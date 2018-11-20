#ifndef LONGNUM_H
#define LONGNUM_H


typedef struct _Digit {
	int z;
	struct _Digit* next;
} Digit;

typedef Digit* LongNumber;

LongNumber addElement(LongNumber num, int z);
LongNumber reverse(LongNumber num);
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

#endif

