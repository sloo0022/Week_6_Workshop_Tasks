/*
*******************************************************************************************************
                                        Task_4_description
*******************************************************************************************************
Consider the following C program and answer the following questions:
1. Describe what the compute_array() function in the code does?
2. Is the program memory safe? If not, how could the program be made memory safe while retaining its
original functionality?
*******************************************************************************************************
*/

/*
The compute_array function checks the indices in string_combined (in main() function) where 
string_1 (in main() function) is detected. The indices will be indicated in the integer array (returned
by the function as a pointer to integer) by setting the elements at the respective indices of the array 
to be equal to the length of string_1 (equal to strlen("abc") = 3 in the example considered). There is
a memory leak in the program, which can be prevented by freeing the space to which the pointer variable 
array_1 points to in memory.
*/


/*
compute_array 
// alloc array1, give elem1 = 0 
// while sum of index and  is within the strlen, and the array
array_1 
start at 0, 
str comb
a b c & a b c 
strcom , str1 a == strcom curr ind + offset from str1 a 
offset ++ until it finds a mismatch 

index i searches through str1, would lead to mismatch at separator $ 


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* compute_array(char* string_combined) 
{
    int n = strlen(string_combined);
    int* array_1 = (int*)malloc(sizeof(int)*n);         
    array_1[0] = 0;
    for (int i = 1; i < n; i++) 
    {
        array_1[i] = 0;
       
        while(((i + array_1[i]) < n) && (string_combined[array_1[i]] == string_combined[i + array_1[i]])) 
        {
            (array_1[i])++;
        }
    }
    return array_1;
}


int main()
{
    char* string_1 = "abc";
    char* separator = "$";
    char* string_2 = "abcacbabcabddbabcaxabc";
   
    char string_combined[200];
    strcpy(string_combined, string_1);
    strcat(string_combined, separator);
    strcat(string_combined, string_2);
    int* array_1 = compute_array(string_combined);
    int n = strlen(string_combined);
    int m = strlen(string_1);

    // testing code 
    // for (int i = 0; i < sizeof(array_1); i++){
    //     printf("%d ", array_1[i]);
    // }
    // printf("\n");
   
    for (int i = 0; i < n; i++) 
    {
        if (array_1[i] == m) 
        {
            printf("%d ", i - m - 1);
        }
    }

    free(array_1);  // to prevent the memory leak
    return 0;
}