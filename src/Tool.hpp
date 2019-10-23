#ifndef TOOL_CLASS_H
# define TOOL_CLASS_H

#include <iostream>
#include <sys/stat.h>


class Tool {

	public:
		Tool();
    Tool( Tool const & src );
		virtual ~Tool( void );

		static int echo_message(std::string& input);
    static int create_game(std::string& input);
};

std::ostream &	operator<<( std::ostream & o, Tool const & i );

#endif
