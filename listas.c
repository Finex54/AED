#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "matriz.h"
#include "listas.h"



struct _lista {
  matriz* this;
  struct _lista *prox;
};

struct _lance{
	int linha, coluna;
	struct _lance *prox;
};


lista *iniLista(void)
{

  return NULL;
}

lance *inilance(void)
{

  return NULL;
}


lista *getProxElementoLista(lista *m)
{

  return m -> prox;
}

lance *getProxLanceLista(lance *m)
{

  return m -> prox;
}


matriz* getItemLista (lista *m)
{

  return m -> this;
}



/******************************************************************************
 * criaNovoNoLista ()
 *
 * Arguments: nome - Item to save in list node
 * Returns: t_lista  *
 * Side-Effects: none
 *
 * Description: creates and returns a new node that can later be added to the
 *              list
 *
 *****************************************************************************/
lista  *criaNovoNoLista (lista* lm, matriz* this, int *err)
{
  lista *novoNo;

  novoNo = (lista*) malloc(sizeof(lista));
  if(novoNo!=NULL) {

    novoNo->this = this;
    novoNo->prox = lm;
    lm = novoNo;
    *err = 0;
  } else {
    *err = 1;
  }
  return lm;
}

/******************************************************************************
 * criaNovoNoLance ()
 *
 * Arguments: nome - Item to save in list node
 * Returns: lance  *
 * Side-Effects: none
 *
 * Description: creates and returns a new node that can later be added to the
 *              list
 *
 *****************************************************************************/
lance  *criaNovoNoLance (lance* lm, int linha, int coluna)
{
  lance *novoNo;

  novoNo = (lance*) malloc(sizeof(lance));
  if(novoNo!=NULL) {

    novoNo->linha = linha;
	novoNo->coluna = coluna;
    novoNo->prox = lm;
    lm = novoNo;
  }
  return lm;
}


void printReverse(lance* head, FILE *fp)
{
    /* Base case  */
    if (head == NULL)
       return;
 
    /* print the list after head node*/
    printReverse(head->prox,fp);
 
    /*After everything else is printed, print head*/
    fprintf(fp,"%d %d\n", head->linha, head->coluna);
}


/******************************************************************************
 * libertaLista ()
 *
 * Arguments: lm - pointer to list
 * Returns:  (void)
 * Side-Effects: frees space occupied by list items
 *
 * Description: free list
 *
 *****************************************************************************/
void libertaLista(lista *lm, void freeItem(matriz*)) 
{
  lista *aux, *newhead;  /* auxiliar pointers to travel through the list */

  for(aux = lm; aux != NULL; aux = newhead) {
    newhead = aux->prox;
    freeItem(aux->this);
    free(aux);
  }

  return;
}