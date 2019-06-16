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

void Zhuravleva::Procedural::Multi_Method(Language *other, ofstream &fout)
{
	other->Multi_Method_Procedural(fout);
}

void Zhuravleva::Procedural::Multi_Method_Procedural(ofstream &fout)
{
	fout << "Procedural and Procedural." << endl;
}

void Zhuravleva::Procedural::Multi_Method_OOP(ofstream &fout)
{
	fout << "OOP and Procedural." << endl;
}