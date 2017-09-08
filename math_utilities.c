#include <stdio.h>

// Method to calculate the median in a list of integer
float median(int n, int x[]) {
    float temp;
    int i, j;
    // the following two loops sort the array x in ascending order
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(x[j] < x[i]) {
                // swap elements
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    if(n%2==0) {
        // if there is an even number of elements, return mean of the two elements in the middle
        return((x[n/2] + x[n/2 - 1]) / 2.0);
    } else {
        // else return the element in the middle
        return x[n/2];
    }
}


// Binomial coefficient
/*  Function to generate subset of length r */
void subset(int arr[], int data[], int start, int end, int index, int r)
{
    int j, i;
    if (index == r) {
        return;
    }
    for (i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        subset(arr, data, i+1, end, index+1, r);
        if (index+1 == r) {
            printf("%s\n", "We consider the array: ");
            for (j = 0; j < index+1; j++)
            printf("%d ", data[j]);
            printf("\n");
        }
        
    }
}


/*  Function to print the subsets */
void printsubset(int arr[], int n, int r)
{
    int data[r];
    subset(arr, data, 0, n - 1, 0, r);
    
}