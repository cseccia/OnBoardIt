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
  std::cout << "JE SUIS UN TURN SKETCH NODE" << '\n';
  return false;
}
