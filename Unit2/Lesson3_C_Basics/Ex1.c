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
	int num;
	printf("Enter An Integer You Want Check ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	if(num % 2 == 0)
	{
		printf("%d is even",num);
	}
	else{
		printf("%d is odd",num);
	}
}
