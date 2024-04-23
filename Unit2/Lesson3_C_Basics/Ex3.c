/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 3 ***************
 */
#include <stdio.h>

void main()
{
	float a,b,c;
	printf("Enter the three Numbers ");
	fflush(stdin);  fflush(stdout);
	scanf("%f %f %f",&a,&b,&c);
	if(a>b)
	{
		if(a>c) printf("Largest Num = %.1f",a);
		else printf("Largest Num = %.1f",c);
	}
	else
	{
		if(b>c) printf("Largest Num = %.1f",b);
		else printf("Largest Num = %.1f",c);
	}
}
