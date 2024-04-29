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
#include <math.h>

void main()
{
	printf("Enter the Number : ");
	int num;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	float result = sqrt((float)num);
	printf("%0.3f",result);


}


