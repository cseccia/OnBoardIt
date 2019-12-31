#include "Game.hpp"

Game::Game(char* file_url){
  memcpy(this->folder_url, file_url, strlen(file_url) + 1);
  return;
}

Game::~Game( void ) {
	return;
}

int Game::start(){
  ANode* current_node;

  current_node = this->node_manager.get_begin();
  while (current_node != nullptr) {
    current_node->exec();
    current_node = current_node->get_next();
  }
  return 0;
}

std::ostream &	operator<<( std::ostream & o, Game const & i ) {
  return o;
}
