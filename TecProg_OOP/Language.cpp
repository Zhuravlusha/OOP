#include "Language.h"
#include "Procedural.h"
#include "OOP.h"

Zhuravleva::Language* Zhuravleva::Language::Language_Input(ifstream &fin)
{
	Language *language;
	unsigned short int temp;
	fin >> temp;
	switch (temp)
	{
	case 1:
		language = new Procedural;
		break;
	case 2:
		language = new Object_oriented;
		break;
	default:
		return 0;
	}
	language->Input(fin);
	return language;
}

void Zhuravleva::Language::Input(ifstream &fin)
{
	fin >> year_of_development;
}

void Zhuravleva::Language::Output(ofstream &fout)
{
	fout << "Year of development = " << year_of_development << endl;
}

void Zhuravleva::Language::Only_Procedural(ofstream &fout)
{
	fout << endl;
}