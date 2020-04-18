#ifndef CD_LINKEDLIST_H
#define CD_LINKEDLIST_H
class CDLinkedList;
class DNode
{
	friend class CDLinkedList;
	int data;
	DNode *prev, *next;
};
class CDLinkedList
{
	DNode head;
public:
	CDLinkedList();
	void display();
	int countNodes();
	bool isSorted();
	bool sortedInsert(int val);
	bool sortedRemove(int& val);
	CDLinkedList(const CDLinkedList & orig);
	~CDLinkedList();
	CDLinkedList& operator=(const CDLinkedList& orig);
	bool operator==(const CDLinkedList& orig);
	bool insertAtStart(int val);
	bool insertAtEnd(int val);
	void splitList(CDLinkedList& leftHalf, CDLinkedList& rightHalf);
	bool merge(CDLinkedList& list1, CDLinkedList& list2);
	bool removeLastNode(int& val);
	bool removeSecondLastNode(int& val);
	bool removeKthNode(int k, int& val);
	void combine(CDLinkedList& list1, CDLinkedList& list2);
	bool merge(CDLinkedList& list1, CDLinkedList& list2);
};
#endif // !CD_LINKEDLIST_H
#pragma once
