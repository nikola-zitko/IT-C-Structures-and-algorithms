/*
#include<stdio.h>
#include<stdlib.h>

int* podniz(int* niz, int start, int stop) {
	int duljina = stop - start;
	int j = 0;
	int* niz2=(int*)malloc(duljina*sizeof(int));
	for (int i = start; i < stop; i++) {
		niz2[j] = niz[i];
		j++;
	}
	return niz2;
}




void main() {
	int niz[] = { 1,2,3,4,5,6,7,8,9,10 };
	int start = 3;
	int stop = 7;
	int* niz2 = podniz(niz, start, stop);
	
	for (int i = 0; i < 4; i++) {
		printf("%d\n", niz2[i]);
	}
	
	free(niz2);


}
*/
