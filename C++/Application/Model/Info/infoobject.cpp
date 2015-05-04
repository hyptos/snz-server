#include "infoobject.hpp"

//Constructeur par défaut
InfoObject::InfoObject() : InfoEntity() {
	m_type = EntityType::OBJECT;
}

//Constructeur avec paramètres
InfoObject::InfoObject(unsigned long long id, ObjectType otype, double x, double z, double y, double dx, double dz, double dy) 
	: InfoEntity(id, EntityType::OBJECT, x, z, y, dx, dz, dy), m_otype(otype) {
}

//Constructeur par copie
InfoObject::InfoObject(const InfoObject& info) 
	: InfoEntity(info.getEntity(), info.getType(), info.getX(), info.getZ(), info.getY(), info.getDX(), info.getDZ(), info.getDY()), m_otype(info.getObjectType()){
}

//Destructeur
virtual InfoObject::~InfoObject(){
}

//Retourne le type de l'object
ObjectType InfoObject::getObjectType() const{
	return m_otype;
}

//Modifie le type de l'objet
void InfoObject::setObjectType(ObjectType otype){
	m_otype = otype;
}
