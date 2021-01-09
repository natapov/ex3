CC = g++
EXEC = test
EXEC_CPP = test_partA.cpp
EXEC_MAIN = test.o
EXEC_OBJS = date.o date_wrap.o 
DEBUG_FLAG = -g
COMP_FLAG = -std=c++11 -Wall -Werror -pedantic-errors 

#OBJECT FILES: right hand side should be source files only
date.o : date.c date.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.c

date_wrap.o : date_wrap.cpp date_wrap.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

$(EXEC_MAIN) : $(EXEC_CPP)
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $(EXEC_CPP) -o $@
	
$(EXEC) : $(EXEC_MAIN) $(EXEC_OBJS) #all objects should be here
	$(CC) $(DEBUG_FLAG) $(EXEC_MAIN) $(EXEC_OBJS) -o $@
clean :
	rm -f date.o test.o date_wrap.o test.exe
