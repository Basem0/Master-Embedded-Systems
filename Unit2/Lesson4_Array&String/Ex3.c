/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 3 ***************
 */
#include <stdio.h>

void main()
{
	printf("Enter The Row & Columns : ");
	int row,column;
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&row,&column);
	int arr[row][column];
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			printf("enter [%d][%d] ",i,j);
			fflush(stdin);
			fflush(stdout);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Entered Matrix : \n");
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("Transposed Matrix : \n");
	for(int i = 0; i < column; i++)
	{
		for(int j = 0; j < row; j++)
		{
			printf("%d\t",arr[j][i]);
		}
		printf("\n");
	}

}
