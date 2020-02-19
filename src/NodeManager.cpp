#include "NodeManager.hpp"

NodeManager *NodeManager::p_instance = 0;

NodeManager *NodeManager::instance() { /* singleton */
	if (!NodeManager::p_instance) NodeManager::p_instance = new NodeManager();
	return NodeManager::p_instance;
}

NodeManager::NodeManager( void ){
	return;
}

NodeManager::~NodeManager( void ) {
	return;
}

bool NodeManager::link_node(ANode* one, ANode* two){
  one->set_next(two);
  return false;
}

ANode* NodeManager::create_node(const std::string NodeType...){
  ANode* node;
  va_list args;

  va_start(args, NodeType);

	node = Build(NodeType, args);

  va_end(args);
  return node;
}

int NodeManager::Register(std::string const& key, Builder const& builder) {
	return node_builder_map.insert(std::make_pair(key, builder)).second;
}

ANode* NodeManager::Build(std::string const& key, va_list args) const {
	auto it = node_builder_map.find(key);
	if (it == node_builder_map.end()) { return 0; } // no such key
	return (it->second)(args);
}

std::string NodeManager::list_node_type() const {
	std::string str = "List of sub classes\n";
	for (auto it = node_builder_map.begin(); it != node_builder_map.end(); ++it)
	{
		str += it->first;
	}
	return str;
}
