3. Laboratorijska vježba

Mjerenje vremena izvođenja algoritma (a posteriori)

Napisati iduće funkcije:

•	generiraj(n) – generira niz dužine n sa slučajnim elementima (svaki element se pojavljuje samo jednom u nizu)
•	shuffle(skup) – miješa elemente u nizu skup
•	presjek(skupA, skupB) – funkcija računa presjek dva skupa
•	presjek_sortiran(skupA, skupB) – funkcija računa presjek dva skupa, gdje je skupB sortirani niz tako da se funkcija oslanja na upotrebu upotrebom bsearch() funkcije (iz stdlib.h)


Izmjeriti vrijeme  izvođenja funkcija za iduća tri algoritma:
•	izračun presjeka dva nesortirana niza
•	izračun presjeka nesortiranog i sortiranog niza 
•	izračun presjeka nesortiranog i sortiranog niza s tim da u vrijeme izvođenja ulazi i sortiranje drugog niza sa qsort()

Potrebno je izmjeriti vremena za različite dužine niza (da bi se promatrao rast vremena izvođenja). U prvom slučaju će se fiksirati duljina prvog niza na 30000 elemenata, a duljina drugog niza će varirati od 10000 do 50000 elemenata sa korakom od 5000. U drugom slučaju će se varirati duljina prvog niza, a duljina drugog niza će biti fiksirana.
Za dužinu (alociranje) niza koji će sadržati presjek nizova se može uzeti veća dužina od dva primljena niza. Ispisati vrijeme izvođenja za sve kombinacije dužina (ukupno ih ima 16). 
Procijeniti vremensku složenost O(f(NA, NB)) za svaki algoritam analitički i provjeriti da li odgovaraju vremenima izvođenja.
Za mjerenje izvođenja pojedinog algoritma koristiti funkciju clock(), po potrebi uvećati sve duljine nizova pet do deset puta (da bi se dobila različita vremena u ovisnosti o duljini niza).
