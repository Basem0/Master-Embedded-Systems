/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 5 ***************
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define pi 3.14156f
#define area(redius) (redius*redius*pi)

int main(void)
{
	int redius;
    printf("Enter Redius Please : ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d",&redius);
    printf("Area = %0.2f",area(redius));

    return 0;
}

