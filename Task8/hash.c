#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)
	HashTable *Nova = (HashTable*)malloc(sizeof(HashTable));
	Nova -> table = ((Bin**)malloc(sizeof(Bin*)*size));
	Nova -> load = 0;
	Nova -> size = size;

	for (int i=0; i<size; i++){
		Nova -> table[i] = NULL;
	}
	return Nova;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while(*word != '\0')
	{
		key = key*HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	unsigned int indeks = hash(word) % ht->size;
	ht->load += 1;
	Bin* temp = (Bin*)malloc(sizeof(Bin));
	temp->word = word;
	temp->next = ht->table[indeks];
	ht->table[indeks] = temp;
}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	unsigned int indeks = hash(word) % ht->size;

	while(ht->table[indeks] != NULL){
		if(!strcmp(ht->table[indeks]->word, word)){
			return 1;
		}
		ht->table[indeks] = ht->table[indeks]->next;
	}
	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	for(int i = 0; i < ht->size; i++){
		while(ht->table[i] != NULL){
			Bin* temp = ht->table[i];
			ht->table[i] = ht->table[i]->next;
			free(temp->word);
			free(temp);
		}
	}
	free(ht->table);
	free(ht);
}
