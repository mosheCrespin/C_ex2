CC=gcc
FLAGS=-Wall -g
AR=ar
HEADER=myBank.h
.PHONY: all clean 
all: mains 
myBank.o:myBank.c $(HEADER)
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c $(HEADER)
	$(CC) $(FLAGS) -c main.c 
myBanklib.a: myBank.o
	$(AR) -rcs myBanklib.a myBank.o
mains: myBanklib.a main.o 
	$(CC) $(FLAGS) -o mains main.o -L. myBanklib.a
clean:
	rm  *.o  *.a mains
	
	

