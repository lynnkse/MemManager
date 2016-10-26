CC = g++
CFLAGS = -g -c -ansi -Wall -pedantic -Werror

OBJS = MemPool_t.o MemManager_t.o MemPage_t.o mem_manager.o

.PHONY : clean rebuild

mem_manager : $(OBJS)
	$(CC) $(OBJS) -o mem_manager

mem_manager.o : mem_manager.cpp MemManager_t.h MemPool_t.h MemPage_t.h
	$(CC) $(CFLAGS) mem_manager.cpp

MemManager_t.o : MemManager_t.cpp MemManager_t.h
	$(CC) $(CFLAGS) MemManager_t.cpp

MemPool_t.o : MemPool_t.cpp MemPool_t.h
	$(CC) $(CFLAGS) MemPool_t.cpp
	
MemPage_t.o : MemPage_t.cpp MemPage_t.h
	$(CC) $(CFLAGS) MemPage_t.cpp
	
clean :
	rm -f *.o
	rm -f mem_manager
	
rebuild : clean mem_manager
