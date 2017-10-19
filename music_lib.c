#include "music_lib.h"

#include <stddef.h>
#include <stdlib.h>

song_node* table[26];

// TODO: Convert strings to lowercase
// TODO: Write makefile

song_node* get_entries(char letter) {
  return table[letter - 'a'];
}

void set_entries(char letter, song_node* value) {
  table[letter - 'a'] = value;
}

song_node* get_random_song() {
  // Assumes srand was called
  char letter = (char)(rand() % 26 + 'a');
  song_node* entries = get_entries(letter);
  return random_song(entries);
}

void music_lib_add_song(char* name, char* artist) {
  song_node* entries = get_entries(artist[0]);
  set_entries(artist[0], insert_in_order(entries, name, artist));
}

song_node* music_lib_search_for_song(char* name, char* artist) {
  song_node* entries = get_entries(artist[0]);
  return search_for_song(entries, name, artist);
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
  char letter;
  for (letter = 'a'; letter <= 'z'; letter++) {
    song_node* entries = get_entries(letter);
    print_list(entries);
  }
}

void music_lib_shuffle(size_t number_to_print) {
  // Assumes srand was called
  size_t i;
  for (i = 0; i < number_to_print; i++) {
    song_node* song = get_random_song();
    print_node(song);
  }
}

void music_lib_delete_song(char* name, char* artist) {
  song_node* entries = get_entries(artist[0]);
  set_entries(artist[0], remove_song(entries, name, artist));
}

void music_lib_delete_whole_library() {
  char letter;
  for (letter = 'a'; letter <= 'z'; letter++) {
    song_node* entries = get_entries(letter);
    set_entries(letter, free_list(entries));
  }
}
