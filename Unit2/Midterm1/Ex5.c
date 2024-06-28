/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 5 ***************
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
		num2 += num1 % 2;
		num1 /= 2;
	}
	printf("%d",num2);


}


