/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 5 ***************
 */
#include <stdio.h>

void main()
{
	char a;
	printf("Enter a Character ");
	fflush(stdin);  fflush(stdout);
	scanf("%c",&a);
	if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
	{
		printf("%c is Alphabet",a);
	}

	else
	{
		printf("%c is Not Alphabet",a);
	}
}
