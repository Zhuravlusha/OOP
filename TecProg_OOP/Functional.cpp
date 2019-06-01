#include "Functional.h"

void Zhuravleva::Functional::Input(ifstream &fin)
{
	Zhuravleva::Language::Input(fin);
	unsigned short int temp;
	fin >> lazy_calculations;
	fin >> temp;
	switch (temp)
	{
	case 1:
		type = Functional::typification::STRICT;
		break;
	case 2:
		type = Functional::typification::DYNAMIC;
		break;
	default:
		break;
	}
}

void Zhuravleva::Functional::Output(ofstream &fout)
{
	fout << "It is Functional programming language: Support \"lazy\" calculations is ";
	if (lazy_calculations)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
	fout << "Typification is ";
	switch (type)
	{
	case Functional::typification::STRICT:
		fout << "strict, ";
		break;
	case Functional::typification::DYNAMIC:
		fout << "dynamic, ";
		break;
	default:
		break;
	}
	Zhuravleva::Language::Output(fout);
}