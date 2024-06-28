#include <stdio.h>

int main()
{
    char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *ptr = alphabet;
    for (int i = 0; i < 27; i++)
    {
        printf("%c  ",*(ptr+i));EX
    }
        
}