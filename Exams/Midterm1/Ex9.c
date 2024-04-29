/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 9 ***************
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

void main()
{
	printf("Enter The String : ");
	char text[1000];
	fflush(stdin);
	fflush(stdout);
	scanf("%s",text);
	printf("Reverse String is : ");
	for(int i = strlen(text) - 1; i >= 0; i--)
	{
		printf("%c",text[i]);
	}

}