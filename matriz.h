
#ifndef _MATRIZ_H
#define _MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listas.h"

typedef struct _matriz matriz;



lista *saveMatrices( FILE *fm );
matriz *NewMatrix(int linhas, int colunas, int variante, int coluna_cluster, int linha_cluster);
void SetMatrixElement(matriz *mA, int pI, int pJ, float value);
lista  *criaNovoNoLista (lista* lm, matriz* this, int *err);
matriz* getItemLista (lista *m);
void PrintMatrix(matriz *mA);
int GetMatrixElement(matriz *mA, int pI, int pJ);
void FreeMatrix(matriz *mA);
void FreeItem( matriz* this);
void libertaLista(lista *lm, void freeItem(matriz*));
int GetMatrixColunas(matriz *mA);
int GetMatrixLinhas(matriz *mA);
int** GetMatrix(matriz *mA);
int GetMatrixLinhaCluster(matriz *mA);
int GetMatrixColunaCluster(matriz *mA);
int GetVariante(matriz *mA);
int VerificaPosicao(matriz *mA, int row, int col, int **visited);
void DFS(matriz *mA, int row, int col, int **visited, int value, int variante);
int ContaCluster(matriz *mA, int value, int variante);
void AjusteGravitico(matriz *mA);
void PuxarParaCima(matriz *mA, int linha, int coluna);
void PuxarParaEsquerda(matriz *mA, int coluna);


#endif
