CC = gcc
all:	mapred
	rm -f *~ *.o
mapred:	main.o	mapreducer.o mapper.o merge.o helper.o
	$(CC) -o mapred	main.o	mapreducer.o mapper.o merge.o helper.o -lpthread
main.o:	main.c
	$(CC) -c main.c -lpthread
mapreducer.o: mapreducer.c mapreducer.h
	$(CC) -c mapreducer.c -lpthread
mapper.o:  mapper.c mapper.h
	$(CC) -c mapper.c -lpthread
merge.o:  merge.c merge.h
	$(CC) -c merge.c -lpthread	
helper.o: helper.c helper.h
	$(CC) -c helper.c -lpthread
clean:
	rm -f *~ *.o mapred