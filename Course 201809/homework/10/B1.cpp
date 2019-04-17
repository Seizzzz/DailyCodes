#include <stdio.h>
#include <stdlib.h>
#define ROWSIZE 5
#define COLSIZE 5
void inputMatrix (int array[][COL1],int rows,int cols);
int findRowMax(int data[], int rowSize); 
int findColMin(int data[][COLSIZE],int,int);

int findRowMax(int data[], int elementSize)
{
    int i, maxloc=0;
    
    for (i=1; i<= elementSize-1; i++)
         if (data[i]>data[maxloc])  //或*(data+i)        
               maxloc=i;         
          
    return maxloc;
}

int findColMin(int data[][COLSIZE], int rows,int col)
{
    int row,minRow=0;
    
    for (row=1; row<=rows-1; row++)
        if (data[row][col]<data[minRow][col]) 
					//或*(p+row*COLS+col)
           minRow=row;
          
    return minRow;
} 


int main(void)
{
    int matrix[ROWSIZE][COLSIZE];
    int found;
    int row,col,minRow,maxCol; 

    inputMatrix (matrix,ROWSIZE,COLSIZE ); //输入矩阵
	    row=0; found=0;
    while (row<ROWSIZE){
           maxCol=findRowMax(matrix[row],COLSIZE);
          minRow=findColMin(matrix,ROWSIZE,maxCol);
          if (minRow==row){ //找到鞍点，则输出
              printf("\nrow=%3d col=%3d element=%3d\n",row,maxCol,matrix[row][maxCol]);
              found=1;
        }
        row++;
      }      

   if (found==0)
       printf("未找到鞍点\n"); 
     
 
    return 0;
}

