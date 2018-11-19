3. Laboratorijska vježba

Algoritmi sortiranja 

U datoteci sortiranja.c se nalaze različite implementacije algoritma za sortiranje (insertion, selection i quick sortiranje). Uz to ima i nekoliko pomoćnih funkcija (za generiranje niza, mjerenje izvođenja funkcije sortiranja i neke pomoćne funkcije). Potrebno je napraviti projekt sa main.c i sortiranja.c datotekama. U projekt dodati i implementirati sortiranja.h koja će sadržati sve potpise funkcija koje će se koristiti u main.c .

U funkciju partition je potrebno dodati odabir pivota tako da se provjere vrijednosti na indeksima 0, n/2 i n-1 i uzme se srednja vrijednost među njima (medijan). Tu vrijednost se zamijeni sa vrijednošću na indeksu 0. Izmjeriti vremena izvođenja quicksorta sa i bez odabira pivota za slučajni i za sortirani niz dužine n = [1000 .. 10000]. U sortiranja.c i sortiranja.h dodati globalnu boolean varijablu choose_pivot tako da se biranje pivota može isključiti/uključiti iz main funkcije po potrebi.

Izmijeniti quicksort funkciju tako da za neki n_min (dužina primljenog niza) zove selectionsort ili insertionsort funkciju umjesto quicksort funkcije. Ideja je da se za vrlo kratke nizove poziva „slabiji“ algoritam sortiranja i da ukupno izvođenje sortiranja bude što brže. Pronaći optimalni n_min mjerenjem vremena izvođenja za različite vrijednosti u rasponu [0 .. 200]. Da bi mijenjali n_min, potrebno je u sortiranja.c i sortiranja.h dodati globalnu deklarirati globalnu varijablu n_min koja će se mijenjati u main funkciji prije poziva prilagođenog quicksorta. 


Dodatno:
Implementirati merge i mergesort funkcije. Pomoćne nizove možete alocirati/oslobađati po potrebi. Izmjeriti vrijeme izvođenja implementirane funkcije za slučajni i sortirani niz dužine n = [1000 .. 10000].

Prilikom testiranja se može dogoditi prevelik broj rekurzija (quicksort na već sortiranom nizu bez biranja pivota) pa je potrebno povećati stack size u postavkama projekta: Properites / Linker / System / Stack Reserve Size postaviti na 16000000.
