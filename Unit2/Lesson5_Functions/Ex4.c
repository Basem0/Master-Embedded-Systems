/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 4 ***************
 */
#include <stdio.h>
#include <string.h>

int power(int num,int pow);

void main()
{
	printf("Enter Base Number : ");
	int num;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	printf("Enter Power Number : ");
	int pow;
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&pow);
	printf("%d ^ %d  = %d",num ,pow ,power(num,pow));

}
int power(int num,int pow)
{
	if(pow == 0)
		return 1;
	else
		return num * power(num,pow-1) ;
}
