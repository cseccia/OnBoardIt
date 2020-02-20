#ifndef TURN_SKETCH_NODE_CLASS_H
# define TURN_SKETCH_NODE_CLASS_H

# include <iostream>
# include <string>
# include "../ANode.hpp"
# include "../NodeManager.hpp"
# include "../TurnSketch.hpp"


class TurnSketchNode: public ANode{

	public:
		TurnSketchNode( va_list args );
		virtual ~TurnSketchNode( void );
		virtual bool exec( void );

	private:
    TurnSketch* associated;
};
static const int registeredBarTurnSketch = NodeManager::instance()->Register("TurnSketchNode", nodeBuilder<TurnSketchNode>);


#endif
