/*
#include<stdio.h>
#include<stdlib.h>


int* filtriraj(int* niz, int n, int th, int* nth) {
	int brojac = 0;
	for (int i = 0; i < n; i++) {
		if (niz[i] < th) {
			brojac++;
		}
	}


	int* niz2 = (int*)malloc(brojac * sizeof(int));
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (niz[i] < th) {
			niz2[j] = niz[i];
			j++;
		}
	}
	*nth = brojac;
	return niz2;
}

void main() {
	int duljinaNovogNiza;
	int* nth = &duljinaNovogNiza;
	int niz[] = { 1,-2,3,54,25,6,7,-18,9,-10 };
	int n = (sizeof(niz) / sizeof(int));
	
	int* niz2 = filtriraj(niz, n, 7, nth);
	for (int i = 0; i < duljinaNovogNiza; i++) {
		printf("%d\n", niz2[i]);
	}
}
*/