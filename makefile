# The makefile for MP6.
# Type:
#   make         -- to build program lab6
#   make clean   -- to delete object files, executable, and core
#

comp = gcc
comp_flags = -g -Wall 
comp_libs = -lm  


lab6 : Graph.o lab6.o 
	$(comp) $(comp_flags) Graph.o lab6.o -o lab6 $(comp_libs)

Graph.o : Graph.c Graph.h
	$(comp) $(comp_flags) -c Graph.c

lab6.o : lab6.c Graph.h 
	$(comp) $(comp_flags) -c lab6.c


clean :
	rm -f *.o lab6 core
