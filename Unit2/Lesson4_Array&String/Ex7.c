/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 7 ***************
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
	int size = 0;
	int i = 0;
	while(text[i++] != '\0')
	{
		size++;
	}
	printf("Lenght Of String is : %d",size);

}
