#include"CDLinkedList.h"
#include<iostream>
using namespace std;
int main()
{
	CDLinkedList cdll,ll,l2;
	cdll.sortedInsert(1);
	cdll.sortedInsert(8);
	//cdll.sortedInsert(0);
	//ll = cdll;
//	l2.merge(cdll, ll);
	//l2.display();
	/*cdll.splitList(ll, l2);
	ll.display();*/
//    l2.display();
	//cout << cdll.countNodes();
	//cdll.display();
//	ll.sortedInsert(11);
//	ll.sortedInsert(8);
	ll = cdll;
	//ll.insertAtStart(3);
//	ll.insertAtEnd(6);
//	cdll.display();
	//cout << ll.operator==(cdll);
	int v;
	cdll.removeLastNode(v);
	//cdll.removeSecondLastNode(v);
	//cdll.removeKthNode(1, v);
	//cdll.display();
	cout << v;
	//l2.combine(cdll, ll);
	//l2.display();
	system("pause");
}