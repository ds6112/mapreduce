CC = gcc
all:	mapred
	rm -f *~ *.o
mapred:	main.o	mapreducer.o shuffle.o mapper.o merge.o
	$(CC) -o mapred	main.o	mapreducer.o shuffle.o mapper.o merge.o -lpthread
main.o:	main.c
	$(CC) -c main.c -lpthread
mapreducer.o: mapreducer.c mapreducer.h
	$(CC) -c mapreducer.c -lpthread
mapper.o:  mapper.c mapper.h
	$(CC) -c mapper.c -lpthread
shuffle.o:  shuffle.c shuffle.h
	$(CC) -c shuffle.c -lpthread
merge.o:  merge.c merge.h
	$(CC) -c merge.c -lpthread	
clean:
	rm -f *~ *.o mapred