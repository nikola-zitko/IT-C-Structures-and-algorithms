#include "longnumber.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>


// dodavanje u glavu
LongNumber addElement(LongNumber num, int z) {
	LongNumber element = (LongNumber)malloc(sizeof(Digit));
	element->z = z;
	element->next = num;
	return element;
}

// pomocna funkcija koja okrece listu znamenaka, trebati ce na vise mjesta
// jer ce se operacije uglavnom oslanjati na dodavanje u glavu liste
// ne gradi novu listu nego preuredjuje dobivenu listu

LongNumber reverse(LongNumber num) {
	LongNumber n = NULL;
	while (num != NULL) {
		n = addElement(n, num->z);
		num = num->next;
	}
	return n;
}
// cita broj iz tekstualne datoteke znamenku po znamenku i gradi listu (dugi broj)
LongNumber read_longnum(char* fname) {

	FILE* fp = fopen(fname, "r");
	if (fp == NULL) {
		printf("Greska pri otvaranju datoteke!");
	}

	LongNumber head = NULL;
	char broj;
	do {
		broj = fgetc(fp);
		if (feof(fp)) {
			break;
		}
		int i = broj - '0';
		head = addElement(head, i);
	} while (1);
	
	fclose(fp);

	return head;
} 

// zapisuje broj u tekstualnu datoteku znamenku po znamenku
void write_longnum(LongNumber num, char* fname) {
	FILE* fpw = fopen(fname, "w");
	const LongNumber tmp = num;
	while (num != NULL) {
		fprintf(fpw, "%d", (num->z));
		num = num->next;
	}
	num = tmp;
	fclose(fpw);
}

// ispisuje broj na ekran 
void print_longnum(LongNumber num) {
	num = reverse(num);
	LongNumber tmp = num;
	if (num == NULL) {
		printf("Prazna lista!");
	}
	while (num != NULL) {
		printf("%d ", num->z);
		num = num->next;
	}
	printf("\n");
	num = reverse(num);
	
}

// oslobadja listu znamenaka
void delete_longnum(LongNumber num) {
	if (num == NULL) {
		return num;
	}
	LongNumber tmp = num;
	LongNumber prev = NULL;
	LongNumber next = NULL;
	
	//setamo po listi i brisemo prethodni
	while (num != NULL) {
		next = num->next;
		prev = num;
		num = next;
		free(prev);
	}
	num = tmp;
}

// zbraja dva broja. 
// Algoritam zbraja znamenku po znamenku i prenosi ostatak na iducu znamenku.
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber add_longnum(LongNumber a, LongNumber b) {
	LongNumber tmpA = a;
	LongNumber tmpB = b;
	LongNumber c = NULL;
	int prijenos = 0, zbroj = 0;
	int tempA, tempB;
	while (a || b || prijenos > 0) {
		if (a == NULL) {
			tempA = 0;
		}
		else {
			tempA = a->z;
			a = a->next;
		}
		if (b == NULL) {
			tempB = 0;
		}
		else {
			tempB = b->z;
			b = b->next;
		}

		zbroj = tempA + tempB + prijenos;
		if (zbroj > 9) {
			c = addElement(c, zbroj % 10);
			prijenos = zbroj / 10;
		}
		else {
			c = addElement(c, zbroj);
			prijenos = zbroj / 10;
		}
	}
	a = tmpA;
	b = tmpB;
	c = reverse(c);
	return c;
}

// pomocna funkcija koja mnozi broj sa znamenkom (uz prenosenje ostatka na iducu znamenku). 
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber mul_by_digit(LongNumber num, int z) {
	LongNumber d = NULL;
	int prijenos = 0, umnozak, tmpN;
	LongNumber tmp = num;
	 
	while (num != NULL || prijenos>0) {
		if (num == NULL) {
			tmpN = 0;
		}
		else {
			tmpN = num->z;
			num = num->next;
		}
		umnozak = tmpN*z + prijenos;

		if ((umnozak) > 9) {
			
			d = addElement(d, (umnozak%10));
			prijenos = umnozak/10;
		}
		else {
			d = addElement(d, umnozak);
			prijenos = 0;
		}
		if (num == NULL && prijenos > 10) {
			d = addElement(d, prijenos % 10);
			prijenos = prijenos / 10;
		}
		else if(num == NULL){
			d = addElement(d, prijenos);
			prijenos = 0;
		}
		
		
	}
	num = tmp;
	d = reverse(d);
	return d;
}

// pomocna funkcija koja mnozi broj sa potencijom od 10 (odnosno dodaje nule na pocetak broja)
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber mul_by_pow10(LongNumber num, int pow) {
	
	LongNumber tmp = num;
	if (num == NULL) {
		return NULL;
	}
	
	for (int i = 0; i < pow; i++) {
		num = addElement(num, 0);
	}

	return num;
}

// mnozi dva broja oslanjanjuci se na prethodne funkcije. Primjer:
// 123 x 235
// ---------
//   123 * 10^0 * 5
//   123 * 10^1 * 3
// + 123 * 10^2 * 2
// --------
//  28905 
// Gradi se potpuno nova lista (broj) kao rezultat.

LongNumber mul_longnum(LongNumber a, LongNumber b) {
	LongNumber tmp1, tmp2, suma = NULL;
	int i = 0;
	while (b != NULL) {
		tmp1 = mul_by_pow10(a, i);
		tmp2 = mul_by_digit(tmp1, b->z);
		suma = add_longnum(suma, tmp2);
		b = b->next;
		i++;
	}
	free(tmp1);
	free(tmp2);

	return suma;
}