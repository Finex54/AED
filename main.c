#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "matriz.h"
#include "listas.h"


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

  /*printf( "...[DONE]\n" );*/

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


/*


void VarianteUm(matriz* mA, FILE *fp)
{

  int contagem = ContaCluster(mA, GetMatrixElement(mA, GetMatrixLinhas(mA) - GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA) - 1), 1);
  printf("\n\nContagem = %d\n\n", contagem);
  fprintf(fp, "%d %d %d %d %d\n%d\n\n", GetMatrixLinhas(mA), GetMatrixColunas(mA), GetVariante(mA), GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA),contagem);


}
*/



/* ---------------------------------------------------REMOVER?--------------------------------------------------------------------------------------
void VarianteDois(matriz* mA, FILE *fp)
{
    int pI, pJ;
  
  ContaCluster(mA, GetMatrixElement(mA, GetMatrixLinhas(mA) - GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA) - 1), 2);
  AjusteGravitico(mA);

  fprintf(fp, "%d %d %d %d %d\n", GetMatrixLinhas(mA), GetMatrixColunas(mA), GetVariante(mA), GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA));


  for( pI = 0; pI < GetMatrixLinhas(mA) ; pI++ ){
    for( pJ = 0; pJ<GetMatrixColunas(mA) ; pJ++ )
      fprintf( fp, "%d ", GetMatrixElement( mA, pI, pJ ) );
    fprintf(fp, "\n" );
  }

  fprintf(fp, "\n");



}

void VarianteX(matriz *mA, FILE *fp)
{
  fprintf(fp, "%d %d %d %d %d\n\n", GetMatrixLinhas(mA), GetMatrixColunas(mA), GetVariante(mA), GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA));



}

-------------------------------------------------------------------------------------------------------------------------------------------------------
*/



/**********************************************
*
*CALCULA: FAZ VARIANTE 1 OU VARIANTE 2
*
*
**********************************************/


void Calcula(lista *lm, FILE *fp)
{

lista *aux=NULL;
int pI, pJ;


aux=lm;
lance* lista_lances=inilance();
lance* aux_lance=NULL;

if (aux==NULL)
  return;

Calcula(getProxElementoLista(aux),fp);


  matriz *mA = getItemLista(aux);
  int nr_lances=0;
  int variante = GetVariante(mA);



  /*if(GetMatrixColunaCluster(mA)>GetMatrixColunas(mA)||GetMatrixColunaCluster(mA)<1|| GetMatrixLinhaCluster(mA)>GetMatrixLinhas(mA)||GetMatrixLinhaCluster(mA)<1)
    fprintf(fp, "%d %d %d %d %d\n\n", GetMatrixLinhas(mA), GetMatrixColunas(mA), GetVariante(mA), GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA));            ALTERAR */

/*
  else*/ if (variante==-1) /*VARIANTE UM OCORRE COM A LEITURA DO VALOR '-1' NO FICHEIRO DE ENTRADA*/
    {
     int contagem = 0, contagem_aux=0;
     fprintf(fp, "%d %d %d \n", GetMatrixLinhas(mA), GetMatrixColunas(mA), GetVariante(mA));


LANCES:  for(pI=GetMatrixLinhas(mA)-1; pI > 0; pI--){
          for(pJ=GetMatrixColunas(mA); pJ > 0; pJ--){
			 
            SetMatrixCluster(mA, GetMatrixLinhas(mA)-pI, pJ);
            
            contagem_aux=contagem;	/* PARA VERIFICAR SE HÁ ALTERAÇÃO DA PONTUAÇÃO*/
              contagem= contagem + ContaCluster(mA, GetMatrixElement(mA, GetMatrixLinhas(mA) - GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA) - 1), 2);
			  
	  
            if(contagem != contagem_aux)
            {
				AjusteGravitico(mA);
				nr_lances++;
				lista_lances=criaNovoNoLance (lista_lances, GetMatrixLinhaCluster(mA),GetMatrixColunaCluster(mA));
				AjusteGravitico(mA);
			  
				
				goto LANCES;
            }
				
			

          }

        }


        fprintf(fp, "%d %d\n", nr_lances, contagem);
		printReverse(lista_lances, fp);
		
	/*------------------------------------------------------LIBERTAR LISTA DE LANCES-------------------------------------------------------------*/
		
while ((aux_lance = lista_lances) != NULL) { 
    lista_lances = getProxLanceLista(lista_lances);
    free (aux_lance);
}


  }


  else if(variante==2)
    {ContaCluster(mA, GetMatrixElement(mA, GetMatrixLinhas(mA) - GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA) - 1), 2);
  AjusteGravitico(mA);

  /*fprintf(fp, "%d %d %d %d %d\n", GetMatrixLinhas(mA), GetMatrixColunas(mA), GetVariante(mA), GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA));*/


  /*for( pI = 0; pI < GetMatrixLinhas(mA) ; pI++ ){
    for( pJ = 0; pJ<GetMatrixColunas(mA) ; pJ++ )
      fprintf( fp, "%d ", GetMatrixElement( mA, pI, pJ ) );
    fprintf(fp, "\n" );
  }*/

  /*fprintf(fp, "\n");*/}

  /*else 
    fprintf(fp, "%d %d %d %d %d\n\n", GetMatrixLinhas(mA), GetMatrixColunas(mA), GetVariante(mA), GetMatrixLinhaCluster(mA), GetMatrixColunaCluster(mA));*/
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
		/*printf("Extensão do ficheiro errada\n");*/
		exit(0);
	}

  	fp_entrada = fopen( nomeficheiro, "r" );

  	/*
  	VERIFICA SE NÃO HÁ ERROS NA ABERTURA DO FICHEIRO
  	*/
  	if( fp_entrada == NULL ){
    /*printf( "Open error of the input file\n" );*/
    exit(0);
  }

  lista_matrizes = saveMatrices( fp_entrada );

  /*APENAS PARA TESTE*/
   /* PrintList( lista_matrizes);*/



    EscreveFileSaida(nomeficheiro,lista_matrizes);


  	/*Liberta a memória da lista*/

    libertaLista( lista_matrizes, FreeItem );


  	/*Fecha o ficheiro*/
  	fclose(fp_entrada);

    exit(0);
}