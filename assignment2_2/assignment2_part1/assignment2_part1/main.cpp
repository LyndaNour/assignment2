

#include<iostream>
#include"singleLinkedList.h"

using namespace std;
int main()
{

	list<int> a_list{};
	if (a_list.empty())
	{
		cout << "The list is empty\n" << endl;
	}
	else
	{
		cout << "The list contains " << a_list.size() << endl;
	}
	int item;
	cout << "Enter item to insert in the list\n ";
	cin >> item;
	a_list.push_front(item);
	a_list.Display();

	cout << "Enter item to insert in the list\n ";
	cin >> item;
	a_list.push_back(item);
	a_list.Display();


	cout << "The list contains " << a_list.size() << " items " << endl;

	cout << "Enter item to search for\ ";
	cin >> item;

	a_list.find(item);

}