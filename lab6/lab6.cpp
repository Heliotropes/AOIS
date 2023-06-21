#include <iostream>
#include <vector>
#include <string>

using namespace std;

int GetHash(string key);
void Add(string key, string value);
void Search(string key);
void Delete(string key);
void Print();


struct HashTableElement
{
	int id;
	string key;
	string value;
	int colision;

	HashTableElement()
	{
		key = "";
		value = "";
		id = 0;
		colision = 0;
	}

	HashTableElement(string _key, string _value)
	{
		key = _key;
		value = _value;
		id = GetHash(key);
		colision = 0;
	}
};

vector <HashTableElement> Table(174);

int main()
{
	while (1)
	{
		Print();
		string key, value;
		cout << "\n\n1) - Add\n2) - Search\n3) - Delete\n4) - Clear\n";
		int variant;
		cin >> variant;
		if (variant == 1) 
		{
			cin >> key >> value;
			Add(key, value);
		}
		else if (variant == 2)
		{
			cin >> key;
			Search(key);
		}
		else if (variant == 3)
		{
			cin >> key;
			Delete(key);
		}
		else if (variant == 4) system("cls");
		cout << "\n\n";
	}
}

int GetHash(string key)
{
	int result = 0;
	if (key.length() >= 3) result = int(key[0]) + int(key[1]) + int(key[2]) - 192;
	else if (key.length() == 2) result = int(key[0]) + int(key[1])-128;
	else if (key.length() == 1) result = int(key[0])-64;
	return result;
}

void Add(string key, string value)
{
	HashTableElement currentElem(key, value);
	if(Table[GetHash(key)  ].id == 0) Table[GetHash(key)  ] = currentElem;
	else 
	{
		Table[GetHash(key)  ].colision = GetHash(key)  ;
		int i = 1;
		while (GetHash(key)   + i < Table.size() && Table[GetHash(key)   + i].id != 0)
			++i;
		Table[GetHash(key) + i] = currentElem;
		Table[GetHash(key) + i].id = GetHash(key) + i;
		Table[GetHash(key)   + i].colision = GetHash(key)  ;
	}
}

void Search(string key)
{
	cout << Table[GetHash(key)  ].value;
}

void Delete(string key)
{
	HashTableElement currentElem("", "");
	Table[GetHash(key) ] = currentElem;
}
void Print()
{
	int index = 0;
	while (index < Table.size()) {
		if (Table[index].id != 0)cout <<"\n" << Table[index].id << " " << Table[index].key << " " << Table[index].value;
		if (Table[index].id != 0 && Table[index].colision != 0) cout << " *colision - " << Table[index].colision << "*";
		++index;
	}
}