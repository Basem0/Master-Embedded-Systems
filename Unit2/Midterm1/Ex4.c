/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 4 ***************
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

void main()
{
	printf("Enter the Number : ");
	int num1,num2 = 0;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num1);
	while(num1 != 0)
	{
		num2 = (num2 * 10) + (num1 % 10);
		num1 /= 10;
	}
	printf("%d",num2);


}


