#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "matriz.h"
#include "listas.h"
#include "graph.h"


/******************************************************************************
 *  PrintList ()
 *
 * Arguments:  lm - pointer to the list
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: print the list of matrices. 
 *****************************************************************************/
void PrintList(lista *lm){

  lista *aux;
  matriz *mA;

  printf("--> Printing items saved in memory...\n");

  aux = lm;
  while( aux!= NULL ){
    mA = (matriz *) getItemLista(aux);
    PrintMatrix( mA );
    aux = getProxElementoLista(aux);
  }

  printf( "...[DONE]\n" );

  return;

}





/******************************************************************************
 * Usage ()
 *
 * Arguments: nomeProg - name of executable
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: message function when arguments are missing
 *
 *****************************************************************************/
void Usage(char *nomeProg)
{
  printf("Usage: %s [filename]\n",
      nomeProg);

  exit(0);

}





void VarianteUm(matriz* mA, FILE *fp)
{

  int contagem = countIslands(mA, GetMatrixElement(mA, GetMatrixLinhas(mA) - GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA) - 1));
  printf("\n\nContagem = %d\n\n", contagem);
  fprintf(fp, "%d %d %d %d %d\n%d\n\n", GetMatrixLinhas(mA), GetMatrixColunas(mA), GetVariante(mA), GetMatrixColunaCluster(mA), GetMatrixLinhaCluster(mA), contagem);


}


void VarianteDois(matriz* mA, FILE *fp)
{
    int pI, pJ;
/*
COMPUTAR A MATRIZ
*/


  fprintf(fp, "%d %d %d %d %d\n", GetMatrixLinhas(mA), GetMatrixColunas(mA), GetVariante(mA), GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA));


  for( pI = 0; pI < GetMatrixLinhas(mA) ; pI++ ){
    for( pJ = 0; pJ<GetMatrixColunas(mA) ; pJ++ )
      fprintf( fp, "%d ", GetMatrixElement( mA, pI, pJ ) );
    fprintf(fp, "\n" );
  }

  fprintf(fp, "\n");



}


/**********************************************
*
*CALCULA: FAZ VARIANTE 1 OU VARIANTE 2
*
*
**********************************************/


void Calcula(lista *lm, FILE *fp)
{

lista *aux=NULL;

for(aux=lm; aux!=NULL; aux=getProxElementoLista(aux))
{
  int variante = GetVariante(getItemLista(aux));
  if (variante==1)
    VarianteUm(getItemLista(aux), fp);

  if(variante==2)
    VarianteDois(getItemLista(aux), fp);

}

}







/*****************************************************************************
*verifica_extensao()
*
*Argumentos: Nome do ficheiro de entrada
*Retorna 0 se a extensão do ficheiro estiver correta e retorna 1 caso contrário
*
*****************************************************************************/

int verifica_extensao(char* filename)
{
	int size = strlen (filename);
	return ( filename[size-1]=='z' && filename[size-2]=='u' && filename[size-3]=='p' && filename[size-4]=='.') ? 0:1;
}


/******************************************************************************
*
*EscreveFileSaida()
*
*Não retorna nada
*Cria o ficheiro .moves
*
******************************************************************************/

/*ALTERAR ENTRADAS PARA RECEBER A LISTA E A MATRIZ A ESCREVER MAIS A PONTUAÇÃO*/

void EscreveFileSaida(char *nomeEntrada, lista *lm)
{

  char ext[6] = "moves";
  char nomeSaida[100];
  int i=0;
  FILE *fpOut;
  
  for(i=0; i<(strlen(nomeEntrada)-3); i++)
    nomeSaida[i] = nomeEntrada[i];

  nomeSaida[i] = '\0';

  strcat(nomeSaida, ext);

  printf("\n\n %s \n\n", nomeSaida);  /*APENAS PARA TESTE*/

  fpOut=fopen(nomeSaida, "w");


  Calcula(lm, fpOut);



  fclose(fpOut);

}






int main(int argc, char *argv[])
{
	char *nomeficheiro;
  	FILE *fp_entrada;
  	lista *lista_matrizes;

  	/*
  		CASO A EXECUÇÃO DO FICHEIRO NÃO SEJA REALIZADA
  		CORRETAMENTE
  	*/
  	if( argc < 2 )
    	Usage( argv[0] );

	nomeficheiro = argv[1];

	if(verifica_extensao(nomeficheiro)!=0)
	{
		printf("Extensão do ficheiro errada\n");
		exit(0);
	}

  	fp_entrada = fopen( nomeficheiro, "r" );

  	/*
  	VERIFICA SE NÃO HÁ ERROS NA ABERTURA DO FICHEIRO
  	*/
  	if( fp_entrada == NULL ){
    printf( "Open error of the input file\n" );
    exit(0);
  }

  lista_matrizes = saveMatrices( fp_entrada );

  /*APENAS PARA TESTE*/
    PrintList( lista_matrizes);





    EscreveFileSaida(nomeficheiro,lista_matrizes);


  	/*Liberta a memória da lista*/
    libertaLista( lista_matrizes, FreeItem );


  	/*Fecha o ficheiro*/
  	fclose(fp_entrada);

    exit(0);
}