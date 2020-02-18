#ifndef ENV_CLASS_H
# define ENV_CLASS_H

#include <iostream>
#include <unordered_map>
#include "Game.hpp"
#include "Tool.hpp"
#include "TurnSketch.hpp"

typedef int (*Func)(std::string&);
typedef std::unordered_map<std::string, Func> script_map;

class Env {

	public:
		Env();
    Env( Env const & src );
		virtual ~Env( void );
		static Env *instance();

    script_map* map_console_func;
		Game* game;

	private:
		static Env *p_instance;
};

std::ostream &	operator<<( std::ostream & o, Env const & i );

#endif
