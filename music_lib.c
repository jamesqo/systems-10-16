#include "music_lib.h"

#include <stddef.h>

song_node* table[26];

// TODO: Convert strings to lowercase
// TODO: Write makefile

song_node* get_entries(char letter) {
  return table[letter - 'a'];
}

void music_lib_add_song(char* name, char* artist) {
  song_node* entries = get_entries(artist[0]);
  insert_in_order(entries, name, artist);
}

song_node* music_lib_search_for_song(char* name) {
  char letter;
  for (letter = 'a'; letter <= 'z'; letter++) {
    song_node* entries = get_entries(letter);
    song_node* result = search_for_name(entries, name);
    if (result != NULL) {
      return result;
    }
  }

  return NULL;
}

song_node* music_lib_search_for_artist(char* artist) {
  song_node* entries = get_entries(artist[0]);
  return search_for_artist(entries, artist);
}

void music_lib_print_entries_with_first_letter(char letter) {
  song_node* entries = get_entries(letter);
  print_list(entries);
}

void music_lib_print_songs_of_artist(char* artist) {
  song_node* entries = get_entries(artist[0]);
  while (entries) {
    entries = search_for_artist(entries, artist);
    print_node(entries);
  }
}

void music_lib_print_whole_library() {
}

void music_lib_shuffle() {
}

void music_lib_delete_song(char* name) {
}

void music_lib_delete_whole_library() {
}
