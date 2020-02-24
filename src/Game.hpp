#ifndef GAME_CLASS_H
# define GAME_CLASS_H

#include <iostream>
#include <sys/stat.h>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "ANode.hpp"
#include "NodeManager.hpp"
#include "TurnSketch.hpp"

class Game{


	public:
		Game( char* file_url, std::string* name );
		virtual ~Game( void );
		bool insert_node( ANode* node );

		typedef std::unordered_map<std::string, TurnSketch*> TurnSketchMap;
		typedef std::unordered_multiset<ANode*> NodeSet;

		std::string name;

		int start();

		int create_turn_sketch(std::string& name);
		ANode* get_begin();
		bool set_begin(ANode* begin);
		void set_openend_turn_sketch(std::string& name);
		void print_turn_sketch(std::string& name);
		TurnSketch* get_turn_sketch(std::string& name);
		int save();
		TurnSketch* opened_turn_sketch;
		TurnSketchMap turn_sketch_map;
		char folder_url[128];

  private:
		ANode* begin;

};

std::ostream &	operator<<( std::ostream & o, Game const & i );

#endif
