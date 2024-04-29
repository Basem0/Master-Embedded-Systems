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
#include <math.h>

int main ()
{
	int arr[10], freq[10];
	int size, i, j, count;
    printf("Enter size of array: ");
    fflush(stdout); fflush(stdin);
    scanf("%d", &size);

	    printf("Enter elements in array: ");
	    fflush(stdout); fflush(stdin);
	    for(i=0; i<size; i++)
	    {
	        scanf("%d", &arr[i]);
	        freq[i] = -1;
	    }

	    for(i=0; i<size; i++)
	    {
	        count = 1;
	        for(j=i+1; j<size; j++)
	        {
	            if(arr[i] == arr[j])
	            {
	                count++;
	                freq[j] = 0;
	            }
	        }

	        if(freq[i] != 0)
	        {
	            freq[i] = count;
	        }
	    }

	    printf("Unique elements are: ");
	    for(i=0; i<size; i++)
	    {
	        if(freq[i] == 1)
	        {
	            printf("%d ", arr[i]);
	        }
	    }

	return 0;
}
