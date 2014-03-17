CC = g++
all:	mapred
mapred:
	$(CC) -o mapred mapred.cpp

clean:
	rm -f *~ *.o mapred