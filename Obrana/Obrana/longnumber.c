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
	//trenutni, sljedeci i prethodni element liste
	LongNumber current = num;
	LongNumber prev = NULL;
	LongNumber next = NULL;

	//provjera je li lista prazna ili ima samo jedan clan
	if (current == NULL) {
		printf("Prazna lista");
		return current;
	}
	else if (current->next == NULL) {
		return current;
	}

	while (current != NULL) {
		//postavimo sljedeci
		next = current->next;
		//preusmjerimo pokazivac trenutnog na prethodnog
		current->next = prev;
		//pomaknemo pokazivace jednu poziciju naprijed
		prev = current;
		current = next;
	}
	//postavljamo novi "head" liste
	return prev;
}

// cita broj iz tekstualne datoteke znamenku po znamenku i gradi listu (dugi broj)
LongNumber read_longnum(char* fname) {

	FILE* fp = fopen(fname, "r");
	if (fp == NULL) {
		printf("Greska pri otvaranju datoteke!");
	}
	LongNumber head = NULL;
	int broj;
	fscanf(fp, "%d", &broj);
	while (broj > 0) {
		head = addElement(head, (broj % 10));
		broj /= 10;
	}
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
	const LongNumber tmp = num;
	if (num == NULL) {
		printf("Prazna lista!");
	}
	while (num != NULL) {
		printf("%d ", num->z);
		num = num->next;
	}
	printf("\n");
	num = tmp;
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
	a = reverse(a);
	LongNumber tmpA = a;
	b = reverse(b);
	LongNumber tmpB = b;
	
	LongNumber c = NULL;
	int prijenos = 0, zbroj=0;
	while (a || b) {
		if (a==NULL && b!=NULL) {
			zbroj = (b->z) + prijenos;
			if (zbroj > 9) {
				c = addElement(c, zbroj % 10);
				prijenos = zbroj / 10;
			}
			else {
				c = addElement(c, zbroj);
				prijenos = 0;
			}
			b = b->next;
			
		}
		else if(a!=NULL && b==NULL) {
			zbroj = (a->z) + prijenos;
			if (zbroj > 9) {
				c = addElement(c, zbroj % 10);
				prijenos = zbroj / 10;
			}
			else {
				c = addElement(c, zbroj);
				prijenos = 0;
			}
			a = a->next;
		}
		else if(a!=NULL && b!=NULL){
			zbroj = (a->z) + (b->z) + prijenos;
			if (zbroj > 9) {
				c = addElement(c, zbroj % 10);
				prijenos = zbroj / 10;
			}
			else {
				c = addElement(c, zbroj);
				prijenos = 0;
			}
			a = a->next;
			b = b->next;
		}
	}
	while (prijenos > 0) {
		if (prijenos > 9) {
			c = addElement(c, (prijenos % 10));
			prijenos = zbroj / 10;
		}
		else {
			c = addElement(c, prijenos);
			prijenos = 0;
		}
	}
	
	a = tmpA;
	b = tmpB;
	a = reverse(a);
	b = reverse(b);
	return c;
}

// pomocna funkcija koja mnozi broj sa znamenkom (uz prenosenje ostatka na iducu znamenku). 
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber mul_by_digit(LongNumber num, int z) {
	LongNumber d = NULL;
	int prijenos = 0, umnozak;
	
	num = reverse(num);
	LongNumber tmp = num;
	
	while (num != NULL) {
		umnozak = (num->z)*z + prijenos;
		if ((umnozak) > 9) {
			
			d = addElement(d, (umnozak%10));
			prijenos = umnozak/10;
		}
		else {
			d = addElement(d, umnozak);
			prijenos = 0;
		}
		num = num->next;
		
	}
	while(prijenos > 0) {
		if (prijenos > 10) {
			d = addElement(d, prijenos % 10);
			prijenos = prijenos / 10;
		}
		else {
			d = addElement(d, prijenos % 10);
			prijenos = 0;
		}
	}
	num = tmp;
	num = reverse(num);
	
	return d;
}

// pomocna funkcija koja mnozi broj sa potencijom od 10 (odnosno dodaje nule na pocetak broja)
// Gradi se potpuno nova lista (broj) kao rezultat.
LongNumber mul_by_pow10(LongNumber num, int pot) {
	int prijenos = 0, umnozak = 0;
	
	num = reverse(num);
	
	LongNumber tmp = num;
	LongNumber e = NULL;

	while (num != NULL) {
		umnozak = (num->z)*pow(10,pot) + prijenos;
		if ((umnozak) > 9) {

			e = addElement(e, (umnozak % 10));
			prijenos = umnozak / 10;
		}
		else {
			e = addElement(e, umnozak);
			prijenos = 0;
		}
		num = num->next;

	}
	while (prijenos > 0) {
		if (prijenos > 10) {
			e = addElement(e, prijenos % 10);
			prijenos = prijenos / 10;
		}
		else {
			e = addElement(e, prijenos % 10);
			prijenos = 0;
		}
	}
	num = tmp;
	num = reverse(num);
	
	return e;
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
	LongNumber tmp1, suma = NULL;
	b = reverse(b);
	int i=0;
	while(b!=NULL){
	tmp1=mul_by_digit(mul_by_power10(a, i), b->z);
	suma=add_longnum(suma, tmp1);
	b=b->next;
	i++;
	}

	return suma;
}
