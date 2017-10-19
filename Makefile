all: main

main: main.o
	gcc -o main main.o

main.o: main.c linked_list.h music_lib.h
	gcc -c main.c

music_lib.o: music_lib.c music_lib.h linked_list.h
	gcc -c music_lib.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

clean:
	rm *.o main

run: all
	./main
