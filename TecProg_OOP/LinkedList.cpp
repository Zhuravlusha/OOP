#include "LinkedList.h"

Zhuravleva::LinkedList::LinkedList()
{
	First = NULL;
	Last = NULL;
	SizeList = 0;
}

Zhuravleva::LinkedList::~LinkedList()
{
	Node *Temp = NULL;
	while (Last != NULL)
	{
		Temp = Last->Prev;
		delete Last;
		Last = Temp;
		--SizeList;
	}
	First = Temp;
}



void Zhuravleva::LinkedList::LinkedList_Input(ifstream &fin)
{
	Node *Temp;
	while (!fin.eof())
	{
		Temp = new Node;

		Temp->Next = NULL;

		Temp->language = Language::Language_Input(fin);

		++SizeList;

		if (First == NULL)//åñëè ñïèñîê ïóñòîé
		{
			Temp->Prev = NULL;
			First = Last = Temp;
		}
		else//åñëè â ñïèñêå åñòü õîòÿ áû 1 ýëåìåíò
		{
			Temp->Prev = Last;
			Last->Next = Temp;
			Last = Temp;
		}
	}
}

void Zhuravleva::LinkedList::LinkedList_Output(ofstream &fout)
{
	Node *current = First;
	fout << "Container contains " << SizeList << " elements." << endl;

	for (size_t i = 0; i < SizeList; i++)
	{
		fout << i + 1 << ": ";
		current->language->Output(fout);
		current = current->Next;
	}
}

void Zhuravleva::LinkedList::Only_Procedural(ofstream &fout)
{
	Node *current = First;
	fout << "Only Procedural languages." << endl;

	for (size_t i = 0; i < SizeList; i++)
	{
		fout << i + 1 << ": ";
		current->language->Only_Procedural(fout);
		current = current->Next;
	}

	fout << endl;
}