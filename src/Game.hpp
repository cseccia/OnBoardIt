#ifndef GAME_CLASS_H
# define GAME_CLASS_H

#include <iostream>
#include <sys/stat.h>

#include "ANode.hpp"
#include "NodeManager.hpp"

class Game{

	public:
		Game( char* file_url);
		virtual ~Game( void );
		bool insert_node( ANode* node );

		int start();
		NodeManager node_manager;

  private:
    char folder_url[128];
};

std::ostream &	operator<<( std::ostream & o, Game const & i );

#endif
