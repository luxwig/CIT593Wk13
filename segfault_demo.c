/********************************************************************/
/* File Name : segfault_demo.c                                      */
/*             an example of how to use gdb to debug the segfault   */
/* Author(s) : Ludwig Zhao                                          */
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void swap(char *lhs,  char *rhs)
{
    char *tmp = (char*) malloc(sizeof(char) * strlen(lhs) + 1);
    strcpy(tmp, lhs);
    strcpy(lhs, rhs);
    strcpy(rhs, tmp);
    free(tmp);
}

int main()
{
    char* str1 = "Ah!";
    char* str2 = "Hello World!";
    
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    swap(str1, str2);
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
}
