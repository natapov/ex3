CC = g++
EXEC = test
EXEC_MAIN = test.o
EXEC_OBJS = date.o date_wrap.o 
DEBUG_FLAG = -g
COMP_FLAG = -Wall -Werror -pedantic-errors
date.o : date.c date.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.c

date_wrap.o : date_wrap.cpp date_wrap.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

test.o : date.o date_wrap.o test.cpp
	$(CC) -c -o $(EXEC_MAIN) $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
	
$(EXEC) : $(EXEC_MAIN)
	$(CC) $(DEBUG_FLAG) $(EXEC_MAIN) $(EXEC_OBJS) -o $@
clean :
	rm -f date.o test.o date_wrap.o test.exe
