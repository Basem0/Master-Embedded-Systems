#include <stdio.h>
#include <string.h>

int main()
{
    char text[6] = "Ahmed"; 
    char *ptr = text;       
    int len = strlen(text); 
    
    printf("Input text : %s\n", text);
    printf("Reverse text : ");
    
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", *(ptr + i));
    }
    
    printf("\n");
    return 0;
}
