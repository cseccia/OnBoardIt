#include "Print.hpp"

Print::Print( std::string& input ) {
  this->p_next = nullptr;
  std::string* str = new std::string(input);
  this->value = static_cast<void*>(str);
  return;
}

Print::~Print( void ) {
	return;
}

bool Print::exec( void ) {
  std::string &s = *(static_cast<std::string*>(this->value));
  std::cout << s << '\n';
  return false;
}
