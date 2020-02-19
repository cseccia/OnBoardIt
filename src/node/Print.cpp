#include "Print.hpp"

Print::Print( va_list args ) {
  this->p_next = nullptr;
  std::string* str = new std::string(va_arg(args, char*));
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
