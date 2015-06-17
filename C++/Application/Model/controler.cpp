#include "controler.hpp"
#include "Server/decoder.h"

//Constructeur
Controler::Controler() 
	: m_model(NULL), m_server(NULL) {
}

//Destructeur
Controler::~Controler(){
}

//Connection au modèle
void Controler::connect_to_model(SNZ_Model* model){
	m_model = model;
}

//Connection au server
void Controler::connect_to_server(ICommunicationServer* server){
	m_server = server;
}

void Controler::onOutPutMessage(QUuid client, IMessage* msg){

	if(m_model != NULL){
	    char code = msg->getCode();
	    std::cout << "reçu : " << code << std::endl;
	    if(code == 'u'){
	    	InfoEntity info;
	        std::cout << "Je passe par le case u" << std::endl;
	        decode<InfoEntity>(*(msg->toByteBuffer()), info);

        	InfoPlayer *player = new InfoPlayer(info);

        	int known = false;

        	for(std::vector<unsigned long long>::iterator it = m_players.begin() 
        			; it != m_players.end() && !known ; it++ ){
        		if(*it == info.getEntity())
        			known = true;
        	}

        	if(known){
        		if(info.getEntity() < m_model->getNbEntities())
        			m_model->notifyEntity(player);
        	}
        	else
        		std::cout << "Error : player id " 
        			<< info.getEntity() << " unknown" << std::endl;
		}
		else if(code == 'c'){
			std::cout << "Connection !" << std::endl;
			InfoEntity info;
	        decode<InfoEntity>(*(msg->toByteBuffer()), info);

	        InfoPlayer *player = new InfoPlayer(info);

        	int known = false;

        	for(std::vector<unsigned long long>::iterator it = m_players.begin() 
        			; it != m_players.end() && !known ; it++ ){
        		if(*it == info.getEntity())
        			known = true;
        	}

        	if(known)
        		std::cout << "Error : player id " 
	        			<< info.getEntity() << " already known" << std::endl;
	       	else{
	       		unsigned long long id = m_model->addEntity(player);
	       		m_players.push_back(id);
	       		// TODO : Envoyer son id au client
	       	}
		}
		else if(code == 'd'){
			std::cout << "Deconnection !" << std::endl;
			InfoEntity info;
	        decode<InfoEntity>(*(msg->toByteBuffer()), info);

	        InfoPlayer *player = new InfoPlayer(info);

        	int known = false;

        	for(std::vector<unsigned long long>::iterator it = m_players.begin() 
        			; it != m_players.end() && !known ; it++ ){
        		if(*it == info.getEntity())
        			known = true;
        	}

        	if(known){
        		if(info.getEntity() < m_model->getNbEntities())
        			m_model->removeEntity(info.getEntity());
        	}
        	else
        		std::cout << "Error : player id " 
        			<< info.getEntity() << " unknown" << std::endl;
		}
		else if(code == 'w'){
            std::cout << "Je passe par le case w" << std::endl;
            StringMessage res;
            decode<StringMessage>(*(msg->toByteBuffer()), res);
            char * str = res.getStr();
            std::cout<< "recu : ";
            for(int i = 0; i < res.getLen(); i++) {
                std::cout<< str[i];
            }
            int nb_client;
            if(m_server != NULL)
            	nb_client = m_server->sendBroadCast(&res);
            
            std::cout<< "  message envoyé à "<< nb_client <<"\n";
        }
        else
            std::cout<<"Error code : " << code << " unknown" << std::endl;
	}
}
