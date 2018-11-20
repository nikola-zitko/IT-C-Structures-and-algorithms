/*
#include<stdio.h>
#include<stdlib.h>
int** podijeli(int* niz, int n) {
	int j = 0;
	int* Lniz = (int*)malloc((n / 2) * sizeof(int));
	int* Dniz = (int*)malloc((n - (n / 2)) * sizeof(int));
	int** nizNizova = (int**)malloc(2 * (sizeof(int*)));
	for (int i = 0; i < (n / 2); i++) {
		Lniz[i] = niz[i];
	}
	for (int i= (n/2); i < n; i++) {
		Dniz[j] = niz[i];
		j++;
	}
	nizNizova[0] = Lniz;
	nizNizova[1] = Dniz;
	return nizNizova;
}
void main() {
	int niz[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = 10;
	
	int** noviNiz = podijeli(niz, n);
	int* lijeviNiz = noviNiz[0];
	int* desniNiz = noviNiz[1];
	for (int i = 0; i < (n / 2); i++) {
		printf("%d ", lijeviNiz[i]);
		
	}
	printf("\n");
	for (int i = 0; i < (n-(n/2)); i++) {
		printf("%d ", desniNiz[i]);
	}
}
*/
