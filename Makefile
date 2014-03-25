CC = gcc
all:	mapred
mapred:	main.o	mapper_wc.o
	$(CC) -o mapred	main.o	mapper_wc.o -lpthread
main.o:	main.c
	$(CC) -c main.c -lpthread
mapper_wc.o:	mapper_wc.c mapper_wc.h
	$(CC) -c mapper_wc.c -lpthread
clean:
	rm -f *~ *.o mapred