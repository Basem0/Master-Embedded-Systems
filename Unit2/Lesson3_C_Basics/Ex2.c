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
	char vowel [] = {'a','A','e','E','i','I','o','O','u','U'};
	char letter;
	printf("Enter An Alphabet ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&letter);
	int check = 0;
	for(int i = 0; i < 10 ; i++)
	{
		if(letter == vowel[i]){
			check = 1;
			break;
		}
	}
	if(check) printf("%c is vowel",letter);
	else printf("%c is constant",letter);
}
