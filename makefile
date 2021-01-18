CC = g++
EXEC = test #NAME OF FINAL EXECUTABLE
TEST_EVENTS = test_events
TEST_EVENTS_OBJ = test_events.o
MAIN_CPP = test_partB.cpp #CHANGE ME TO CHANGE THE CURRENT TEST FILE
MAIN_OBJ = test.o

#THIS IS ALL THE OBJ FILES EXCEPT THE ONE CONTAINTING THE main() FUNCTION
ALL_OBJS = date.o date_wrap.o  base_event.o closed_event.o open_event.o custom_event.o list.o event_container.o festival.o

#VARIOUS FLAGS
DEBUG_FLAG = -g
COMP_FLAG = -std=c++11 -Wall -Werror -pedantic-errors
COMP_FLAG_C = -std=c99 -Wall -Werror -pedantic-errors 

#OBJECT FILES: right hand side should be source files only
date.o : date.c date.h
	gcc -c $(DEBUG_FLAG) $(COMP_FLAG_C) $*.c

list.o: list.cpp list.h exceptions.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

date_wrap.o : date_wrap.cpp date_wrap.h exceptions.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

base_event.o : base_event.cpp base_event.h list.h date_wrap.cpp date_wrap.h date.c date.h exceptions.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

open_event.o : open_event.cpp open_event.h base_event.cpp base_event.h  list.h date_wrap.cpp date_wrap.h date.c date.h exceptions.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

custom_event.o : custom_event.h custom_event.cpp base_event.cpp base_event.h list.cpp list.h date_wrap.cpp date_wrap.h date.c date.h exceptions.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

closed_event.o : closed_event.cpp closed_event.h base_event.cpp base_event.h  list.h date_wrap.cpp date_wrap.h date.c date.h exceptions.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

event_container.o: event_container.h event_container.cpp list.h base_event.h base_event.cpp date_wrap.h date_wrap.cpp date.h date.c
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

festival.o: festival.h festival.cpp event_container.h event_container.cpp list.h base_event.h base_event.cpp date_wrap.h date_wrap.cpp date.h date.c
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

$(MAIN_OBJ) : $(MAIN_CPP)
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $(MAIN_CPP) -o $@

$(TEST_EVENTS_OBJ) : test_events.cpp event_container.cpp event_container.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) test_events.cpp -o $@

#EXECUTABLES
#NOT ALL OBJECT FILES ARE NECARRY FOR EVERY TEST BUT THIS WORKS TOO
$(EXEC) : $(MAIN_OBJ) $(ALL_OBJS) #all objects should be here
	$(CC) $(DEBUG_FLAG) $(MAIN_OBJ) $(ALL_OBJS) -o $@

$(TEST_EVENTS) : $(TEST_EVENTS_OBJ) $(ALL_OBJS) 
	$(CC) $(DEBUG_FLAG) $(TEST_EVENTS_OBJ) $(ALL_OBJS) -o $@
clean :
	rm -f $(MAIN_OBJ) $(ALL_OBJS) $(EXEC) $(TEST_EVENTS_OBJ) test_list test_list.o $(TEST_EVENTS) 