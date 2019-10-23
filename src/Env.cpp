#include "Env.hpp"

Env::Env( void ) {
  map_console_func = new script_map();
  map_console_func->insert(std::make_pair(std::string("echo"), &Tool::echo_message));
  map_console_func->insert(std::make_pair(std::string("new-game"), &Tool::create_game));
  return;
}

Env::Env( Env const & src ) {
	*this = src;
	return;
}

Env::~Env( void ) {
	return;
}

std::ostream &	operator<<( std::ostream & o, Env const & i ) {
  return o;
}
