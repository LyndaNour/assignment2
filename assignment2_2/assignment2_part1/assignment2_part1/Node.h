#ifndef NODE_H_
#define NODE_H_

template<typename Item_Type>
struct Node {

public:

	Item_Type data; // the data field contained in the node 
	Node<Item_Type>* next;  // pointer to the next node 
};




#endif



