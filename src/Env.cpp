#include "Env.hpp"

Env *Env::p_instance = 0;

Env::Env( void ) {
  map_console_func = new script_map();
  map_console_func->insert(std::make_pair(std::string("echo"), &Tool::echo_message));
  map_console_func->insert(std::make_pair(std::string("new_game"), &Tool::create_game));
  map_console_func->insert(std::make_pair(std::string("create_print"), &Tool::create_print));
  map_console_func->insert(std::make_pair(std::string("set_begin"), &Tool::set_begin));
  map_console_func->insert(std::make_pair(std::string("start"), &Tool::start));
  map_console_func->insert(std::make_pair(std::string("link_node"), &Tool::link_next_node));
  map_console_func->insert(std::make_pair(std::string("save_game"), &Tool::save_game));
  map_console_func->insert(std::make_pair(std::string("create_turn_sketch"), &Tool::new_turn_sketch));
  map_console_func->insert(std::make_pair(std::string("list_turn_sketch"), &Tool::list_turn_sketch));
  map_console_func->insert(std::make_pair(std::string("open_turn_sketch"), &Tool::open_turn_sketch));
  map_console_func->insert(std::make_pair(std::string("print_turn_sketch"), &Tool::print_turn_sketch));
  map_console_func->insert(std::make_pair(std::string("list_node_type"), &Tool::list_node_type));
  this->game = nullptr;
  return;
}

Env::Env( Env const & src ) {
	*this = src;
	return;
}

Env::~Env( void ) {
	return;
}

Env *Env::instance() { /* singleton */
	if (!Env::p_instance) Env::p_instance = new Env();
	return Env::p_instance;
}

std::ostream &	operator<<( std::ostream & o, Env const & i ) {
  return o;
}
