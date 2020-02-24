#include "Game.hpp"

Game::Game(char* url, std::string* name_game) {
  memcpy(this->folder_url, url, strlen(url) + 1);
  this->name = *name_game;

  int dir_err = mkdir(this->folder_url, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  if (-1 == dir_err) {
    throw std::string("Error creating directory!");
  }

  char folder_ts[11] = "TurnSketch";
  char folder_root[strlen(this->folder_url) + 13];
  memcpy(folder_root, this->folder_url, strlen(this->folder_url) + 1);
  strcat(folder_root, folder_ts);
  dir_err = mkdir(folder_root, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  if (-1 == dir_err) {
    throw std::string("Error creating directory!");
  }

  char game_file[256];
  memcpy(game_file, this->folder_url, strlen(this->folder_url) + 1);
  strcat(game_file, this->name.c_str());
  strcat(game_file, ".obi\0");
  std::ofstream wf(game_file, std::ios::out | std::ios::binary);
  if(!wf) {
    throw std::string("Error creating file!");
  }

  wf.write(this->name.c_str(), sizeof(this->name));
  wf.write("\0", 1);

  wf.close();
  if(!wf.good()) {
    throw std::string("Error occurred at writing time!");
  }

  std::cout << this->folder_url << '\n';
  std::cout << this->name << '\n';
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

int Game::save(){
  std::cout << "Saving game : " << this->name << '\n';
  return 0;
}
