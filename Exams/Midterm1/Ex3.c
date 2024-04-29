/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 3 ***************
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

void main()
{
	printf("Enter the Numbers : ");
	int num1,num2;
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&num1,&num2);
	for(int i = num1; i <= num2; i++){
		if((i==2) || (i==3) || (i==5) || (i==7))
			printf("%d\t",i);
		else if((i%2!=0) && (i%3!=0) && (i%5!=0) && (i%7!=0))
			printf("%d\t",i);
	}


}


