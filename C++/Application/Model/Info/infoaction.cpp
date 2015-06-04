#include "infoaction.hpp"

//Constructeur
InfoAction::InfoAction(const ActionType& action, const unsigned long long& entity, const unsigned long long& cible)
	: m_action(action), m_entity(entity), m_cible(cible) {
}

//Destructeur
InfoAction::~InfoAction(){}

//Retourne l'action effectué par l'entité
ActionType InfoAction::getAction() const {
	return m_action;
}

//Retourne l'entité faisant l'action
unsigned long long InfoAction::getEntity() const {
	return m_entity;
}

//Retourne l'entité ciblé par l'action
unsigned long long InfoAction::getCible() const {
	return m_cible;
}
