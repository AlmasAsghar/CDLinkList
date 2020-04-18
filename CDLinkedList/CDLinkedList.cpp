#include"CDLinkedList.h"
#include<iostream>
using namespace std;
CDLinkedList::CDLinkedList()
{
	head.next = &head;
	head.prev = &head;
}
void CDLinkedList::display()
{
	DNode *curr = head.next;
	while (curr != &head)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
}
int CDLinkedList::countNodes()
{
	int count = 0;
	DNode *curr = head.next;
	while (curr != &head)
	{
		count++;
		curr = curr->next;
	}
	return count;
}
bool CDLinkedList::isSorted()
{	
	DNode * curr = head.next;
	DNode * prev = &head;
	if (curr == &head)
	{
		return false;
	}
	else
	{
		while (curr != &head)
		{
			if (curr->data > prev->data)
			{
				prev = curr;
				curr = curr->next;
			}
			else
				return false;
		}
		return true;
	}
	/*DNode *curr = head.next;
	while (curr != &head)
	{
		DNode * c = head.next;
		while (c != curr)
		{
			if (c->data > curr->data)
				return false;
			c = c->next;
		}
		curr = curr->next;
	}
	return true;*/
}
bool CDLinkedList::sortedInsert(int val)
{
	DNode * temp = new DNode;
	temp->data = val;
	DNode* curr = head.next;
	while (curr != &head && curr->data < val)
	{
		curr = curr->next;
	}
	temp->next = curr;
	temp->prev = curr->prev;
	curr->prev->next = temp;
	curr->prev = temp;
	return true;
}
bool CDLinkedList::sortedRemove(int& val)
{
	DNode* curr = head.next;
	while (curr != &head && curr->data < val)
	{
		curr = curr->next;
	}
	if (curr != &head && curr->data == val)
	{
		curr->prev->next = curr->next;
		curr->next->prev= curr->prev;
		delete curr;
		curr = nullptr;
		return true;
	}
	return false;
}
CDLinkedList::CDLinkedList(const CDLinkedList & orig)
{
	DNode * p1 = orig.head.next;
	DNode * p2 = &head;
	while (p1 != &orig.head)
	{
		p2->next = new DNode;
		p1->next->prev = p2;
		p2 = p2->next;
		p2->data = p1->data;
		p1 = p1->next;
	}
	p2->next = &head;
	head.prev = p2;
}
CDLinkedList::~CDLinkedList()
{
	DNode * p1 = head.next;
	DNode * p2 = nullptr;
	while (p1 != &head)
	{
		p2 = p1->next;
		delete p1;
		p1 = p2;
	}
	head.next = &head;
	head.prev = &head;
}
CDLinkedList& CDLinkedList::operator=(const CDLinkedList& orig)
{
	if (&orig.head == &head)
		return *this;
	else
	{
		this->~CDLinkedList();
		if (orig.head.next == &orig.head)
			return *this;
		else
		{
			DNode * p1 = orig.head.next;
			DNode * p2 = &head;
			while (p1 != &orig.head)
			{
				p2->next = new DNode;
				p1->next->prev = p2;
				p2 = p2->next;
				p2->data = p1->data;
				p1 = p1->next;
			}
			p2->next = &head;
			head.prev = p2;
			return *this;
		}
	}
}
bool CDLinkedList::operator==(const CDLinkedList& orig)
{
	DNode * p1 = orig.head.next;
	DNode * p2 = head.next;
	while (p1 != &orig.head && p2 != &head && p1->data == p2->data)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1 == &orig.head && p2 != &head)
		return false;
	else if (p1 != &orig.head && p2 == &head)
		return false;
	else if (p1->data != p2->data)
		return false;
	return true;
}
bool CDLinkedList::insertAtStart(int val)
{
	DNode * temp = new DNode;
	temp->data = val;
	temp->next = head.next;
	temp->prev = &head;
	head.next->prev= temp;
	head.next = temp;
	return true;
}
bool CDLinkedList::insertAtEnd(int val)
{
	DNode * temp = new DNode;
	temp->data = val;
	temp->next = &head;
	temp->prev = head.prev;
	head.prev->next = temp;
	head.prev = temp;
	return true;
}
void CDLinkedList::splitList(CDLinkedList& leftHalf, CDLinkedList& rightHalf)
{
	int count = countNodes();
	int c = (count % 2 == 0) ? count / 2 : (count / 2) + 1;
	leftHalf.head.next= head.next;
	DNode * curr = head.next;
	count = count - c;
	c--;
	while (c > 0)
	{
		curr = curr->next;
		c--;
	}
	rightHalf.head.next = curr->next;
	leftHalf.head.prev = curr;
	curr->next = &head;
	count--;
	while(count>0)
	{
		count--;
		curr = curr->next;
	}
	curr->next =&rightHalf.head;
	rightHalf.head.prev = curr;
	head.next=&head;
	head.prev = &head;
}
//bool CDLinkedList::merge(CDLinkedList& list1, CDLinkedList& list2)
//{
//	if (!list2.isSorted() || !list1.isSorted())
//		return false;
//	else
//	{
//		DNode * curr = head.next;
//		DNode *t1 = list1.head.next;
//		DNode * t2 = list2.head.next;
//		while (t1 != &list1.head && t2 != &list2.head)
//		{
//			if (t1->data > t2->data)
//			{
//				t2->prev = curr;
//				curr = t2;
//				curr = curr->next;
//				t2 = t2->next;
//			}
//			else if (t1->data < t2->data)
//			{
//				t1->prev = curr;
//				curr = t1;
//				curr = curr->next;
//				t1 = t1->next;
//			}
//			else
//			{
//				t1->prev = curr;
//				curr= t1;
//				t1 = t1->next;
//				curr = curr->next;
//				t2->prev = curr;
//				curr = t2;
//				t2 = t2->next;
//			}
//		}
//		if (t1 == &list1.head)
//		{
//			curr->prev = t1->prev;
//			curr->prev->next = curr;
//		}
//		else if (t2 == &list2.head)
//		{
//			curr->prev = t2->prev;
//			curr->prev->next = curr;
//		}
//		list1.head.next = &list1.head;
//		list1.head.prev = &list1.head;
//		list2.head.next = &list2.head;
//		list2.head.prev = &list2.head;
//		return true;
//	}
//}
bool CDLinkedList::removeLastNode(int& val)
{
	if (head.prev != &head)
	{
		DNode * t=head.prev;
		head.prev = t->prev;
		head.prev->next = &head;
		val = t->data;
		delete t;
		return true;
	}
	return false;
}
bool CDLinkedList::removeSecondLastNode(int& val)
{
	if (head.next == &head || head.next->next == &head)
		return false;
	else
	{
		DNode * t = head.prev->prev;
		head.prev->prev= t->prev;
		t->prev->next = head.prev;
		val = t->data;
		delete t;
		return true;
	}
}
bool CDLinkedList::removeKthNode(int k, int& val)
{
	int count = countNodes();
	if (k >0  && k <= count)
	{
		DNode * curr = head.next;
		for (int i = 0; i < k; i++)
			curr = curr->next;
		val = curr->data;
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		delete curr;
		return true;
	}
	return false;
}
void CDLinkedList::combine(CDLinkedList& list1, CDLinkedList& list2)
{
	head.next = list1.head.next;
	list1.head.prev->next = list2.head.next;
	list2.head.prev = &head;
	list1.head.next = &list1.head;
	list1.head.prev = &list1.head;
	list2.head.next = &list2.head;
	list2.head.prev = &list2.head;
}
bool merge(CDLinkedList& list1, CDLinkedList& list2)
{

}