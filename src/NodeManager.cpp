#include "NodeManager.hpp"

NodeManager::NodeManager( void ){
	return;
}

NodeManager::~NodeManager( void ) {
	return;
}

ANode* NodeManager::get_begin(){
  if (*this->begin != nullptr){
    return *this->begin;
  }
  std::cout << "Start isn't set" << '\n';
  return nullptr;
}

NodeSet::iterator NodeManager::insert_node( ANode* node ){
  return this->node_list.insert(node);
}

std::string NodeManager::list_node(){
  std::string str;
  NodeSet::iterator iNode;
  void* address;
  std::stringstream ss;

  for(iNode = this->node_list.begin(); iNode != this->node_list.end(); ++iNode){
    address = static_cast<void*>(*iNode);
    ss << std::distance(this->node_list.begin(), iNode) << " | " << address << '\n';

  }
  str = ss.str();

  return str;
}

bool NodeManager::set_begin(NodeSet::iterator node_id){
  this->begin = node_id;
  return false;
}

bool NodeManager::set_begin(int node_id){
  return this->set_begin( std::next(this->node_list.begin(), node_id));
}

bool NodeManager::link_node(NodeSet::iterator one, NodeSet::iterator two){
  (*one)->set_next(*two);
  return false;
}

bool NodeManager::link_node(int one, int two){
  return this->link_node(std::next(this->node_list.begin(), one), std::next(this->node_list.begin(), two));
}

ANode* NodeManager::create_node(NodeType id...){
  ANode* node;
  va_list args;

  va_start(args, id);

  switch ( id )
  {
    case NodeType::Print:
      std::string str = std::string(va_arg(args, char*));
      node = new Print(str);
      break;
  }
  va_end(args);
  this->insert_node(node);
  return node;
}
