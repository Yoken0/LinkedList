CC = gcc
CFLAGS = -Wall
RM = rm -f

default: all

all: Q1 Q2 Q3 Q4 Q5

Q1: Q1.c
	$(CC) $(CFLAGS) -o Q1 Q1.c -lm

Q2: Q2.c
	$(CC) $(CFLAGS) -o Q2 Q2.c -lm

Q3: Q3.c
	$(CC) $(CFLAGS) -o Q3 Q3.c -lm

Q4: Q4.c
	$(CC) $(CFLAGS) -o Q4 Q4.c -lm

Q5: Q5.c
	$(CC) $(CFLAGS) -o Q5 Q5.c -lm

clean: 
	$(RM) Q1 Q2 Q3 Q4 Q5
