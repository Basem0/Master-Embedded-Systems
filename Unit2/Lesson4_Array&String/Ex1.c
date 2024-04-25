/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 1 ***************
 */
#include <stdio.h>

void main()
{
	int arr1[2][2];
	int arr2[2][2];
	printf("Enter The elements of 1st Array\n");
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("enter [%d][%d] ",i,j);
			fflush(stdin);
			fflush(stdout);
			scanf("%d",&arr1[i][j]);
		}
	}
	printf("Enter The elements of 2nd Array\n");
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("enter [%d][%d] ",i,j);
			fflush(stdin);
			fflush(stdout);
			scanf("%d",&arr2[i][j]);
		}
	}
	int sum[2][2];
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			sum[i][j] =	arr1[i][j] + arr2[i][j];
		}
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("%d\t",sum[i][j]);
		}
		printf("\n");
	}


}
