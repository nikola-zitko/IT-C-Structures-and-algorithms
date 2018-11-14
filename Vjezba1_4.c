
#include<stdio.h>
#include<stdlib.h>

typedef struct Tocka {
	float x;
	float y;
}Tocka;

typedef struct Poligon {
	Tocka* nizVrhova;
	int n;
}Poligon;


Poligon* novi_poligon(float* niz_x, float* niz_y, int n) {
	Poligon* NoviPoligon = (Poligon*)malloc(sizeof(Poligon));
	Tocka* NoviNizVrhova = (Tocka*)malloc(n * sizeof(Tocka));

	NoviPoligon->n = n;
	for (int i = 0; i < NoviPoligon->n; i++) {
		NoviNizVrhova[i].x = niz_x[i];
		NoviNizVrhova[i].y = niz_y[i];
	}
	
	NoviPoligon->nizVrhova = NoviNizVrhova;

	return NoviPoligon;
}


Tocka** pozitivni(Poligon* p) {
	
	int brojac = 0;
	int j = 0;
	for (int i = 0; i < (p->n); i++) {
		if (p->nizVrhova[i].x > 0 && p->nizVrhova[i].y > 0) {
			brojac++;
		}
	}

	Tocka** PozNizVrhova = (Tocka**)malloc(brojac * sizeof(Tocka*));
	
	for (int i = 0; i < (p->n); i++) {
		if ((p->nizVrhova[i].x > 0) && (p->nizVrhova[i].y > 0)) {
			PozNizVrhova[j] = &(p->nizVrhova[i]);
			j++;
		}
	}
	return PozNizVrhova;
}



void main() {
	float niz_x[] = { -1, 5, 10, 15, 20 };
	float niz_y[] = { 20, 15, -10, 5 ,1 };
	int n = 5;

	Poligon* NovPol = novi_poligon(niz_x, niz_y, n);
	/*
	for (int i = 0; i < n; i++) {
		printf("%.2f %.2f\n", NovPol->nizVrhova[i].x, NovPol->nizVrhova[i].y);
	}
	printf("\n");
	*/


	Tocka** NovNizPoz = pozitivni(NovPol);
	
	for (int i = 0; i < 3; i++) {
		printf("%.2f %.2f \n", NovNizPoz[i]->x, NovNizPoz[i]->y);
	}
	

}