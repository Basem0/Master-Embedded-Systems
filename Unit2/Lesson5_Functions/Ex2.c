/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 2 ***************
 */
#include <stdio.h>
#include <string.h>

int Factorial(int num);

void main()
{
	printf("Enter A Positive Number : ");
	int num;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	if(num == 0)
		printf("Factorial of 0 is = 1: ");
	else
		printf("Factorial of %d is = %d: ",num,Factorial(num));

}
int Factorial(int num)
{
	if(num == 1)
		return 1;
	else
		return num * Factorial(num - 1) ;
}
