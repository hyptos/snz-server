#include "controler.hpp"
#include "Server/decoder.h"

//Constructeur
Controler::Controler() 
	: m_model(NULL) {
}

//Destructeur
Controler::~Controler(){
}

//Connection au modèle
void Controler::connect_to_model(SNZ_Model* model){
	m_model = model;
}

void Controler::onOutPutMessage(IMessage* msg){

	if(m_model != NULL){
	    char code = msg->getCode();
	    std::cout << "reçu : " << code << std::endl;
	    if(code == 'u'){
	    	InfoEntity info;
	        std::cout << "Je passe par le case u" << std::endl;
	        decode<InfoEntity>(*(msg->toByteBuffer()), info);

	        //if(info.getType() == EntityType::PLAYER){

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
	        	else{
	        		m_players.push_back(m_model->addEntity(player));
	        		//delete player;
	        	}
	        //}
		}
	}
}
