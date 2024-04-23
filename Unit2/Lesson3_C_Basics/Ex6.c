/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 6 ***************
 */
#include <stdio.h>

void main()
{
	int a;
	printf("Enter a Integer ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&a);
	int sum = 0;
	for(int i = a; i > 0; i--)
	{
		sum += i;
	}
	printf("sum = %d",sum);
}
