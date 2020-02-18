#include "NodeManager.hpp"

NodeManager::NodeManager( void ){
	map_create_node_func = new create_node_map();
	map_create_node_func->insert(std::make_pair(std::string("print"), &NodeManager::create_print));
	return;
}

NodeManager::~NodeManager( void ) {
	return;
}

bool NodeManager::link_node(ANode* one, ANode* two){
  one->set_next(two);
  return false;
}

ANode* NodeManager::create_node(std::string NodeType...){
  ANode* node;
  va_list args;

  va_start(args, NodeType);

  node = map_create_node_func->find(NodeType)->second(args);

  va_end(args);
  return node;
}

ANode* NodeManager::create_print(va_list args){
	ANode* node;

	std::string str = std::string(va_arg(args, char*));
	node = new Print(str);
	std::cout << str << '\n';

	return node;
}
