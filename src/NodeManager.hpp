#ifndef NODE_MANAGER_CLASS_H
# define NODE_MANAGER_CLASS_H

# include <iostream>
# include <unordered_set>
# include <string>
# include <sstream> //for std::stringstream
# include <unordered_map>

# include "ANode.hpp"

class NodeManager {
	public:
    NodeManager();
    virtual ~NodeManager( void );

		static NodeManager *instance();

		typedef std::function<ANode*(va_list)> Builder;
		typedef std::unordered_map<std::string, Builder> BuilderMap;

	  int Register(std::string const& key, Builder const& builder);
	  ANode* Build(std::string const& key, va_list args) const;
		std::string list_node_type() const;

		ANode* create_node(const std::string NodeType...);
    static ANode* create_print(va_list args);
    bool link_node(ANode* one, ANode* two);

	private:
		static NodeManager *p_instance;
		BuilderMap node_builder_map;

};

template <typename T>
	ANode* nodeBuilder(va_list args) { return new T(args); }

#endif
