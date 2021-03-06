// Trie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "TrieType.h"

using namespace std;

char word[10];
EntryType *item;

int DisplayMenu(void);
int main()
{
	TrieType trie;
	int option;

	do
	{
		option = DisplayMenu();
		switch (option)
		{
		case 1:
		{
			//Insert
			system("cls");
			cout << "Enter the word to insert into trie" << endl;
			cin >> word;
			EntryType* myword = new EntryType(word);
			trie.InsertTrie(word, myword);
			break;
		}
		case 2:
		{
			//Search 
			system("cls");
			cout << "Enter the word you want to search for: " << endl;
			cin >> word;
			if (trie.TrieSearch(word))
				cout << "Word found in trie\n";
			else
				cout << "Word not found in trie\n";
			break;
		}
		case 3:
		{
			//Print Alphabetically
			system("cls");
			trie.PrintAll();
			break;
		}
		case 4:
		{
			//Delete
			system("cls");
			cout << "Enter the word you want to delete: " << endl;
			cin >> word;
			if (trie.DeleteTrie(word) == true)
				cout << "Word deleted from trie\n";
			else
				cout << "Word not found in trie\n";
			break;
		}
		case 5: 
		{
			break;
		}
		default:
			cout << "Wrong option\n";
		}
	} while (option != 5);


	return 0;
}

int DisplayMenu(void)
{
	int option;
	cout << endl;
	cout << "\t1. Insert into to a Trie\n";
	cout << "\t2. Search a Trie\n";
	cout << "\t3. Print Words Alphabetically\n";
	cout << "\t4. Delete from a Trie\n";
	cout << "\t5. To Exit\n";
	cout << "\t\tEnter option : ";
	cin >> option;
	return option;
	cout << endl;
}
