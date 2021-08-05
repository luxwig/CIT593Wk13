#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Declaration of the node
typedef struct student_t {
    int    *grade;
    struct student_t *next;
} student_t;

/* offset    node 1                   
 *        +---------+                +-------+-------+
 *   0x0  |  grade  |--------------->|  85   |  99   |
 *        +---------+                +-------+-------+
 *   0x8  |  next   | -----------+
 *        +---------+            |
 *                               |
 *          node 2               |
 *        +---------+ <----------+
 *        |  grade  |----------------> int[2]
 *        +---------+
 *        |  next   | ------> next node
 *        +---------+
 */


// traversal
void print_list(student_t *ptr)
{
    int num = 0;
    while (ptr)
    {
        printf("Student %d: %3d %3d Addr - %p Next - %p\n", 
               ++num, ptr->grade[0], ptr->grade[1],
               ptr, ptr->next);
        ptr = ptr->next;
    }
}
int main()
{
    student_t *head, *current;
    head    = NULL;
    current = NULL;
    
    int   grade[2];
    int   num = 0;
    
    while (1)
    {
        // Input from stdin
        printf("Student %d: ", ++num);
        scanf("%d %d", grade, grade+1);
        if (feof(stdin)) break;
        
        // Allocate a new node for head ptr if head == NULL
        if (!head) 
        {
            head = (student_t*) malloc(sizeof(student_t));
            if (!head) return 1;
            current = head;
        }
        else 
        {
            // Allocate a new node for next ptr
            current->next = (student_t*) malloc(sizeof(student_t));
            if (!current->next) return 1;
            current = current->next;
        }
        
        // Copy the input data
        current->grade    = (int*) malloc(sizeof(int)*2);
        if (!current->grade) return 1;
        current->grade[0] = grade[0];
        current->grade[1] = grade[1];
        current->next     = NULL;
    }
    
    printf("\n\n");
    
    print_list(head);
    
    
    // deallocation
     
    /*              +--------+      +--------+
     * current -+-> | Node 1 | ---> | Node 2 |
     *          |   +--------+      +--------+
     * head ----+
     * 
     *              +--------+      +--------+
     * current ---> |<Freed> |  +-> | Node 2 |
     *              +--------+  |   +--------+
     *                  head ---+
     */
    
    while (head)
    {
        current = head;
        head = current->next;
        printf("%p deallocated\n",current);
        free(current->grade);
        free(current);
    }
}
