#include "OOP.h"

void Zhuravleva::Object_oriented::Input(ifstream &fin)
{
	Zhuravleva::Language::Input(fin);
	unsigned short int temp;
	fin >> temp;
	switch (temp)
	{
	case 1:
		number = Object_oriented::inheritance::SINGLE;
		break;
	case 2:
		number = Object_oriented::inheritance::MULTIPLE;
		break;
	case 3:
		number = Object_oriented::inheritance::INTERFACE;
		break;
	default:
		break;
	}
}

void Zhuravleva::Object_oriented::Output(ofstream &fout)
{
	fout << "It is Object-oriented programming language: Inheritance is ";
	switch (number)
	{
	case Object_oriented::inheritance::SINGLE:
		fout << "single, ";
		break;
	case Object_oriented::inheritance::MULTIPLE:
		fout << "multiple, ";
		break;
	case Object_oriented::inheritance::INTERFACE:
		fout << "interface, ";
		break;
	default:
		break;
	}
	Zhuravleva::Language::Output(fout);
}

void Zhuravleva::Object_oriented::Multi_Method(Language *other, ofstream &fout)
{
	other->Multi_Method_OOP(fout);
}

void Zhuravleva::Object_oriented::Multi_Method_OOP(ofstream &fout)
{
	fout << "OOP and OOP." << endl;
}

void Zhuravleva::Object_oriented::Multi_Method_Procedural(ofstream &fout)
{
	fout << "Procedural and OOP." << endl;
}