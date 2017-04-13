#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "matriz.h"
#include "listas.h"


int cnt=0;

struct _matriz {
  int **values;
  int linhas, colunas;
  int variante, linha_cluster, coluna_cluster;
};





/******************************************************************************
 * *NewMatrix(int size)
 *
 * Arguments: size - size of the square matrix (size x size)
 * Returns: (matrix *) pointer to actual word (string)
 * Side-Effects: none
 *
 * Description: returns the new matrix 
 *****************************************************************************/
matriz *NewMatrix(int linhas, int colunas, int variante, int coluna_cluster, int linha_cluster)
{

  int pI, pJ;
  pI = pJ = 0;

  /* allocate space for the matrix */
  matriz *Mat = (matriz*) malloc (sizeof(matriz));/* Write your code here */
  Mat->values = (int **) malloc(linhas*sizeof(int*));/* Write your code here */
  for ( pI = 0; pI < linhas; pI++ )
    Mat->values[pI] = (int*) malloc (colunas*sizeof(int));/* Write your code here */
 
  /* initiate matrix */
  for ( pI =0; pI < linhas; pI++ )
    for ( pJ =0; pJ < colunas; pJ++ )
      Mat->values[pI][pJ] = 0.0;

  Mat->linhas = linhas;
  Mat->colunas = colunas;
  Mat->variante = variante;
  Mat->coluna_cluster = coluna_cluster;
  Mat->linha_cluster = linha_cluster;

  return Mat;

}


/******************************************************************************
 * SetMatrixElement(t_matrix *mA, int pI, int pJ, float value)
 *
 * Arguments: mA    - (t_matrix *) the matrix
 *            pI    - (int) row of the element
 *            pJ    - (int) column if the element
 *            value - (float) value to include int the matrix 
 * Returns: (void) nothing 
 * Side-Effects: none
 *
 * Description: function to include an element (value) in the matrix (mA),
 *              in position (pI, pJ)
 *****************************************************************************/
void SetMatrixElement(matriz *mA, int pI, int pJ, float value)
{

  mA->values[pI][pJ] = value;

  return;

}





/******************************************************************************
 *  saveMatrices ()
 *
 * Arguments:  fm - pointer to the file with the matrices
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: save the matrices in fm, into mA. 
 *****************************************************************************/
lista *saveMatrices( FILE *fm )
{

  lista *lm;
  matriz *newMatrix;
  
  int m_linhas = 0, m_colunas=0, variante=0, linha=0, coluna=0;
  int pJ, pI, err;
  int NumberMatrices = 0;
  float newEntry = 0.0;

  printf("--> Loading matrices...");

  lm = iniLista();


  while( 1 ){ 

    /* scan the size of the matrix NumberMatrices */
    if( fscanf( fm, "%d %d %d %d %d", &m_linhas, &m_colunas, &variante, &linha, &coluna ) != 5 )
      break;

    /* verify if size is correct */
    /*if( m_size < 2 || m_size > 9 )
      {
            printf("FileData is corrupted.\n");
            exit(1);
      }*/


    /* create a new matrix */
    newMatrix = NewMatrix( m_linhas, m_colunas, variante, linha, coluna );

    /* save the matrix */
    for( pI = 0 ; pI < m_linhas ; pI++ ){
      for( pJ = 0 ; pJ < m_colunas ; pJ++ ){
        if( fscanf( fm, "%f", &newEntry ) != 1 )
          {
            printf("FileData is corrupted.\n");
            exit(1);
          }


        SetMatrixElement(newMatrix, pI, pJ, newEntry);
      }
    }
 
    NumberMatrices++;
    lm = criaNovoNoLista (lm, newMatrix, &err);


  }

  printf( "[DONE]\n" );
  return lm;

}




/******************************************************************************
 * PrintMatrix(t_matrix *mA)
 *
 * Arguments: mA - (t_matrix *) the matrix
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: print the matrix pointed by mA
 *****************************************************************************/
void PrintMatrix(matriz *mA)
{
 
  int pI, pJ;

  printf( "Matrix:\n" );
  printf("Variante: %d, Cluster: (%d, %d)\n", mA->variante, mA->linha_cluster, mA->coluna_cluster);
  for( pI = 0; pI < mA->linhas ; pI++ ){
    for( pJ = 0; pJ < mA->colunas ; pJ++ )
      printf( "%d ", GetMatrixElement( mA, pI, pJ ) );
    printf( "\n" );
  }

  return;

}

