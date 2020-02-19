#include "ANode.hpp"

ANode::ANode( void ) : p_next(0) {
	this->value = nullptr;
	return;
}

std::type_index ANode::get_t_id( void ){
	return typeid(this);
}

ANode::~ANode( void ) {
	return;
}

int ANode::get_int( void ) const {
	return 0;
}

char ANode::get_char( void ) const {
	return 0;
}

bool ANode::get_bool( void ) const {
	return false;
}

float ANode::get_float( void ) const {
	return 0.0f;
}

std::string* ANode::get_str( void ) const {
	return nullptr;
}

void ANode::set_next(ANode* next){
	this->p_next = next;
	return;
}

ANode* ANode::get_next(){
	return this->p_next;
}

std::ostream &	operator<<( std::ostream & o, ANode const & i ) {
	return o;
}
