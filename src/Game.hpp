#ifndef GAME_CLASS_H
# define GAME_CLASS_H

#include <iostream>
#include <sys/stat.h>

#include "ANode.hpp"
#include "NodeManager.hpp"
#include "TurnSketch.hpp"

class Game{


	public:
		Game( char* file_url);
		virtual ~Game( void );
		bool insert_node( ANode* node );

		typedef std::unordered_map<std::string, TurnSketch*> TurnSketchMap;
		typedef std::unordered_multiset<ANode*> NodeSet;

		char name[128];

		int start();

		int create_turn_sketch(std::string& name);
		ANode* get_begin();
		bool set_begin(ANode* begin);
		void set_openend_turn_sketch(std::string& name);
		void print_turn_sketch(std::string& name);
		TurnSketch* get_turn_sketch(std::string& name);
		TurnSketch* opened_turn_sketch;
		TurnSketchMap turn_sketch_map;

  private:
		char folder_url[128];
		ANode* begin;

};

std::ostream &	operator<<( std::ostream & o, Game const & i );

#endif
