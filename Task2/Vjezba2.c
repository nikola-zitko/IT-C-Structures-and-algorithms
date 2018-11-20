#include<stdio.h>
#include<stdlib.h>

typedef struct VrhTrokuta {
	float x1T, y1T, z1T;
	float x2T, y2T, z2T;
	float x3T, y3T, z3T;
}VrhTrokuta;

typedef struct Trokut {
	float xN, yN, zN;
	VrhTrokuta Vrhovi;
	unsigned short bojaTrokuta;
}Trokut;

typedef struct Objekt3D {
	unsigned int brojTrokuta;
	Trokut* NizTrokuta;
}Objekt3D;


Objekt3D* ReadFromFile(FILE* fp, Objekt3D* Objekt) {

	
	fseek(fp, 80, SEEK_SET);

    	fread(&Objekt->brojTrokuta, sizeof(unsigned int), 1, fp);
    	int n = Objekt->brojTrokuta;


	Objekt->NizTrokuta = malloc(sizeof(Trokut)*n);

	for (int i = 0; i < n; i++) {
		fread(&Objekt->NizTrokuta[i].xN, sizeof(float), 1, fp);
		fread(&Objekt->NizTrokuta[i].yN, sizeof(float), 1, fp);
		fread(&Objekt->NizTrokuta[i].zN, sizeof(float), 1, fp);

		fread(&Objekt->NizTrokuta[i].Vrhovi.x1T, sizeof(float), 1, fp);
		fread(&Objekt->NizTrokuta[i].Vrhovi.y1T, sizeof(float), 1, fp);
		fread(&Objekt->NizTrokuta[i].Vrhovi.z1T, sizeof(float), 1, fp);
		fread(&Objekt->NizTrokuta[i].Vrhovi.x2T, sizeof(float), 1, fp);
		fread(&Objekt->NizTrokuta[i].Vrhovi.y2T, sizeof(float), 1, fp);
		fread(&Objekt->NizTrokuta[i].Vrhovi.z2T, sizeof(float), 1, fp);
		fread(&Objekt->NizTrokuta[i].Vrhovi.x3T, sizeof(float), 1, fp);
		fread(&Objekt->NizTrokuta[i].Vrhovi.y3T, sizeof(float), 1, fp);
		fread(&Objekt->NizTrokuta[i].Vrhovi.z3T, sizeof(float), 1, fp);

		fread(&Objekt->NizTrokuta[i].bojaTrokuta, sizeof(unsigned short), 1, fp);
	}

	return Objekt;
}

void WriteToFile(FILE* fwp, Objekt3D* Objekt) {
	char buffer[80]={0};
	
	fwrite(buffer, 1, 80, fwp);
    	int n = Objekt->brojTrokuta;
	fwrite(&n, 4, 1, fwp);
	for (int i = 0; i < n; i++) {
		fwrite(&Objekt->NizTrokuta[i].xN, sizeof(float), 1, fwp);
		fwrite(&Objekt->NizTrokuta[i].yN, sizeof(float), 1, fwp);
		fwrite(&Objekt->NizTrokuta[i].zN, sizeof(float), 1, fwp);

		fwrite(&Objekt->NizTrokuta[i].Vrhovi.x1T, sizeof(float), 1, fwp);
		fwrite(&Objekt->NizTrokuta[i].Vrhovi.y1T, sizeof(float), 1, fwp);
		fwrite(&Objekt->NizTrokuta[i].Vrhovi.z1T, sizeof(float), 1, fwp);
		fwrite(&Objekt->NizTrokuta[i].Vrhovi.x2T, sizeof(float), 1, fwp);
		fwrite(&Objekt->NizTrokuta[i].Vrhovi.y2T, sizeof(float), 1, fwp);
		fwrite(&Objekt->NizTrokuta[i].Vrhovi.z2T, sizeof(float), 1, fwp);
		fwrite(&Objekt->NizTrokuta[i].Vrhovi.x3T, sizeof(float), 1, fwp);
		fwrite(&Objekt->NizTrokuta[i].Vrhovi.y3T, sizeof(float), 1, fwp);
		fwrite(&Objekt->NizTrokuta[i].Vrhovi.z3T, sizeof(float), 1, fwp);

		fwrite(&Objekt->NizTrokuta[i].bojaTrokuta, sizeof(unsigned short), 1, fwp);
	}


}


void WriteToTextFile(FILE* fwtp, Objekt3D* Objekt) {
	
	fprintf(fwtp, "solid OpenSCAD_Model\n");
	
	int n = Objekt->brojTrokuta;
	for (int i = 0; i < n; i++) {
		fprintf(fwtp, "facet normal %f %f %f\n", Objekt->NizTrokuta[i].xN, Objekt->NizTrokuta[i].yN, Objekt->NizTrokuta[i].zN);
		fprintf(fwtp, "\t outer loop\n");
		fprintf(fwtp, "\t\t vertex %f %f %f\n", Objekt->NizTrokuta[i].Vrhovi.x1T, Objekt->NizTrokuta[i].Vrhovi.y1T, Objekt->NizTrokuta[i].Vrhovi.z1T );
		fprintf(fwtp, "\t\t vertex %f %f %f\n", Objekt->NizTrokuta[i].Vrhovi.x2T, Objekt->NizTrokuta[i].Vrhovi.y2T, Objekt->NizTrokuta[i].Vrhovi.z2T );
		fprintf(fwtp, "\t\t vertex %f %f %f\n", Objekt->NizTrokuta[i].Vrhovi.x3T, Objekt->NizTrokuta[i].Vrhovi.y3T, Objekt->NizTrokuta[i].Vrhovi.z3T );
		fprintf(fwtp, "\t endloop\n");
		fprintf(fwtp, "endfacet\n\n");
	}
	fprintf(fwtp, "endsolid OpenSCAD_Model\n");

}

void DeleteObjekt3D(Objekt3D* Objekt) {
	free(Objekt->NizTrokuta);
	free(Objekt);
}


void main() {

	FILE* fp;
	FILE* fwp;
	FILE* fwtp;
	Objekt3D* ObjektMal = (Objekt3D*)malloc(sizeof(Objekt3D));
	fp = fopen("primjerbin.stl", "rb");
	if (fp == NULL) {
		printf("File ne postoji. \n");
	}
	else {
		ObjektMal = ReadFromFile(fp, ObjektMal);
	}
	fclose(fp);

	fwp = fopen("binarniSTL.stl", "wb");
	if (fwp == NULL) {
		printf("File ne postoji. \n");
	}
	else {
		WriteToFile(fwp, ObjektMal);
	}
	fclose(fwp);


	fwtp = fopen("tekstualniSTL.stl", "wt");
	if (fwtp == NULL) {
		printf("File ne postoji. \n");
	}
	else {
		WriteToTextFile(fwtp, ObjektMal);
	}
	fclose(fwtp);
}
