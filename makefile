##**
##* @file makefile
##* @author William Hayes, Jackson Horton, and Kenneth Wallace
##* @date 2022-11-22
##* @brief short
##* 
##* long


CC = g++
CFLAGS = -g -Wall -Wextra


default: deq

deq: main.o
	$(CC) $(CFLAGS) -o deq main.o

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) deq *.o *~
