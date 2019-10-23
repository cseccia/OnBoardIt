#include "Tool.hpp"

int Tool::echo_message(std::string& input){
  std::cout << input << '\n';
  return 0;
}

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
