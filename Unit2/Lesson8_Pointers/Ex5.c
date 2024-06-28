#include <stdio.h>

struct Employee {
    char name[50];
    int id;
};

int main() {
    struct Employee temp = {"Alex", 1002};
    struct Employee *arr[1]; 
    struct Employee **ptr;  

    arr[0] = &temp; 
    ptr = arr;      
    
    printf("Employee Name : %s\n", (*ptr)->name);
    printf("Employee ID : %d\n", (*ptr)->id);

    return 0;
}