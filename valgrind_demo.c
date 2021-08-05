/*******************************************************/
/* File Name : valgrind_demo.c                         */
/*             4 examples of 3 common valgrind errors  */
/* Author(s) : Ludwig Zhao                             */
/*******************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Illegal read/write errors
void func1()
{
    char *str    = (char*) malloc(sizeof(char) * 3);
    strcpy(str, "foo");
    printf("%s\n", str);
    free(str);
}

// Another examples of illegal read/write
void func2()
{
    int *ptr = (int*) malloc(sizeof(int));
    *ptr = 0xdeadbeef;
    printf("addr: %p - value: %x\n", ptr, *ptr);
    free(ptr);
    printf("ptr deallocated\n");
    printf("addr: %p - value: %x\n", ptr, *ptr);
}


// Use of uninitialised values
void func3()
{
    int *ptr = (int*) malloc(sizeof(int));
    printf("%d\n", ptr[0]);
    free(ptr);
}

// Illegal frees
void func4()
{
    int *ptr = (int*) malloc(sizeof(int));
    free(ptr);
    printf("ptr deallocated\n");
    free(ptr);
    printf("ptr deallocated again\n");
}

int main()
{
    int input;
    scanf("%d", &input);
    switch (input)
    {
        case 1:
            func1(); // Illegal read/write errors
            break;
        case 2:
            func2();
            break;
        case 3:
            func3(); // Use of uninitialised values
            break;
        case 4:
            func4(); // Illegal free
            break;
        default:
            printf("Invalid input\n");
    }
}
