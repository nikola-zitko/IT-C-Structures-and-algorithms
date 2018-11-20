#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include "sortiranja.h"

void main() {

	int *niz;
	int n;
    	n_min = 200;

	printf("Unesite zeljenu duljinu niza: ");
	scanf("%d", &n);

	// ako je n veći od n_min, normalno printamo i radimo...
	if(n >= n_min) {
		for(int i = 0; i < 4; i++) {
			// generiramo niz 4 puta, prvi i treći puta bez pivota, treći i četvrti puta sa već sortiranim nizom
       	 		niz = generate(n);
        		if (i > 1) quicksort(niz, n);
      	  		(i % 2) == 1 ? (choose_pivot = true) : (choose_pivot = false);

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
			printf("%f\n", measure(quicksort, niz, len));
		}
	// u suprotnom, umjesto quicksort se koristi selectionsort, pa su nam nepotrebne 4 različite situacije kao gore ^^
	} else {
		niz = generate(n);
		// primjenjuje se selectionsort() umjesto quicksort
		printf("Vrijeme izvodenja selectionsorta je: %f\n", measure(quicksort, niz, n));
	}
}
