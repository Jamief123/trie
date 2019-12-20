#include "pch.h"
#include "EntryType.h"
#include <string.h>
#include <iostream>
using namespace std;

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

