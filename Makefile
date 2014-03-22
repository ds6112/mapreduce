CC = gcc
all:	mapred
mapred:
	$(CC) -o mapred main.c

clean:
	rm -f *~ *.o mapred