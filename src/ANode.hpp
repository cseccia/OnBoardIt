#ifndef ANODE_CLASS_H
# define ANODE_CLASS_H

# include <iostream>
# include <string>
# include <typeindex>
# include <typeinfo>
# include <unordered_map>
#include <typeindex>


class ANode {

	public:

		ANode( void );
		virtual ~ANode( void );
		virtual bool exec( void ) = 0;
		virtual int get_int( void ) const;
		virtual char get_char( void ) const;
		virtual bool get_bool( void ) const;
		virtual float get_float( void ) const;
		virtual std::string* get_str( void ) const;
		std::type_index get_t_id( void );


		void set_next(ANode* next);
		ANode* get_next();

	protected:
		ANode *p_next;
    void *value;

};

std::ostream &	operator<<( std::ostream & o, ANode const & i );

#endif
