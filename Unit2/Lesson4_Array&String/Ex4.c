/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 2 ***************
 */
#include <stdio.h>

void main()
{
	printf("Enter Number Of Element : ");
	int num;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	int arr[num + 1];
	for(int i = 0; i < num; i++)
	{
		arr[i] = i+1;
	}
	for(int i = 0; i < num; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\nEntered The Element To Be Inserted : \n");
	int inserted;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&inserted);
	printf("Entered The Location : \n");
	int location;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&location);
	arr[num] = arr[location - 1];
	arr[location - 1] = inserted;
	for(int i = 0; i < num+1; i++)
	{
		printf("%d\t",arr[i]);
	}


}
