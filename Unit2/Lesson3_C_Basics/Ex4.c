/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 4 ***************
 */
#include <stdio.h>

void main()
{
	float a;
	printf("Enter a Number ");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&a);
	if(a > 0	)
	{
		printf("%.1f is positive",a);
	}
	else if(a < 0)
	{
		printf("%.1f is negative",a);
	}
	else
	{
		printf("%.1f is Zero",a);
	}
}
