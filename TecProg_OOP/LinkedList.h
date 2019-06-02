#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Zhuravleva
{
	class LinkedList
	{
		struct Node
		{
			Language *language;
			Node *Next;
			Node *Prev;
		};
	public:
		LinkedList();
		~LinkedList();

		void LinkedList_Input(ifstream &fin);
		void LinkedList_Output(ofstream &fout);

		void Only_Procedural(ofstream &fout);

		void Sort_List();
	private:
		Node *First;
		Node *Last;
		size_t SizeList;

		void Swap(Node *first, Node *second);
	};
}

#endif // !LINKEDLIST_H