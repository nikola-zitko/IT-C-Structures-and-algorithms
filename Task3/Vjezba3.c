#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SMALLER(x, y) (((x) > (y)) ? (x) : (y))

int cmpfunc(const void * a, const void * b) {
	return (*(int*)a - *(int*)b);
}

int* generiraj(int n) {
	int *niz = (int*)malloc(n * sizeof(int));
	niz[0] = rand() % 3;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 3;
	}
	return niz;
}


void shuffle(int *niz, int n) {
	for (int i = 0; i < n; i++) {
		int ia = i;
		int ib = rand() % n;
		int tmp = niz[ia];
		niz[ia] = niz[ib];
		niz[ib] = tmp;
	}
}

void presjek(int* nizA, int* nizB, int n1, int n2) {
	clock_t start_t, end_t;
	double total_t;
	start_t = clock();
	
	int n = SMALLER(n1, n2);
	int* presjekNiza = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (nizA[i] == nizB[j]) presjekNiza[--n] = nizA[i];
		}
	}
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Ukupno vrijeme u sekundama: %f\n", total_t);
}

void presjek_sortiran(int* nizA, int* nizB, int n1, int n2) {
	clock_t start_t, end_t;
	double total_t;
	start_t = clock();

	int n = SMALLER(n1, n2);
	int* presjekNiza = (int*)malloc(n * sizeof(int));

	int* presjek;
	for (int i = 0; i < n; i++) {
		presjek = (int*)bsearch(&nizA[i], nizB, n, sizeof(int), cmpfunc);
		if (presjek != NULL) {
			presjekNiza[--n] = *presjek;
		}
	}
	
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Ukupno vrijeme u sekundama: %f\n", total_t);
}

void presjek_sortiran_qsort(int* nizA, int* nizB, int n1, int n2) {
	clock_t start_t, end_t;
	double total_t;
	start_t = clock();

	int n = SMALLER(n1, n2);
	int* presjekNiza = (int*)malloc(n * sizeof(int));

	qsort(nizB, n, sizeof(int), cmpfunc);

	int* presjek;

	for (int i = 0; i < n; i++) {
		presjek = (int*)bsearch(&nizA[i], nizB, n, sizeof(int), cmpfunc);
		if (presjek != NULL) {
			presjekNiza[--n] = *presjek;
		}
	}

	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Ukupno vrijeme u sekundama: %f\n", total_t);
}

void main() {
	
	srand(time(NULL));
	int* nizA;
	int* nizB;
	int n1, n2;

	printf("Unesi duljinu prvog niza: ");
	scanf("%d", &n1);
	printf("Unesi duljinu drugog niza: ");
	scanf("%d", &n2);

	nizA = generiraj(n1);
	shuffle(nizA, n1);
	
	nizB = generiraj(n2);
	shuffle(nizB, n2);

	//izracun presjeka dva ne sortirana niza
	//printf("Izracun presjeka dva ne sortirana niza: \n");
	//presjek(nizA, nizB, n1, n2);

	//izracun presjeka sortiranog i nesortiranog
	printf("Izracun presjeka sortiranog i nesortiranog: \n");
	nizA = generiraj(n1);
	shuffle(nizA, n1);
	nizB = generiraj(n2);
	presjek_sortiran(nizA, nizB, n1, n2);

	// -//- sa qsort
	printf("Izracun presjeka sortiranog i nesortiranog sa qsort: \n");
	nizA = generiraj(n1);
	shuffle(nizA, n1);
	nizB = generiraj(n2);
	shuffle(nizB, n2);
	presjek_sortiran_qsort(nizA, nizB, n1, n2);

}
