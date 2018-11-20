#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include "sortiranja.h"



void main() {

	int *niz;
	int n;
	clock_t start_t, end_t;
	double total_t;

	printf("Unesite zeljenu duljinu niza: ");
	scanf("%d", &n);

	for(int i = 0; i < 4; i++) {
	// generiramo niz 4 puta, prvi i treći puta bez pivota, treći i četvrti puta sa već sortiranim nizom
        niz = generate(n);
        if (i > 1) quicksort(niz, n);

        (i % 2) == 1 ? (choose_pivot = true) : (choose_pivot = false);

        start_t = clock();
        quicksort(niz, n);
        end_t = clock();

        switch(i){
            case 0:
                printf("Vrijeme izvodenja quicksorta nasumicnog niza bez odabira pivota: ");
                break;
            case 1:
                printf("Vrijeme izvodenja quicksorta nasumicnog niza sa odabirom pivota: ");
                break;
            case 2:
                printf("Vrijeme izvodenja quicksorta sortiranog niza bez odabira pivota: ");
                break;
            case 3:
                printf("Vrijeme izvodenja quicksorta sortiranog niza sa odabirom pivota: ");
                break;
            default:
                printf("U WuT M8?!");
                break;
        }
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        printf("%f\n", total_t);
	}
}
