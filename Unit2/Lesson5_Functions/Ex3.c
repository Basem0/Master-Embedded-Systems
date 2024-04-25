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

void reverse();

void main()
{
	printf("Enter A Sentance ");
	fflush(stdin);
	fflush(stdout);
	reverse();

}
void reverse() {
    char letter;
    scanf("%c", &letter);
    if (letter != '\n') {
    	reverse();
        printf("%c", letter);
    }
}
