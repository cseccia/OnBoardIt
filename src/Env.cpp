#include "Env.hpp"

int echo_message(std::string& input){
  std::cout << input << '\n';
  return 0;
}

Env::Env( void ) {
  map_console_func = new script_map();
  map_console_func->insert(std::make_pair(std::string("echo"), &echo_message));
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
