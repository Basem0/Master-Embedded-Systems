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
	printf("Enter The Number of Data : ");
	int num;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	float arr[num];
	float sum = 0;
	for(int i = 0; i < num; i++)
	{
		printf("enter [%d] ",i);
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&arr[i]);
	}
	for(int i = 0; i < num; i++)
	{
		sum += arr[i];
	}
	printf("Average = %f",(sum/num));


}
