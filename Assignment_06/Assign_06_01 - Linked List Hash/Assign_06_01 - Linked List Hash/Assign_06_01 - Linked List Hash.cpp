// Assign_06_01 - Linked List Hash.cpp : Defines the entry point for the console application.

/*
	Modify the HashTable implemented in class to support separate chaining with Linked List 
*/

/*	Tyler Quayle  */

#include "stdafx.h"
#include <iostream>

using namespace std;

class HashNode
{
public:
	char* key;
	int value;
	HashNode* next;

	HashNode(char* key, int value)
	{
		this->key = key;
		this->value = value;
		next = NULL;
	}
};


int hashStrings(char* key)
{
	char a = key[0];
	int hashresult = 0;
	int i = 1;
	while (a != '\0')
	{
		hashresult += (int)a - 48;
		a = key[i++];
	}
	return hashresult;
}

class HashTable
{
	HashNode** table;
	int end;

public:
	HashTable(int pN)
	{
		table = new HashNode*[pN];
		for (int i = 0; i < pN; i++)
                table[i] = NULL;
		end = pN;
	}

	void Add(char* key, int value)
    {
		int hash_val = hashStrings(key);
        HashNode* prev = NULL;
        HashNode* entry = table[hash_val];
        while (entry != NULL)
        {
            prev = entry;
            entry = entry->next;
        }
        if (entry == NULL)
        {
            entry = new HashNode(key, value);
			if (prev == NULL)
			{
				table[hash_val] = entry;
			}
			else
			{
				prev->next = entry;
			}
        }
        else
        {
            entry->value = value;
        }
    }

	int Find(char* key)
	{
        int hash_val = hashStrings(key);

		HashNode* lookUp = table[hash_val];
		
        while (lookUp != NULL)
	    {
            if (lookUp->key == key){  return lookUp->value;}
            
			lookUp = lookUp->next;
        }
        
		cout << "No entry: ";
        return -1;
        
	}

    void Remove(char* key)
    {
        int hash_val = hashStrings(key);
		bool found = false;
        HashNode* entry = table[hash_val];
        HashNode* prev = NULL;
        if (entry == NULL)
        {
            cout<<"No Element found at key "<<key<<endl;
            return;
        }
		
		if(entry->key == key){table[hash_val] = entry->next;}

		else
		{
			while (entry->next != NULL && entry->key != key)
			{
				prev = entry;
				entry = entry->next;
				if(entry->key == key)
					found = true;
			}
		
			if (prev != NULL)
				prev->next = entry->next;
		
			if(found == true)
				delete entry;
			else
			{
				cout << "No key found in element chain";
				return;
			}
		}
        cout << endl << key <<" Removed"<<"\n";
    }
};

int main()
{
	HashTable* ht = new HashTable(10000);
	ht->Add("abc", 100000);
	ht->Add("acb", 100000);
	ht->Add("bac", 200000);
	ht->Add("bca", 150000);
	ht->Add("cab", 175000);
	ht->Add("cba", 225000);

	cout << "abc" << " " << ht->Find("abc") << endl;
	cout << "acb" << " " << ht->Find("acb") << endl;
	cout << "bac" << " " << ht->Find("bac") << endl;
	cout << "bca" << " " << ht->Find("bca") << endl;
	cout << "cab" << " " << ht->Find("cab") << endl;
	cout << "cba" << " " << ht->Find("cba") << endl;
	cout << "dba" << " " << ht->Find("dba") << endl;

	ht->Remove("abc");

	ht->Remove("bca");
	
	cout << endl;
	cout << "abc" << " " << ht->Find("abc") << endl;
	cout << "acb" << " " << ht->Find("acb") << endl;
	cout << "bac" << " " << ht->Find("bac") << endl;
	cout << "bca" << " " << ht->Find("bca") << endl;
	cout << "cab" << " " << ht->Find("cab") << endl;
	cout << "cba" << " " << ht->Find("cba") << endl;

	cout << endl;
	system("pause");
	return 0;
}
