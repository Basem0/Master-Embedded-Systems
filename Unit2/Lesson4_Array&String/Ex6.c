/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 6 ***************
 */
#include <stdio.h>
#include <string.h>
void main()
{
	printf("Enter The String : ");
	char text[1000];
	fflush(stdin);
	fflush(stdout);
	gets(text);
	printf("Enter The Character to Find Frequncy : ");
	char letter;
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&letter);
	int times = 0;
	strlwr(text);
	for(int i = 0; i < strlen(text); i++)
	{
		if(text[i] == letter)
		{
			times++;
		}
	}
	printf("Frequency of %c is : %d",letter,times);


}
