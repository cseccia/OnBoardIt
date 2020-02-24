#include "TurnSketch.hpp"

TurnSketch::TurnSketch( std::string* input ){
  this->name = *input;
	return;
}

TurnSketch::~TurnSketch( void ) {
	return;
}

ANode* TurnSketch::get_begin(){
  if (*this->begin != nullptr){
    return *this->begin;
  }
  std::cout << "Start isn't set" << '\n';
  return nullptr;
}

NodeSet::iterator TurnSketch::insert_node( ANode* node ){
  return this->node_list.insert(node);
}

std::string TurnSketch::list_node(){
  std::string str;
  NodeSet::iterator iNode;
  void* address;
  std::stringstream ss;

  ss << "Turn Sketch : " << this->name << '\n';

  for(iNode = this->node_list.begin(); iNode != this->node_list.end(); ++iNode){
    address = static_cast<void*>(*iNode);
    ss << std::distance(this->node_list.begin(), iNode) << " | " << address << '\n';

  }
  str = ss.str();

  return str;
}

bool TurnSketch::set_begin(NodeSet::iterator node_id){
  this->begin = node_id;
  return false;
}

bool TurnSketch::set_begin(int node_id){
  return this->set_begin( std::next(this->node_list.begin(), node_id));
}

bool TurnSketch::link_node(NodeSet::iterator one, NodeSet::iterator two){
  NodeManager::instance()->link_node((*one),(*two));
  return false;
}

bool TurnSketch::link_node(int one, int two){
  return this->link_node(std::next(this->node_list.begin(), one), std::next(this->node_list.begin(), two));
}

int TurnSketch::save(std::string* folder_url){
  std::cout << "Saving turn sketch : " << this->name << '\n';

  std::string file_url;
  file_url = *folder_url + this->name + ".tsk";
  std::cout << file_url << std::endl;


  return 0;
}
