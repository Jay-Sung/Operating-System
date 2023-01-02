CC = g++
all : fig316_producer.o fig317.o
		$(CC) -o producer_execute fig316_producer.o
		$(CC) -o consumer_execute  fig317.o
build : fig316_producer.c fig317.c
		$(CC) -c fig316_producer.o fig316_producer.c -lrt
		$(CC) -c fig317.o fig317.c -lrt
clean :
		rm  *.o consumer_execute producer_execute

