#ifndef ENV_CLASS_H
# define ENV_CLASS_H

#include <iostream>
#include <unordered_map>
#include "Tool.hpp"

typedef int (*Func)(std::string&);
typedef std::unordered_map<std::string, Func> script_map;

class Env {

	public:
		Env();
    Env( Env const & src );
		virtual ~Env( void );

    script_map* map_console_func;
};

std::ostream &	operator<<( std::ostream & o, Env const & i );

extern Env* g_Env;

#endif
