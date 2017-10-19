#include "linked_list.h"

#include <stddef.h>

void music_lib_add_song(char* name, char* artist);

song_node* music_lib_search_for_song(char* name, char* artist);

song_node* music_lib_search_for_artist(char* artist);

void music_lib_print_entries_with_first_letter(char letter);

void music_lib_print_songs_of_artist(char* artist);

void music_lib_print_whole_library();

void music_lib_shuffle(size_t number_to_print);

void music_lib_delete_song(char* name, char* artist);

void music_lib_delete_whole_library();
