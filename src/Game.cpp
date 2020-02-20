#include "Game.hpp"

Game::Game(char* name){
  memcpy(this->name, name, strlen(name) + 1);
  return;
}

Game::~Game( void ) {
	return;
}

int Game::start(){
  ANode* current_node;

  current_node = this->get_begin();
  while (current_node != nullptr) {
    current_node->exec();
    current_node = current_node->get_next();
  }
  return 0;
}

std::ostream &	operator<<( std::ostream & o, Game const & i ) {
  return o;
}

int Game::create_turn_sketch(std::string& name){
  TurnSketch* pts;

  std::string* TSName = new std::string(name);
  pts = new TurnSketch(TSName);
  this->turn_sketch_map.insert(std::make_pair(*TSName, pts));
  std::cout << pts->name << '\n';
  return false;
}

void Game::set_openend_turn_sketch(std::string& name){
  if (this->turn_sketch_map.count(name) > 0)
  {
    this->opened_turn_sketch = this->turn_sketch_map.find(name)->second;
  } else {
    std::cout << "not found" << '\n';
  }
}

void Game::print_turn_sketch(std::string& name){
  TurnSketch* pts;

  if (this->turn_sketch_map.count(name) > 0) {
    pts = this->turn_sketch_map.find(name)->second;
  } else {
    if (this->opened_turn_sketch == nullptr) {
      std::cout << "no TurnSketch is open" << '\n';
      return;
    }
    pts = this->opened_turn_sketch;
  }

  std::cout << pts->list_node();
}

TurnSketch* Game::get_turn_sketch(std::string& name){
  TurnSketch* pts;

  if (this->turn_sketch_map.count(name) > 0) {
    pts = this->turn_sketch_map.find(name)->second;
  } else {
    std::cout << "no TurnSketch finded" << '\n';
    return nullptr;
  }
  return pts;
}

ANode* Game::get_begin(){
  if (this->begin != nullptr){
    return this->begin;
  }
  std::cout << "Start isn't set" << '\n';
  return nullptr;
}

bool Game::set_begin(ANode* node){
  this->begin = node;
  return false;
}
