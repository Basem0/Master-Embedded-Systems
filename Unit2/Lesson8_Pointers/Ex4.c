#include <stdio.h>

int main() {
    int n, i;
    int arr[5];

    for(int i = 0; i < 5; i++){
        printf("element %d : ",i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements of the array in reverse order are:\n");
    for (i = 4; i >= 0; i--) {
        printf("element - %d : %d\n", i + 1, arr[i]);
    }

    return 0;
}
