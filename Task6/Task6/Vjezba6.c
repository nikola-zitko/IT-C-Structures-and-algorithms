#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



typedef struct ElementReda {
	int Prioritet;
}ElementReda;

int PopraviPremaVrhu(ElementReda* Niz, int Indeks);

void DodajElement(ElementReda* Niz, int* Zadnji, int P) {
	Niz[*Zadnji].Prioritet = P;
	PopraviPremaVrhu(Niz, (*Zadnji));
	(*Zadnji)++;
}

void IzbrisiElement(ElementReda* Niz, int* Zadnji) {
	Niz[0].Prioritet = Niz[(*Zadnji)-1].Prioritet;
	Niz[(*Zadnji)-1].Prioritet = NULL;
	(*Zadnji)--;
	PopraviPremaDnu(Niz, 0, *Zadnji);
}

void IspisiNiz(ElementReda* Niz, int Max) {
	for (int i = 0; i < Max; i++) {
		printf("%d ", Niz[i].Prioritet);
	}
}

int PopraviPremaVrhu(ElementReda* Niz, int Indeks) {
	int temp;
	if (Indeks == 0) {
		return 0;
	}
	if (Niz[Indeks].Prioritet > Niz[(Indeks - 1) / 2].Prioritet) {
		temp = Niz[Indeks].Prioritet;
		Niz[Indeks].Prioritet = Niz[(Indeks - 1) / 2].Prioritet;
		Niz[(Indeks - 1) / 2].Prioritet = temp;
		
		PopraviPremaVrhu(Niz, (Indeks - 1) / 2);
	}
	else {
		return 0;
	}
}

int PopraviPremaDnu(ElementReda* Niz, int Indeks, int Max) {
	int L = 2 * Indeks + 1;
	int D = 2 * Indeks + 2;
	int temp;
	if ((L > Max) || (D > Max)) {
		return 0;
	}
	if ((Niz[Indeks].Prioritet < Niz[L].Prioritet) && (Niz[L].Prioritet > Niz[D].Prioritet)) {
		temp = Niz[Indeks].Prioritet;
		Niz[Indeks].Prioritet = Niz[L].Prioritet;
		Niz[L].Prioritet = temp;
		PopraviPremaDnu(Niz, L, Max);
	}
	else if ((Niz[Indeks].Prioritet < Niz[D].Prioritet)) {
		temp = Niz[Indeks].Prioritet;
		Niz[Indeks].Prioritet = Niz[D].Prioritet;
		Niz[D].Prioritet = temp;
		PopraviPremaDnu(Niz, D, Max);
	}
	else {
		return 0;
	}
}

void main() {
	ElementReda PrioritetniNiz[10000];
	int BrojEl = 0;

	DodajElement(PrioritetniNiz, &BrojEl, 23);
	DodajElement(PrioritetniNiz, &BrojEl, 30);
	DodajElement(PrioritetniNiz, &BrojEl, 60);
	DodajElement(PrioritetniNiz, &BrojEl, 25);
	DodajElement(PrioritetniNiz, &BrojEl, 10);
	DodajElement(PrioritetniNiz, &BrojEl, 70);
	DodajElement(PrioritetniNiz, &BrojEl, 80);
	DodajElement(PrioritetniNiz, &BrojEl, 50);
	DodajElement(PrioritetniNiz, &BrojEl, 85);
	IzbrisiElement(PrioritetniNiz, &BrojEl);
	IzbrisiElement(PrioritetniNiz, &BrojEl);
	IzbrisiElement(PrioritetniNiz, &BrojEl);
	IzbrisiElement(PrioritetniNiz, &BrojEl);
	IzbrisiElement(PrioritetniNiz, &BrojEl);
	IzbrisiElement(PrioritetniNiz, &BrojEl);


	IspisiNiz(PrioritetniNiz, BrojEl);

}
