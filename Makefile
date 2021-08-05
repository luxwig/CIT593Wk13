###########################################################################
## File Name : Makeile 		    									     ##
## Purpose   : CIT 593 Week 11 Recitation                                ##
##             Makefile 		    									 ##
## Author(s) : Ludwig Zhao 		 									     ##
###########################################################################

CC = clang
CFLAGS = -Wall -g
INCLUDES =
LFLAGS =
MAINS = malloc_calloc students segfault_demo valgrind_demo

.PHONY: clean

all:    $(MAINS)

$(MAINS): $(MAIN=$@)

.c.o: 
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@
clean:
	rm -f *.o *~ $(MAINS)

