/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 8 ***************
 */
#include <stdio.h>
#include <string.h>
#include <math.h>


void main()
{
	int size;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&size);
	int arr[size];
	for(int i = 0; i < size; i++)
	{
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&arr[i]);
	}
	for(int i = size - 1; i >= 0; i--)
	{
		printf("%d\t",arr[i]);
	}

    return 0; // indicate success


}