#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Zhuravleva
{
	class Linked_List
	{
		struct Node
		{
			Language *language;
			Node *next;
			Node *prev;
		};
	public:
		Linked_List();
		~Linked_List();
		void Linked_List_Input(ifstream &fin);
		void Linked_List_Output(ofstream &fout);
		void Sort_List();
		void Only_Procedural(ofstream &fout);
		void Multi_Method(ofstream &fout);
	private:
		Node *head;
		Node *tail;
		size_t size_list;
		void Swap(Node *first, Node *second);
	};
}

#endif