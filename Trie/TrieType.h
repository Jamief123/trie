#pragma once
#include "EntryType.h"
const int LETTERS = 26;
typedef char Key[MAXLENGTH];
struct Trienode
{
	Trienode *branch[LETTERS];
	EntryType *ref;
};

class TrieType
{
public:
	TrieType();
	~TrieType();
	TrieType(TrieType &originalTree);
	void operator=(TrieType & originalTree);
	void MakeEmpty();
	void InsertTrie(Key newkey, EntryType *newentry);
	EntryType* TrieSearch(Key target);
	bool DeleteTrie(Key delkey);
	void PrintTrie(ostream& outfile) const;
	void Display(Key searchKkey);
	void DisplayAll(Trienode* root, char* word, int pos = 0);
	void PrintAll();
private:
	Trienode * root;
};

TrieType::TrieType()
{
}


TrieType::~TrieType()
{
}

EntryType * TrieType::TrieSearch(Key target)
{
	int i;
	Trienode* current = root;
	for (i = 0; i < MAXLENGTH && current; i++)
		if (target[i] == '\0')
			break;
		else
			current = current->branch[target[i] - 'a'];
	if (!current)
		return NULL;
	else
		if (!current->ref)
			return NULL;

	return current->ref;
}

Trienode *CreateNode()
{
	int ch;
	Trienode *newnode = new Trienode;
	for (ch = 0; ch < LETTERS; ch++)
		newnode->branch[ch] = NULL;

	newnode->ref = NULL;

	return newnode;
}

void TrieType::InsertTrie(Key newkey, EntryType *newentry)
{
	int i;
	Trienode *current;
	if (!root)
		root = CreateNode();
	current = root;
	for (i = 0; i < MAXLENGTH; i++)
		if (newkey[i] == '\0')
			break;
		else
		{
			if (!current->branch[newkey[i] - 'a'])
				current->branch[newkey[i] - 'a'] = CreateNode();
			current = current->branch[newkey[i] - 'a'];
		}
	if (current->ref != NULL)
		cout << "\nTried to insert a duplicate key." << endl;
	else
		current->ref = newentry;

}

void TrieType::Display(Key searchKey)
{
	int i;
	Trienode *current;
	if (!root) {
		cout << "No words have been inserted into the trie.";
		return;
	}
	current = root;
	for (i = 0; i < MAXLENGTH; i++)
		if (searchKey[i] == '\0')
			break;
		else
		{
			if (!current->branch[searchKey[i] - 'a'])
				current->branch[searchKey[i] - 'a'] = CreateNode();
			current = current->branch[searchKey[i] - 'a'];
		}
	if (current->ref != NULL)
		current->ref->PrintWord();
	else
		cout << "No such key found";
}

void TrieType::DisplayAll(Trienode* root, char* word, int pos) {

	if (root == NULL)
		return;

	if (!root->ref == '\0')
	{
		root->ref->PrintWord();
	}
	for (int i = 0; i < LETTERS; i++)
	{
		if (root->branch[i] != NULL)
		{
			word[pos] = i + 'a';
			DisplayAll(root->branch[i], word, pos + 1);
		}
	}
}

void TrieType::PrintAll()
{
	char wordArray[MAXLENGTH];
	DisplayAll(root,wordArray);
}
