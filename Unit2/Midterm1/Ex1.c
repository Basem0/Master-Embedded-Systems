/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 1 ***************
 */
#include <stdio.h>
#include <string.h>

int sum(int num);
void main()
{
	printf("Enter the Number : ");
	int num;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	printf("Sum of Digits = %d",sum(num));


}
int sum(int num){
	int sum = 0;
	while(num != 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

