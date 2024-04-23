/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 7 ***************
 */
#include <stdio.h>

void main()
{
	int a;
	printf("Enter a Integer ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&a);
	if(a < 0){
		printf("Error!!! factorial of negative number doesn't exit.");
	}
	else if(a == 0)
	{
		printf("Factorial = 1");
	}
	else
	{
		int sum = 1;
		for(int i = 1; i < a; i++)
		{
			sum *= i;
		}
		printf("Factorial = %d",sum);
	}
}
