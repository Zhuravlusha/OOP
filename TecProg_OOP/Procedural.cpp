#include "Procedural.h"
#include <string>

bool Zhuravleva::Procedural::Input(ifstream &fin)
{
	if (!Zhuravleva::Language::Input(fin))
	{
		return false;
	}

	string temp;
	fin >> temp;
	if (temp == "\0")
	{
		return false;
	}
	if (temp.length() > 1)
	{
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front()))))
	{
		return false;
	}

	int state = stoi(temp);
	if (state > 0)
	{
		abstract_type = true;
	}
	else
	{
		abstract_type = false;
	}
	return true;
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

void Zhuravleva::Procedural::Multi_Method_Functional(ofstream &fout)
{
	fout << "Functional and Procedural." << endl;
}