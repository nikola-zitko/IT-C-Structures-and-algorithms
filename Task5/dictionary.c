#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

Dictionary create () {
    Dictionary dict = NULL;
    dict = (Dictionary)malloc(sizeof(Word));

    dict->count = 0;
    dict->word = NULL;
    dict->next = NULL;

    return dict;
}

void add(Dictionary dict, char *str) {

    while (dict->next != NULL) {
        // ukoliko postoji rijec koja je jednaka parametru str, count++
        if(strcmp(dict->next->word, str) == 0){
            (dict->next->count)++;
            return;
        }
        // provjeravamo je li neka rijec veca od od parametra str ako je veca, str ubacujemo u listu ispred toga clana
        if(strcmp(dict->next->word, str) > 0){
            Dictionary tmp = (Dictionary)malloc(sizeof(Word));
            tmp->count = 1;
            tmp->word = strdup(str);
            tmp->next = dict->next;
            dict->next = tmp;
            return;
        }
        dict = dict->next;
    }
    // ako se rijec ne pojavi do kraja rjecnika, znaci da nema vece rijeci od nje i dodaje se na rep liste
    Dictionary tmp = (Dictionary)malloc(sizeof(Word));

    tmp->count = 1;
    tmp->word = strdup(str);
    tmp->next = dict->next;

    tmp->next = NULL;
    dict->next = tmp;
}

void print(Dictionary dict) {
    Dictionary current = dict->next;

    while (current != NULL) {
        printf("%s    \t%d\n", current->word, current->count);
        current = current->next;
    }
}

void destroy(Dictionary dict) {
    Dictionary current = dict->next;
    Dictionary next;

    while (current != NULL) {
        next = current->next;
        // oslobadjamo i clana liste "current" i njegov "current->word" gdje se je duplicirao string sa strdup() pa i tu memoriju treba zasebno osloboditi
        free(current->word);
        free(current);
        current = next;
    }
    dict = NULL;
}

int filter(Word* w) {
    if (strlen(w->word) > 3 && w->count > 5 && w->count < 10) return 1;
    else return 0;
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Dictionary)) {
    Dictionary current = indict;
    Dictionary next = indict->next;

    while (next != NULL) {
        if (!filter(next)) {
            current->next = next->next;
            free(next->word);
            free(next);
            next = current->next;
        } else {
            current = next;
            next = current->next;
        }
    }
    return indict;
}
