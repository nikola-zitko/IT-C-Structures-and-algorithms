#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "sortiranja.h"



void main() {

	int* niz;
	int n;
	clock_t start_t, end_t;

	printf("Unesi duljinu niza: ");
	scanf("%d", &n);

	choose_pivot = false;
	start_t = clock();
	niz = generate(n);
	//print(niz, n);
	partition(niz, n);
	end_t = clock();
	printf("Vrijeme izvodenja: %f\n", ((float)(end_t - start_t) / CLOCKS_PER_SEC));

	choose_pivot = true;
	start_t = clock();
	niz = generate(n);
	partition(niz, n);
	end_t = clock();
	printf("Vrijeme izvodenja sa pivotom: %f\n", ((float)(end_t - start_t) / CLOCKS_PER_SEC));


}