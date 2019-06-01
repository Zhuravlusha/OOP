#include "Procedural.h"

void Zhuravleva::Procedural::Input(ifstream &fin)
{
	Zhuravleva::Language::Input(fin);
	fin >> abstract_type;
}

void Zhuravleva::Procedural::Output(ofstream &fout)
{
	fout << "It is Procedural programming language: Abstract data types is ";
	if (abstract_type)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
	Zhuravleva::Language::Output(fout);
}

void Zhuravleva::Procedural::Only_Procedural(ofstream &fout)
{
	Zhuravleva::Procedural::Output(fout);
}