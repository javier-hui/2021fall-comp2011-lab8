# Write the make file here

# Definition of variables
SRCS = lab8.cpp main.cpp
OBJS = lab8.o main.o
# Rules' Format
# TARGET: DEPENDENCIES
# [TAB] COMMAND USED TO CREATE THE TARGET
main: $(OBJS)
	g++ -o main $(OBJS)
lab8.o: lab8.cpp lab8.h
	g++ -c lab8.cpp
main.o: main.cpp lab8.h
	g++ -c main.cpp
# makedepend can find the .h dependencies automatically
depend:; makedepend $(SRCS)