/******************************************************************************
 * GetMatrixElement(Matrix *mA, int pI, int pJ)
 *
 * Arguments: mA - (matrix *) the matrix
 *            pI - (int) row of the element
 *            pJ - (int) column if the element
 * Returns: (float) the value of the matrix that is in (pI, pJ)
 * Side-Effects: none
 *
 * Description: returns an element in the matrix (mA) in position (pI,pJ)
 *****************************************************************************/
int GetMatrixElement(matriz *mA, int pI, int pJ)
{

  return mA->values[pI][pJ];

}


int GetMatrixLinhas(matriz *mA)
{

  return mA->linhas;

}


int GetMatrixLinhaCluster(matriz *mA)
{

  return mA->linha_cluster;

}



int GetMatrixColunas(matriz *mA)
{

  return mA->colunas;

}

int GetMatrixColunaCluster(matriz *mA)
{

  return mA->coluna_cluster;

}

int GetVariante(matriz *mA)
{

  return mA->variante;

}


int** GetMatrix(matriz *mA)
{

  return mA->values;

}

/******************************************************************************
 * FreeMatrix(t_matrix *mA)
 *
 * Arguments: mA - (t_matrix *) the matrix
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: free all the memory associated with the matrix mA
 *****************************************************************************/
void FreeMatrix(matriz *mA)
{
  int pI;
  /* Complete the code here */
  for ( pI = 0; pI < mA->linhas; pI++ )
    free(mA->values[pI]);

  free(mA->values);
  free(mA);


  return;

}

/******************************************************************************
 * FreeItem ()
 *
 * Arguments: p - pointer to Item
 * Returns: (void)
 * Side-Effects: calls function to free word structure
 *
 * Description: interfaces generic list item to specific matrix structure
 *
 *****************************************************************************/
void FreeItem( matriz* this)
{

  FreeMatrix( (matriz *)this);

  return;
}


// A function to check if a given cell (row, col) can be included in DFS
int isSafe(matriz *mA, int row, int col, int **visited)
{
  int **M=GetMatrix(mA);
    // row number is in range, column number is in range and value is 1 
    // and not yet visited
    return (row >= 0) && (row < GetMatrixLinhas(mA)) &&     
           (col >= 0) && (col < GetMatrixColunas(mA)) &&      
           (M[row][col] && !visited[row][col]); 
}
 
// A utility function to do DFS for a 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(matriz *mA, int row, int col, int **visited, int value)
{

    // These arrays are used to get row and column numbers of 8 neighbours 
    // of a given cell
    //static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    //static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};
    static int rowNbr[] = {-1, 0, 1, 0};
    static int colNbr[] = {0, 1, 0, -1};
 
    // Mark this cell as visited
    visited[row][col] = 1;
 
    // Recur for all connected neighbours
    for (int k = 0; k < 4; ++k)
        if (isSafe(mA, row + rowNbr[k], col + colNbr[k], visited) && GetMatrixElement(mA, row, col) == GetMatrixElement(mA, row + rowNbr[k], col + colNbr[k]))
        {
          cnt++;
            DFS(mA, row + rowNbr[k], col + colNbr[k], visited, value);
              
        }

}
 
// The main function that returns count of islands in a given boolean
// 2D matrix
int countIslands(matriz *mA, int value)
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    //bool visited[GetMatrixLinhas(mA)][GetMatrixColunas(mA)];

    int **visited, i=0;

    visited = (int**) malloc (GetMatrixLinhas(mA)*sizeof(int*));
    for(i=0; i<GetMatrixLinhas(mA); i++)
      visited[i]=(int*) malloc (sizeof(int)*GetMatrixColunas(mA));


    for (int i = 0; i < GetMatrixLinhas(mA); ++i)
        for (int j = 0; j < GetMatrixColunas(mA); ++j)
          visited[i][j]=0;
        printf("\n 1.HEY!");


    int**M=GetMatrix(mA);
 
    // Initialize count as 0 and travese through the all cells of
    // given matrixs
    for (int i = 0; i < GetMatrixLinhas(mA); ++i)
        for (int j = 0; j < GetMatrixColunas(mA); ++j)
            if (M[i][j] == value && !visited[i][j]) // If a cell with value 1 is not
            {                         // visited yet, then new island found
                DFS(mA, i, j, visited, value);    
            }
 



    for (int i = 0; i < GetMatrixLinhas(mA); ++i)
          free(visited[i]);

        free(visited);

    if(value!=-1)
      cnt++;
    else cnt=0;

    return cnt;
}