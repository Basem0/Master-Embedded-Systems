/* Master Embedded System Diploma
 * Kerolos Shenoda
 * Learn In Dipth
 * Made By Ahmed Basem Mohamed
 *
 *
 * ****************** EX 2 ***************
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

struct len {
    int feet;
    float inches;
};

struct len addLen(struct len len1, struct len len2){
    struct len res;
    res.inches = len1.inches + len2.inches;
    res.feet = len1.feet + len2.feet + (res.inches / 12);
    res.inches -= 12;
    return res;
}


void main()
{
	struct len len1, len2, res;
	printf("Enter length 1 (feet inches): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %f", &len1.feet, &len1.inches);
	printf("Enter length 2 (feet inches): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %f", &len2.feet, &len2.inches);
	res = addLen(len1, len2);
	printf("Sum: %d feet %0.1f inches\n", res.feet, res.inches);

}
