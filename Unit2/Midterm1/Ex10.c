/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 10 ***************
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

int ones (int num);
int main ()
{
	int num;

	printf("Enter an number : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);

	printf("maximum number of Ones = %d.", ones(num));

	return 0;
}


int ones (int num)
{
	int oper, counter=0, maxOnes=0;

	for (int i = 31; i >= 0; i--)
	{
		oper = num >> i;

		if (oper & 1)
			counter++;
		else
		{
			if(counter>maxOnes)
			{
				maxOnes = counter ;
				counter = 0;
			}
			else
				counter=0;
		}
	}
	return maxOnes;

}
