1. Laboratorijska vježba

Nizovi, strukture i alociranje

Napisati iduće funkcije koje rade sa nizom brojeva:

int* podniz(int *niz, int start, int stop) – vraća novi niz koji je kopija dijela niza od indeksa start do indeksa stop.

int* filtriraj(int *niz, int n, int th, int *nth) – vraća novi niz koji sadrži brojeve iz originalnog niza koji su manji od th. Originalni niz ima dužinu n. Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth. 

int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela i stvara kopije prvog i drugog dijela. Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio.

Deklarirati strukturu Tocka koja sadrži dva člana: x i y (oba su float). Deklarirati strukturu Poligon koja se sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i broj vrhova n. Napisati funkcije za rad sa poligonima:

Poligon* novi_poligon(float *niz_x, float *niz_y, int n) – prima niz x i y koordinata i stvara novi poligon koji će kao vrhove imati parove brojeva iz nizova. Nizovi su dužine n (≥ 3).

Tocka** pozitivni(Poligon *p, int *np) – funkcija vraća niz pokazivača na vrhove poligona kojima su obje koordinate pozitivne. Broj elemenata u nizu će biti spremljen u np parametar.      
