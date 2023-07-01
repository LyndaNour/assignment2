#ifndef SINGLE_LINKED_LIST_
#define SINGLE_LINKED_LIST_

#include<iostream>
#include <stdexcept>

template<typename Item_Type>
class list {
#include "Node.h"   


private:
	Node<Item_Type>* head;  // a pointer to the first item in the list
	Node<Item_Type>* tail;	  // a pointer to the last item in the list 

	int num_items; // a count of the number of items in the list 

public:
	void push_front(const Item_Type& item);// push front
	void push_back(const Item_Type& item);	// push back
	void pop_front();	// pop front
	void pop_back();	// pop back
	Item_Type& front();
	Item_Type& back();
	bool empty()const;	// empty 
	void insert(size_t index, const Item_Type& item);
	bool remove(size_t index);
	size_t find(const Item_Type& item);

	void Display();
	int size() const;
};

/** add an element to the head of the list */

template<typename Item_Type>
void list<Item_Type>::push_front(const Item_Type& item)
{

	Node<Item_Type>* newNode = new Node<Item_Type>;
	newNode->data = item;

	if (empty())
	{
		head = newNode;
		tail = newNode;
		newNode->next = NULL;
	}
	else
	{
		head->next = head;
		head = newNode;
	}
	num_items++;

}

/** add an element to the end of the list */
template<typename Item_Type>
void list<Item_Type>::push_back(const Item_Type& item)
{

	Node<Item_Type>* newNode = new Node<Item_Type>;
	newNode->data = item;

	if (empty())
	{
		head = newNode;
		tail = newNode;
	}

	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	num_items++;
}


// remove a front item 
template<typename Item_Type>
void list<Item_Type>::pop_front()
{
	if (empty())
	{
		throw std::invalid_argument("Attempt to call pop_front() on an empty list");

	}

	else
	{
		Node<Item_Type>* temp = head;
		head = head->next;
		delete temp;
		num_items--;
	}
}

// remove a back element 
template<typename Item_Type>
void list<Item_Type>::pop_back()
{

	if (empty())
	{
		throw std::invalid_argument("Attempt to call pop_back() on an empty list");
	}
	else
	{
		Node<Item_Type>* current = head;
		Node<Item_Type>* secondLastNode = NULL;

		while (current->next != NULL)
		{
			secondLastNode = current;
			current = current->next;
		}
		delete secondLastNode->next;
		tail = secondLastNode;
		num_items--;

	}

}

template<typename Item_Type>

Item_Type& list<Item_Type>::front()
{

	if (empty())
	{
		throw std::invalid_argument(__func__, "list is empty");
	}
	else
	{
		return (head->data);
	}
}

template<typename Item_Type>
Item_Type& list<Item_Type>::back()
{

	if (empty())
	{
		throw std::invalid_argument(__func__, "list is empty");
	}
	else
	{
		return tail->data;
	}
}


template<typename Item_Type>
bool list<Item_Type>::empty() const
{
	return(num_items==0);
}


template<typename Item_Type>
void list<Item_Type>::insert(size_t index, const Item_Type& item)
{
	Node<Item_Type>* newNode = new Node<Item_Type>;
	newNode->data = item;

	if (index == 0)
	{
		push_front(item);
	}
	else if (index == num_items-1)
	{
		push_back(item);
	}
	else if (index<0 || index>num_items)
	{
		throw std::invalid_argument("index is invalid! ");
	}

	else
	{
		Node<Item_Type>* ptrCurrent = head;
		Node<Item_Type>* secondLastNode = NULL;

		for (int counter = 0; counter < index; counter++)
		{
			secondLastNode = ptrCurrent;
			ptrCurrent = ptrCurrent->next;
		}

		newNode->next = secondLastNode->next;
		secondLastNode->next = newNode;

	}

}

template<typename Item_Type>
bool list<Item_Type>::remove(size_t index)
{

	if (index<0 || index>num_items) //invalid index 
	{
		return false;
	}
	else if (empty()) // empty list
	{
		throw std::invalid_argument("cannot remove from empty list");
		return false;
	}
	else if (index == 0)   // remove the first item from the list 
	{
		pop_front();
		return true;
	}
	else if (index == num_items-1)  //remove the last item from the list
	{
		pop_back();
		return true;
	}
	else  // remove an item at index 
	{
		Node<Item_Type> * ptrCurrent = head;
		Node<Item_Type>* secondLastNode = NULL;

		for (int counter = 0; counter < index; counter++)
		{
			secondLastNode = ptrCurrent;
			ptrCurrent = ptrCurrent->next;
		}

		secondLastNode->next = ptrCurrent->next;
		delete ptrCurrent;
		num_items--;
		return true;
	}

}


template<typename Item_Type>
size_t list<Item_Type>::find(const Item_Type& item)
{

	Node<Item_Type> * ptrCurrent = head;
	for (int counter = 0; counter < num_items; counter++)
	{
		ptrCurrent = ptrCurrent->next;
		if (ptrCurrent->data == item)
		{
			return counter + 1;
		}
		else
		{
			return (num_items);
		}

	}
}



template <typename Item_Type>
void list<Item_Type>::Display()
{
	Node<Item_Type>* temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}


template<typename Item_Type>
int list<Item_Type>::size() const
{
	int counter=0;
	Node<Item_Type>* temp = head;
	while (temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return counter;
}







#endif 
