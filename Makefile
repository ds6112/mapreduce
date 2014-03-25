CC = gcc
all:	mapred
mapred:	main.o	mapreducer.o mapper_wc.o
	$(CC) -o mapred	main.o	mapreducer.o mapper_wc.o -lpthread
main.o:	main.c
	$(CC) -c main.c -lpthread
mapreducer.o: mapreducer.c mapreducer.h
	$(CC) -c mapreducer.c -lpthread
mapper_wc.o:	mapper_wc.c mapper_wc.h
	$(CC) -c mapper_wc.c -lpthread
clean:
	rm -f *~ *.o mapred