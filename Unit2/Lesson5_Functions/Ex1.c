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

int prime(int num);

void main()
{
	printf("Enter Two Numbers Interval : ");
	int num1 , num2;
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&num1,&num2);
	printf("prime number between %d and %d are: ",num1,num2);
	for(int i = num1 ; i <= num2; i++){
		if (prime(i) != 0)
		    printf("%d ", prime(i));
		else
		    continue;
	}

}
int prime(int num)
{
	if(num == 2 || num == 3 || num == 5 || num == 7) return num;
	else if((num % 2 != 0) && (num % 3 != 0) && (num % 5 != 0) && (num % 7 != 0)) return num;
	else return 0;
}
