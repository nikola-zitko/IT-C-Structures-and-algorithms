#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct Word {
	char *word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word *next;
} Word;

typedef Word* Dictionary;

// kreaira novi prazni rjecnik
Dictionary create();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char *str);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);

// briše cijeli rjeènik
void destroy(Dictionary dict);

// vraca 1 ako je rijec dulja od 3 znaka i ako se ponavlja 5 do 10 puta
int filter(Word* w);

//Funkcija filterDictionary() vraća izmijenjenu indict listu koja sadrži samo riječi za koje je filter() funkcija vratila 1 (sve druge riječi se oslobađaju)
Dictionary filterDictionary(Dictionary indict, int (*filter)(Dictionary));

#endif
