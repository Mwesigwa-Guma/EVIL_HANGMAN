CC = gcc
CFLAGS =-Wall --std=c99 -g
OBJECTS = main.o my_string.o generic_vector.o associative_array.o

all: hello unit_test

hello:$(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)

unit_test: my_string.o unit_test.o test_def.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_def.o my_string.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

unit_test.o: unit_test.c unit_test.h
	$(CC) $(CFLAGS) -c unit_test.c  -o unit_test.o

test_def.o: test_def.c unit_test.h
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o

status.o: status.h
	$(CC) $(CFLAGS) -c status.h -o status.o	

generic_vector.o: generic_vector.c generic_vector.h
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o

associative_array.o: associative_array.c associative_array.h
	$(CC) $(CFLAGS) -c associative_array.c -o associative_array.o

clean:
	rm string_driver unit_test unit_test.o test_def.o $(OBJECTS)
