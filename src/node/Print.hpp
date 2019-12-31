#ifndef PRINT_CLASS_H
# define PRINT_CLASS_H

# include <iostream>
# include <string>
# include "../ANode.hpp"

class Print: public ANode{

	public:
		Print( std::string& input );
		virtual ~Print( void );
		virtual bool exec( void );


	private:
};

#endif
