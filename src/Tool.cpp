#include "Tool.hpp"

int Tool::create_game(std::string& input){
  char cstr[input.size() + 13];
  memcpy(cstr, "game_source/", 12);
	input.copy(&(cstr[12]), input.size() + 1);
	cstr[input.size() + 12] = '\0';

  std::cout << cstr << '\n';

  const int dir_err = mkdir(cstr, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  if (-1 == dir_err)
  {
    printf("Error creating directory!\n");
    exit(1);
  }
  Env::instance()->game = new Game(cstr);
  return 0;
}

int Tool::new_turn_sketch(std::string& input){
  if (Env::instance()->game == nullptr)
    return 1;
  Env::instance()->game->create_turn_sketch(input);
  return 0;
}

int Tool::open_turn_sketch(std::string& input){
  Env::instance()->game->set_openend_turn_sketch(input);
  return 0;
}

int Tool::list_turn_sketch(std::string& input){
  for (Game::TurnSketchMap::iterator it = Env::instance()->game->turn_sketch_map.begin(); it != Env::instance()->game->turn_sketch_map.end(); ++it)
  {
    std::cout << it->second->name << '\n';
  }
  return 0;
}

int Tool::print_turn_sketch(std::string& input){
  Env::instance()->game->print_turn_sketch(input);
  return 0;
}

int Tool::create_print(std::string& input){
  Env* env = Env::instance();

  if (env->game == nullptr){
    std::cout << "No game is set" << '\n';
    return 1;
  }
  const char* c_input = input.c_str();
  env->game->opened_turn_sketch->insert_node(NodeManager::instance()->create_node("print", c_input));

  return 0;
}

int Tool::list_node_type(std::string& input){
  std::cout << NodeManager::instance()->list_node_type() << '\n';
  return 0;
}

int Tool::echo_message(std::string& input){
  std::cout << input << '\n';
  return 0;
}

int Tool::set_begin(std::string& input){
  Env* env = Env::instance();

  env->game->opened_turn_sketch->set_begin(std::stoi(input));

  return 0;
}

int Tool::link_next_node(std::string& input){
  Env* env = Env::instance();
  int one;
  int two;
  std::stringstream ss(input);
  std::string token;

  std::getline(ss, token, ' ');
  one = std::stoi(token);
  std::getline(ss, token, ' ');
  two = std::stoi(token);
  env->game->opened_turn_sketch->link_node(one, two);

  return 0;
}

int Tool::start(std::string& input){
  Env* env = Env::instance();

  env->game->start();

  return 0;
}

int Tool::save_game(std::string& input){
  Env* env = Env::instance();

  env->game->start();

  return 0;
}

Tool::Tool( void ) {
  return;
}

Tool::Tool( Tool const & src ) {
	*this = src;
	return;
}

Tool::~Tool( void ) {
	return;
}

std::ostream &	operator<<( std::ostream & o, Tool const & i ) {
  return o;
}
