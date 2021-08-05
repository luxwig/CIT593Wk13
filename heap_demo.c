/***************************************************************/
/* File Name : heap_demo.c                                     */
/*             demostrate how heap and stack are allocated     */
/* Author(s) : Ludwig Zhao                                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  array1[3] = {1, 2, 3}; 
    int *intptr1, *intptr2;
    
    printf("Addr of array1:\t%p\n", &array1);
    printf("Addr of intptr1:\t%p\n", &intptr1);
    printf("Addr of intptr2:\t%p\n", &intptr2);
    
    intptr1 = (int*) malloc(sizeof(int) * 3);
    intptr1[0] = 0xdeadbeef;
    intptr1[1] = 0xdeadbeef;  
    intptr1[2] = 0xdeadbeef;
    
    intptr2 = (int*) malloc(sizeof(int) * 3);
    printf("Value of intptr1:\t%p\n", intptr1);
    printf("Value of intptr2:\t%p\n", intptr2);
    
    free(intptr1);
    free(intptr2);
}

