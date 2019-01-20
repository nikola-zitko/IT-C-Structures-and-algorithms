#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	return NULL;
}

void AddNode(BSTree *bst, char *word)
{
	// Rekurzivno se trazi mjesto za novi cvor u stablu. Ako rijec postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivac.

	if (*bst == NULL) {
		BSTree tmp = (BSTree)malloc(sizeof(Node));
		tmp->left = tmp->right = NULL;
		tmp->word = word;
		*bst = tmp;
		return;
	}

	int rez = strcmp(word, (*bst)->word);
	if ((*bst)->left == NULL && (*bst)->right == NULL) {
		BSTree tmp = (BSTree)malloc(sizeof(Node));
		tmp->left = tmp->right = NULL;
		tmp->word = word;

		if (rez > 0)
			(*bst)->right = tmp;
		else if (rez < 0)
			(*bst)->left = tmp;
		return;
	}

	if (rez > 0)
		AddNode(&((*bst)->right) ,word);
	else if (rez < 0)
		AddNode(&((*bst)->left), word);
}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se prona�la najdu�a grana (visina stabla).
	if (bst == NULL)
		return 0;
	int prvi = BSTHeight(bst->left), drugi = BSTHeight(bst->right);
	if (prvi > drugi)
		return 1 + prvi;
	return 1 + drugi;
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rije�i u stablu na ekran po abecednom redu.
	// In-order �etnja po stablu (lijevo dijete, �vor, desno dijete)
	if (bst == NULL)
		return;

	PrintBSTree(bst->left);
	puts(bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rije� po rije� iz stabla u tekstualnu datoteku. Rije�i su odvojene razmakom.
	// Pre-order �etnja po stablu (trenutni �vor pa djeca)
	if (bst == NULL)
		return;

	fprintf(fd, "%s\n", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	// Bri�e stablo (string word i sam �vor) iz memorije.
	// Post-order �etnja po stablu (prvo djeca pa trenutni �vor)
	if (bst == NULL)
		return;

	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
	// U�itava rije� po rije� iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rije� duplicirati sa strdup().
	char *buffer[1024];
	BSTree bst = NewBSTree();

	while (fgets(buffer, 1024, fd) != NULL)
		AddNode(&bst, _strdup(buffer));
	return bst;
}
