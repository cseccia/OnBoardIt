#include "TurnSketchNode.hpp"

TurnSketchNode::TurnSketchNode( va_list args ) {
  this->p_next = nullptr;
  this->associated = va_arg(args, TurnSketch*);

  return;
}

TurnSketchNode::~TurnSketchNode( void ) {
	return;
}

bool TurnSketchNode::exec( void ) {

  ANode* current_node;

  current_node = this->associated->get_begin();
  while (current_node != nullptr) {
    current_node->exec();
    current_node = current_node->get_next();
  }
  return false;
}
