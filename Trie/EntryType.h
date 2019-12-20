#pragma once
#include <iostream>
using namespace std;

#ifndef ENTRYTYPE
#define ENTRYTYPE
#endif

const int MAXLENGTH = 10;
class EntryType
{
public:
	EntryType();
	EntryType(char * key);
	EntryType(EntryType & entry);

	friend istream& operator>> (istream& is, EntryType& item);
	friend ostream& operator<< (ostream& os, EntryType item);

	bool operator== (const EntryType& item) const;
	bool operator!= (const EntryType& item) const;
	void EntryKey(char word[]);
	void PrintWord();

private:
	char entryKey[MAXLENGTH];
};

void EntryType::EntryKey(char word[])
{
	for (int i = 0; i < 10; i++)
	{
		entryKey[i] = word[i];
	}
}

void EntryType::PrintWord()
{
	cout << entryKey << endl;
}

EntryType::EntryType()
{
}

EntryType::EntryType(char * key)
{
	strcpy_s(entryKey, key);

}

EntryType::EntryType(EntryType & entry)
{
	strcpy_s(entryKey, entry.entryKey);

}

istream& operator>> (istream& is, EntryType& entry)
{
	is >> entry.entryKey;
	return is;
}

ostream& operator<< (ostream& os, EntryType entry)
{
	os << entry.entryKey;
	return os;
}

bool EntryType::operator== (const EntryType& entry) const
{
	return entryKey == entry.entryKey;
}

bool EntryType::operator!= (const EntryType& entry) const
{
	return entryKey != entry.entryKey;
}