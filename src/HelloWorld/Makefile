all: program

program: main.o
	gcc main.o -o program

main.o: main.c
	gcc -c main.c

clean:
	rm main.o program