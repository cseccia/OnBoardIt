#ifndef PRINT_CLASS_H
# define PRINT_CLASS_H

# include <iostream>
# include <string>
# include "../ANode.hpp"
# include "../NodeManager.hpp"


class Print: public ANode{

	public:
		Print( va_list args );
		virtual ~Print( void );
		virtual bool exec( void );

	private:
};
static const int registeredBar = NodeManager::instance()->Register("Print", nodeBuilder<Print>);


#endif
