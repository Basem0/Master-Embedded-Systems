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
#include <math.h>

struct complex {
    float real;
    float imaginary;
};

struct complex sumCmplx(struct complex cmplx1, struct complex cmplx2){
    struct complex res;
    res.real = cmplx1.real + cmplx2.real;
    res.imaginary = cmplx1.imaginary+ cmplx2.imaginary;
    return res;
}


void main()
{
	struct complex cmplx1, cmplx2, res;
	printf("Enter real of 1st Element : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &cmplx1.real);
	printf("Enter imaginary of 1st Element : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &cmplx1.imaginary);
	printf("Enter real of 2nd Element : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &cmplx2.real);
	printf("Enter imaginary of 2nd Element : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &cmplx2.imaginary);
	res = sumCmplx(cmplx1, cmplx2);
	printf("Sum =  %0.1f + %0.1fi\n", res.real, res.imaginary);

}
