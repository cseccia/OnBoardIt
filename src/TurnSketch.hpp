#ifndef TURN_SKETCH_CLASS_H
# define TURN_SKETCH_CLASS_H

# include <iostream>
# include <string>
# include <sstream> //for std::stringstream
# include "ANode.hpp"
# include "node/Print.hpp"
# include "NodeManager.hpp"
# include <unordered_map>
# include <unordered_set>

typedef std::unordered_multiset<ANode*> NodeSet;

typedef ANode* (*create_node_func)(va_list);

class TurnSketch {
	public:
    TurnSketch(std::string* name);
    virtual ~TurnSketch( void );
    std::string name;

    std::string list_node();
    ANode* get_begin();
    bool set_begin(NodeSet::iterator node_id);
    bool set_begin(int node_id);
    bool link_node(NodeSet::iterator one, NodeSet::iterator two);
    bool link_node(int one, int two);
    NodeSet::iterator insert_node( ANode* node );
		int save(std::string* name);

	private:
    NodeSet node_list;
    NodeSet::iterator begin;

};
#endif
