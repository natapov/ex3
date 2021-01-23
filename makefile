CC = g++

TEST_EVENTS = test_events
TEST_EVENTS_OBJ = test_events.o

#main exec 
MAIN_EXEC = test #NAME OF FINAL EXECUTABLE
MAIN_CPP = temp.cpp #CHANGE ME TO CHANGE THE CURRENT TEST FILE
MAIN_OBJ = test.o

#THIS IS ALL THE OBJ FILES EXCEPT THE ONE CONTAINTING THE main() FUNCTION
ALL_OBJS = date.o date_wrap.o base_event.o closed_event.o open_event.o event_container.o festival.o schedule.o pointer_list.o

#VARIOUS FLAGS
DEBUG_FLAG = -g
COMP_FLAG = -std=c++11 -Wall -Werror -pedantic-errors 
COMP_FLAG_C = -std=c99 -Wall -Werror -pedantic-errors

#OBJECT FILES: right hand side should be source files only
date.o : date.c date.h
	gcc -c $(DEBUG_FLAG) $(COMP_FLAG_C) $*.c

date_wrap.o : date_wrap.cpp date_wrap.h exceptions.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

base_event.o : base_event.cpp base_event.h list.h date_wrap.cpp date_wrap.h date.c date.h exceptions.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

open_event.o : open_event.cpp open_event.h base_event.cpp base_event.h  list.h date_wrap.cpp date_wrap.h date.c date.h exceptions.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

closed_event.o : closed_event.cpp closed_event.h base_event.cpp base_event.h  list.h date_wrap.cpp date_wrap.h date.c date.h exceptions.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

pointer_list.o: pointer_list.h pointer_list.cpp base_event.h base_event.cpp
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
	
event_container.o: event_container.h event_container.cpp list.h base_event.h base_event.cpp date_wrap.h date_wrap.cpp date.h date.c pointer_list.h pointer_list.cpp
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

festival.o: festival.h festival.cpp event_container.h event_container.cpp list.h base_event.h base_event.cpp date_wrap.h date_wrap.cpp date.h date.c pointer_list.h pointer_list.cpp
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
schedule.o: schedule.cpp schedule.h event_container.h event_container.cpp base_event.h base_event.cpp date_wrap.h date_wrap.cpp date.h date.c pointer_list.h pointer_list.cpp
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp

$(MAIN_OBJ) : $(MAIN_CPP)
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $(MAIN_CPP) -o $@

$(TEST_EVENTS_OBJ) : test_events.cpp event_container.cpp event_container.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) test_events.cpp -o $@
 

#EXECUTABLES
#NOT ALL OBJECT FILES ARE NECARRY FOR EVERY TEST BUT THIS WORKS TOO
$(MAIN_EXEC) : $(MAIN_OBJ) $(ALL_OBJS) #all objects should be here
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $(MAIN_OBJ) $(ALL_OBJS) -o $@

$(TEST_EVENTS) : $(TEST_EVENTS_OBJ) $(ALL_OBJS) 
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $(TEST_EVENTS_OBJ) $(ALL_OBJS) -o $@
	
#TESTS: NAMES HARDCODED FOR SCRIPT COMPATABILITY
testA : test_partA.cpp $(ALL_OBJS) 
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) test_partA.cpp $(ALL_OBJS) -o $@
	
testB : test_partB.cpp $(ALL_OBJS) 
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) test_partB.cpp $(ALL_OBJS) -o $@
	
testC : test_partC.cpp $(ALL_OBJS) 
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) test_partC.cpp $(ALL_OBJS) -o $@
	
testL : test_list.cpp $(ALL_OBJS) 
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) test_list.cpp $(ALL_OBJS) -o $@
	
testE : test_list.cpp $(ALL_OBJS) 
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) test_list.cpp $(ALL_OBJS) -o $@

adamA : adam_test_part_a.cpp $(ALL_OBJS) 
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) adam_test_part_a.cpp $(ALL_OBJS) -o $@

adamB : adam_test_part_b.cpp $(ALL_OBJS) 
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) adam_test_part_b.cpp $(ALL_OBJS) -o $@

adamC : adam_test_part_c.cpp $(ALL_OBJS) 
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) adam_test_part_c.cpp $(ALL_OBJS) -o $@
clean :
	rm -f $(MAIN_OBJ) $(ALL_OBJS) $(MAIN_EXEC) $(TEST_EVENTS_OBJ) test_list test_list.o $(TEST_EVENTS) testC testB testA testL testE tmp.out adamA adamB adamC a
