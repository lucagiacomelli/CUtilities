#include <stdio.h>
#include "utilities.h"

// Method to compare two strings in C
int compare_strings(const void*s0, const void*s1) {
    return strcmp((const char*)s0, (const char*)s1);
}

int getNumberWords(const char* text){
    int count = 0, i;
    
    for (i = 0; text[i] != '\0'; i++){
        if (text[i] == ' ')
        count++;
    }
    return count;
}



/*  Function to generate subset of strings of length r */
void subsetChar(char* arr[], char* data[], int start, int end, int index, int r)
{
    int j, i;
    if (index == r) {
        return;
    }
    for (i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        subsetChar(arr, data, i+1, end, index+1, r);
        if (index+1 == r) {
            printf("%s\n", "We consider the array: ");
            for (j = 0; j < index+1; j++)
            printf("%s ", data[j]);
            printf("\n");
            
        }
        
    }
}

/*  Function to print the subset  */
void printsubsetChar(char* arr[], int n, int r)
{
    char* data[r];
    subsetChar(arr, data, 0, n - 1, 0, r);
    
}


// Return the most common string among those present in a list
const char *most_common(const char **records, size_t n) {
    qsort(records, n, sizeof(records[0]), compare_strings);
    const char *best = 0;  // The most common string found so far.
    size_t max = 0;  // The longest run found.
    size_t run = 0;  // The length of the current run.
    for (size_t i = 0; i < n; i++) {
        if (!compare_strings(records[i], records[i - run])) {
            run += 1;
        } else {
            run = 1;
        }
        if (run > max) {
            best = records[i];
            max = run;
        }
    }
    return best;
}