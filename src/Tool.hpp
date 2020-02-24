#ifndef TOOL_CLASS_H
# define TOOL_CLASS_H

#include <iostream>
#include <sys/stat.h>
#include "Game.hpp"
#include "Env.hpp"
#include "ANode.hpp"

class Tool {

	public:
		Tool();
    Tool( Tool const & src );
		virtual ~Tool( void );

		static int echo_message(std::string& input);
		static int create_game(std::string& input);
		static int create_print(std::string& input);
    static int create_turn_sketch_node(std::string& input);
		static int set_begin(std::string& input);
		static int ts_set_begin(std::string& input);
		static int link_next_node(std::string& input);
		static int start(std::string& input);
		static int save_game(std::string& input);
		static int save_all(std::string& input);
		static int save_turn_sketch(std::string& input);
		static int new_turn_sketch(std::string& input);
		static int open_turn_sketch(std::string& input);
		static int print_turn_sketch(std::string& input);
		static int list_turn_sketch(std::string& input);
		static int list_node_type(std::string& input);

};

std::ostream &	operator<<( std::ostream & o, Tool const & i );

#endif
