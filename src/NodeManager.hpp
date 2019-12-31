#ifndef NODE_MANAGER_CLASS_H
# define NODE_MANAGER_CLASS_H

# include <iostream>
# include <unordered_set>
# include <string>
#include <sstream> //for std::stringstream

# include "ANode.hpp"
# include "node/Print.hpp"

typedef std::unordered_multiset<ANode*> NodeSet;


class NodeManager {
	public:
    NodeManager();
    virtual ~NodeManager( void );

    enum class NodeType {
      Print
    };

    ANode* create_node(NodeType id...);
    std::string list_node();
    ANode* get_begin();
    bool set_begin(NodeSet::iterator node_id);
    bool set_begin(int node_id);
    bool link_node(NodeSet::iterator one, NodeSet::iterator two);
    bool link_node(int one, int two);


	private:
    NodeSet::iterator insert_node( ANode* node );
    NodeSet node_list;
    NodeSet::iterator begin;

};
#endif
