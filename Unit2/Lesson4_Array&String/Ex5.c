/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 5 ***************
 */
#include <stdio.h>

void main()
{
	printf("Enter Number Of Element : ");
	int num;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	int arr[num];
	for(int i = 0; i < num; i++)
	{
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&arr[i]);
	}
	printf("Entered The Element To Be Search : \n");
	int search;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&search);

	int index = 0;
	for(int i = 0; i < num; i++)
	{
		if(arr[i] == search)
		{
			index = i + 1;
			break;
		}
	}
	if(index != 0)
	{
		printf("Number Found At Location %d",index);
	}
	else{
		printf("Number Not Found");
	}
}
