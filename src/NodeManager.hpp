#ifndef NODE_MANAGER_CLASS_H
# define NODE_MANAGER_CLASS_H

# include <iostream>
# include <unordered_set>
# include <string>
# include <sstream> //for std::stringstream
# include <unordered_map>

# include "ANode.hpp"
# include "node/Print.hpp"

typedef ANode* (*create_node_func)(va_list);

typedef std::unordered_map<std::string, create_node_func> create_node_map;


class NodeManager {
	public:
    NodeManager();
    virtual ~NodeManager( void );

		ANode* create_node(std::string NodeType...);
    static ANode* create_print(va_list args);
    bool link_node(ANode* one, ANode* two);

	private:
		create_node_map* map_create_node_func;

};
#endif
