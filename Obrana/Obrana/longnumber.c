#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

#include "longnumber.h"

// jedna dekadska znamenka (0-9)
/*
typedef struct _Digit {
	int z;
	struct _Digit *next;
} Digit;
*/

// "dugi" broj je lista znamenaka. Najmanje znacajna znamenka je na pocetku liste
typedef Digit* LongNumber;

// pomocna funkcija koja okrece listu znamenaka, trebati ce na vise mjesta
// jer ce se operacije uglavnom oslanjati na dodavanje u glavu liste
// ne gradi novu listu nego preuredjuje dobivenu listu
LongNumber reverse(LongNumber num);

// cita broj iz tekstualne datoteke znamenku po znamenku i gradi listu (dugi broj)
LongNumber read_longnum(char* fname);

// zapisuje broj u tekstualnu datoteku znamenku po znamenku
void write_longnum(LongNumber num, char* fname);

// ispisuje broj na ekran 
void print_longnum(LongNumber num);

// oslobadja listu znamenaka
void delete_longnum(LongNumber num);

// zbraja dva broja. 
// Algoritam zbraja znamenku po znamenku i prenosi ostatak na iducu znamenku.
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber add_longnum(LongNumber a, LongNumber b);

// pomocna funkcija koja mnozi broj sa znamenkom (uz prenosenje ostatka na iducu znamenku). 
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber mul_by_digit(LongNumber num, int z);

// pomocna funkcija koja mnozi broj sa potencijom od 10 (odnosno dodaje nule na pocetak broja)
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber mul_by_pow10(LongNumber num, int pow);

// mnozi dva broja oslanjanjuci se na prethodne funkcije. Primjer:
// 123 x 235
// ---------
//   123 * 10^0 * 5
//   123 * 10^1 * 3
// + 123 * 10^2 * 2
// --------
//  28905 
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber mul_longnum(LongNumber a, LongNumber b);
