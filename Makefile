DEBUG:=false
CFLAGS:=-Wall -Werror
ifeq ($(DEBUG),true)
	CFLAGS:=$(CFLAGS) -g
endif

all: main

main: main.o music_lib.o linked_list.o
	gcc -o main main.o music_lib.o linked_list.o

main.o: main.c linked_list.h music_lib.h
	gcc $(CFLAGS) -c main.c

music_lib.o: music_lib.c music_lib.h linked_list.h
	gcc $(CFLAGS) -c music_lib.c

linked_list.o: linked_list.c linked_list.h
	gcc $(CFLAGS) -c linked_list.c

clean:
	rm *.o main

run: all
	./main
