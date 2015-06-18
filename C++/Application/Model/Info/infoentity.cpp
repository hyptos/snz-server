#include "infoentity.hpp"

#define MSG_WOPAWOPA 'w'
#define MSG_WOPAINFO 'u'

//Constructeur par défaut
InfoEntity::InfoEntity(){
}

//Constructeur avec params
InfoEntity::InfoEntity(unsigned long long entity, EntityType type, double x, double z, double y, double dx, double dz, double dy)
    : m_entity(entity), m_type(type), m_x(x), m_z(z), m_y(y), m_dx(dx), m_dz(dz), m_dy(dy){
}

InfoEntity::InfoEntity(const InfoEntity& info)
    : m_entity(info.getEntity()), m_type(info.getType()), m_x(info.getX()), m_z(info.getZ()), m_y(info.getY()), m_dx(info.getDX()), m_dz(info.getDZ()), m_dy(info.getDY()){
}

//Destructeur
InfoEntity::~InfoEntity(){
}

//Retourne l'id de l'entité
unsigned long long InfoEntity::getEntity() const {
    return m_entity;
}

//Retourne le type de l'entité
EntityType InfoEntity::getType() const {
    return m_type;
}

//Retourne la coordonnée X de l'entité dans l'environnement
double InfoEntity::getX() const {
    return m_x;
}

//Retourne la coordonnée Z de l'entité dans l'environnement
double InfoEntity::getZ() const {
    return m_z;
}

//Retourne la coordonnée Y de l'entité dans l'environnement
double InfoEntity::getY() const {
    return m_y;
}

//Retourne la coordonnée X du vecteur direction de l'entité
double InfoEntity::getDX() const {
    return m_dx;
}

//Retourne la coordonnée Z du vecteur direction de l'entité
double InfoEntity::getDZ() const {
    return m_dz;
}

//Retourne la coordonnée Y du vecteur direction de l'entité
double InfoEntity::getDY() const {
    return m_dy;
}

//Modifie l'ID de l'entité
void InfoEntity::setEntity(unsigned long long entity){
    m_entity = entity;
}

//Modifie le Type de l'entité
void InfoEntity::setType(EntityType type){
    m_type = type;
}

//Modifie la coordonnée X
void InfoEntity::setX(double x){
    m_x = x;
}

//Modifie la coordonnée Z
void InfoEntity::setZ(double z){
    m_z = z;
}

//Modifie la coordonnée Y
void InfoEntity::setY(double y){
    m_y = y;
}

//Modifie la coordonnée DX
void InfoEntity::setDX(double dx){
    m_dx = dx;
}

//Modifie la coordonnée DZ
void InfoEntity::setDZ(double dz){
    m_dz = dz;
}

//Modifie la coordonnée DY
void InfoEntity::setDY(double dy){
    m_dy = dy;
}

// affichage
void InfoEntity::affiche(){
    std::cout << " affichage de l'entite " << std::endl;
    std::cout << "m_id:" << this->getEntity() << std::endl;
    std::cout << "m_type:" << this->getType() << std::endl;
    std::cout << "m_x:" << this->getX() << std::endl;
    std::cout << "m_z:" << this->getZ() << std::endl;
    std::cout << "m_y:" << this->getY() << std::endl;
    std::cout << "m_dx:" << this->getDX() << std::endl;
    std::cout << "m_dz:" << this->getDZ() << std::endl;
    std::cout << "m_dy:" << this->getDY() << std::endl;
}


//
char InfoEntity::getCode() {
    return MSG_WOPAINFO;
}

//Coder
ByteBuffer* InfoEntity::toByteBuffer() {
    //Ordre d'encodage de l'infoEntity dans le ByteBuffer
    ByteBuffer *res = new ByteBuffer();
    res->append(toBuffer<char>(MSG_WOPAINFO));
    res->append(toBuffer<unsigned long long>(this->getEntity()));
    res->append(toBuffer<int>(this->getType()));
    res->append(toBuffer<double>(this->getX()));
    res->append(toBuffer<double>(this->getZ()));
    res->append(toBuffer<double>(this->getY()));
    res->append(toBuffer<double>(this->getDX()));
    res->append(toBuffer<double>(this->getDZ()));
    res->append(toBuffer<double>(this->getDY()));
    return res;
}
