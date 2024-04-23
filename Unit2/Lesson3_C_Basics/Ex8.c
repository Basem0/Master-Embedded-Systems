/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 2 ***************
 */
#include <stdio.h>

void main()
{
	float num1,num2;
	char operator;
	printf("Enter operator either + or - or * or divide: \n"); //to determine the operator
	fflush(stdin); fflush(stdout);
	scanf("%c",&operator);
	printf("Enter tow operands: \n");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&num1,&num2);
	if(operator=='+')
		printf("%0.2f + %0.2f = %0.2f",num1,num2,num1+num2);
	if(operator=='-')
		printf("%0.2f - %0.2f = %0.2f",num1,num2,num1-num2);
	if(operator=='*')
		printf("%0.2f * %0.2f = %0.2f",num1,num2,num1*num2);
	if(operator=='/')
		printf("%0.2f / %0.2f = %0.2f",num1,num2,num1/num2);
}
