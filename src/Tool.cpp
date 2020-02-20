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
  Env* env = Env::instance();

  if (env->game == nullptr){
    std::cout << "No game is set" << '\n';
    return 1;
  }
  Env::instance()->game->print_turn_sketch(input);
  return 0;
}

int Tool::create_print(std::string& input){
  Env* env = Env::instance();

  if (env->game == nullptr){
    std::cout << "No game is set" << '\n';
    return 1;
  }
  if (env->game->opened_turn_sketch == nullptr){
    std::cout << "No TurnSketch is open" << '\n';
    return 1;
  }
  const char* c_input = input.c_str();
  ANode* node = NodeManager::instance()->create_node("Print", c_input);
  if (node != nullptr){
    env->game->opened_turn_sketch->insert_node(node);
  }

  return 0;
}

int Tool::create_turn_sketch_node(std::string& input){
  Env* env = Env::instance();

  if (env->game == nullptr){
    std::cout << "No game is set" << '\n';
    return 1;
  }
  if (env->game->opened_turn_sketch == nullptr){
    std::cout << "No TurnSketch is open" << '\n';
    return 1;
  }
  TurnSketch* ts = env->game->get_turn_sketch(input);
  if (ts != nullptr){
    ANode* node = NodeManager::instance()->create_node("TurnSketchNode", ts);
    if (node != nullptr){
      env->game->opened_turn_sketch->insert_node(node);
    }
  }
  return 0;
}

int Tool::list_node_type(std::string& input){
  std::cout << NodeManager::instance()->list_node_type();
  return 0;
}

int Tool::echo_message(std::string& input){
  std::cout << input << '\n';
  return 0;
}

int Tool::ts_set_begin(std::string& input){
  Env* env = Env::instance();

  env->game->opened_turn_sketch->set_begin(std::stoi(input));

  return 0;
}

int Tool::set_begin(std::string& input){
  Env* env = Env::instance();
  if (env->game->opened_turn_sketch != nullptr){
    ANode* node = NodeManager::instance()->create_node("TurnSketchNode", env->game->opened_turn_sketch);
    if(node != nullptr){
      env->game->set_begin(node);
      return 0;
    }
  }
  return 1;
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
