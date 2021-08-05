/*************************************************************/
/* File Name : malloc_calloc.c                               */
/*             demostrate two identical different ways       */
/*             to allocate memory using malloc and calloc    */
/* Author(s) : Ludwig Zhao                                   */
/*************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int*) malloc(sizeof(int) * 4);
    ptr[0] = ptr[1] = ptr[2] = ptr[3] = 0;
    printf("%d %d %d %d\n", ptr[0], ptr[1], ptr[2], ptr[3]);
    free(ptr);
    ptr = (int*) calloc(4, sizeof(int));
    printf("%d %d %d %d\n", ptr[0], ptr[1], ptr[2], ptr[3]);
    free(ptr);
}
