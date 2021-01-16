CC = g++
EXEC = test
EXEC_CPP = test_partA.cpp
EXEC_MAIN = test.o
EXEC_OBJS = date.o date_wrap.o 
DEBUG_FLAG = -g
COMP_FLAG = -std=c++11 -Wall -Werror -pedantic-errors
COMP_FLAG_C = -std=c99 -Wall -Werror -pedantic-errors 

#OBJECT FILES: right hand side should be source files only
date.o : date.c date.h
	gcc -c $(DEBUG_FLAG) $(COMP_FLAG_C) $*.c

list.o: sorted_list.cpp sorted_list.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

date_wrap.o : date_wrap.cpp date_wrap.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

base_event.o : base_event.cpp base_event.h sorted_list.cpp sorted_list.h date_wrap.cpp date_wrap.h date.c date.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

closed_event.o : closed_event.cpp closed_event.h base_event.cpp base_event.h sorted_list.cpp sorted_list.h date_wrap.cpp date_wrap.h date.c date.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

open_event.o : open_event.cpp open_event.h base_event.cpp base_event.h sorted_list.cpp sorted_list.h date_wrap.cpp date_wrap.h date.c date.h	
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

#EXECUTABLES
$(EXEC_MAIN) : $(EXEC_CPP)
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $(EXEC_CPP) -o $@
	
$(EXEC) : $(EXEC_MAIN) $(EXEC_OBJS) #all objects should be here
	$(CC) $(DEBUG_FLAG) $(EXEC_MAIN) $(EXEC_OBJS) -o $@


clean :
	rm -f date.o test.o date_wrap.o list.o base_event.o test.exe
