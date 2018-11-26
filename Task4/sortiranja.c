#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>
#define MEDIAN(a, b, c)((((a)-(b))*((b)-(c))) > (-1) ? (b) : (((a-b)*(a-c)) < (1) ? (a) : (c)))
#include "sortiranja.h"

void swap(int *a, int *b)
{
 int tmp = *a;
 *a = *b;
 *b = tmp;
}

// globalna n_min varijabla
int n_min;

//globalna boolean varijabla
bool choose_pivot = false;

// generiranje i ispis niza
int* generate(int n) {
	int i;
	int *niz = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		niz[i] = rand() % 1000;
	return niz;
}

void print(int *niz, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}
	printf("\n");
}

// selection sort
void selectionsort(int *niz, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		int j, tmp, maxi = i;
		for (j = i + 1; j < n; j++) {
			if (niz[j] < niz[maxi])
				maxi = j;
		}

		tmp = niz[maxi];
		niz[maxi] = niz[i];
		niz[i] = tmp;
	}
}

// insertion sort
void insertionsort(int *niz, int n) {
	int i;
	for (i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && niz[j - 1] > niz[j]) {
			int tmp;
			tmp = niz[j-1];
			niz[j - 1] = niz[j];
			niz[j] = tmp;
			j--;
		}
	}
}

// quick sort
int partition(int *niz, int n) {
	int l, r;
	l = 1;
	r = n - 1;
	
	if (choose_pivot == 1) {
		if (MEDIAN(niz[0], niz[n / 2], niz[n - 1]) == niz[n / 2]) swap(&niz[0], &niz[n / 2]);
		else if (MEDIAN(niz[0], niz[n / 2], niz[n - 1]) == niz[n - 1]) swap(&niz[0], &niz[n - 1]);
	}

	while (l < r) {
        (niz[r] >= niz[0]) ? (r--) : ((niz[l] < niz[0]) ? (l++) : (swap(&niz[l], &niz[r])));
	}
	if (niz[0] < niz[r]) return 0;
	else {
	    swap(&niz[r], &niz[0]);
	    return r;
	}

void quicksort(int *niz, int n) {
    if (n < n_min) {
        selectionsort(niz, n);
    } else {
        if (n < 2) return;
        int pi = partition(niz, n);
        quicksort(niz, pi);
        quicksort(niz + pi + 1, n - pi - 1);
    }
}

// merge sort
void merge(int *niz, int *niza, int na, int *nizb, int nb) {
	// implemntirati merge funkciju
}

// alocira i vraæa kopiju niza
int* duplicate(int *niz, int n) {
	int i;
	int *novi = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		novi[i] = niz[i];
	}
	return novi;
}

void mergesort(int *niz, int n) {
	// implementirati
}

// mjerenje vremena izvoðenja funkcije sortiranja
double measure(void(*sort)(int *niz, int n), int *niz, int n) {
	int start_time = clock();
	sort(niz, n);
	int end_time = clock();
	return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}
