#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include "Procedural.h"
#include "OOP.h"
#include "Functional.h"
#include <ctime>
#include <string>

Zhuravleva::Language *Zhuravleva::Language::Language_Input(ifstream &fin)
{
	Language *language;
	string temp;
	fin >> temp;
	if (temp == "\0")
	{
		return false;
	}
	if (temp.length() > 1)
	{
		fin.get();
		getline(fin, temp, '\n');
		return NULL;
	}
	if (!isdigit(int(unsigned char(temp.front()))))
	{
		fin.get();
		getline(fin, temp, '\n');
		return NULL;
	}
	int state = stoi(temp);
	switch (state)
	{
	case 1:
		language = new Procedural;
		break;
	case 2:
		language = new Object_Oriented;
		break;
	case 3:
		language = new Functional;
		break;
	default:
		fin.get();
		getline(fin, temp, '\n');
		return NULL;
	}
	if (!language->Input(fin))
	{
		return NULL;
	}
	else
	{
		return language;
	}
}

bool Zhuravleva::Language::Input(ifstream &fin)
{
	string temp;
	fin >> temp;
	if (temp == "\0")
	{
		return false;
	}
	if (temp.length() != 4)
	{
		getline(fin, temp, '\n');
		return false;
	}
	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter))))
		{
			getline(fin, temp, '\n');
			return false;
		}
	}
	year_of_development = stoul(temp);

	fin >> temp;
	if (temp == "\0")
	{
		return false;
	}
	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter))))
		{
			getline(fin, temp, '\n');
			return false;
		}
	}
	reference = stoull(temp);
	return true;
}

void Zhuravleva::Language::Output(ofstream &fout)
{
	fout << "Year of development = " << year_of_development
		<< ", The number of references of this language on the Internet = " << reference << endl;
}

void Zhuravleva::Language::Only_Procedural(ofstream &fout)
{
	fout << endl;
}

int Zhuravleva::Language::Past_Years()
{
	time_t now = time(NULL);
	tm *localtm = localtime(&now);
	return 1900 + localtm->tm_year - year_of_development;
}

bool Zhuravleva::Language::Compare(Language &second)
{
	return Past_Years() < second.Past_Years();
}