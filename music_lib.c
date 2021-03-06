#include "music_lib.h"

#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

song_node* table[26];

song_node* get_entries(char letter) {
  return table[tolower(letter) - 'a'];
}

void set_entries(char letter, song_node* value) {
  table[tolower(letter) - 'a'] = value;
}

size_t number_of_non_empty_lists() {
  size_t result = 0;

  size_t i;
  for (i = 0; i < 26; i++) {
    if (table[i]) {
      result++;
    }
  }
  
  return result;
}

song_node* nth_non_empty_list(size_t n) {
  size_t i;
  for (i = 0; i < 26; i++) {
    if (table[i]) {
      if (n == 0) {
        return table[i];
      }

      n--;
    }
  }

  // This should not happen, but...
  return NULL;
}

char* make_lower(char* str) {
  // Make a copy since str may point to readonly memory
  // Please free the result of this fn.
  size_t buf_len = strlen(str) + 1;
  char* new_str = malloc(sizeof(char) * buf_len);
  size_t i;
  for (i = 0; i < buf_len; i++) {
    new_str[i] = tolower(str[i]);
  }
  return new_str;
}

song_node* get_random_song() {
  // Assumes srand was called
  size_t n = rand() % number_of_non_empty_lists();
  song_node* entries = nth_non_empty_list(n);
  return random_song(entries);
}

void music_lib_add_song(char* name, char* artist) {
  name = make_lower(name);
  artist = make_lower(artist);
  
  song_node* entries = get_entries(artist[0]);
  set_entries(artist[0], insert_in_order(entries, name, artist));

  free(name);
  free(artist);
}

song_node* music_lib_search_for_song(char* name, char* artist) {
  name = make_lower(name);
  artist = make_lower(artist);
  
  song_node* entries = get_entries(artist[0]);
  song_node* result = search_for_song(entries, name, artist);

  free(name);
  free(artist);

  return result;
}

song_node* music_lib_search_for_artist(char* artist) {
  artist = make_lower(artist);
  
  song_node* entries = get_entries(artist[0]);
  song_node* result = search_for_artist(entries, artist);

  free(artist);

  return result;
}

void music_lib_print_entries_with_first_letter(char letter) {
  song_node* entries = get_entries(letter);
  print_list(entries);
}

void music_lib_print_songs_of_artist(char* artist) {
  artist = make_lower(artist);
  
  song_node* entries = get_entries(artist[0]);
  while (entries) {
    entries = search_for_artist(entries, artist);
    if (entries) {
      print_node(entries);
      entries = entries->next;
    }
  }

  free(artist);
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
  name = make_lower(name);
  artist = make_lower(artist);
  
  song_node* entries = get_entries(artist[0]);
  set_entries(artist[0], remove_song(entries, name, artist));

  free(name);
  free(artist);
}

void music_lib_delete_whole_library() {
  char letter;
  for (letter = 'a'; letter <= 'z'; letter++) {
    song_node* entries = get_entries(letter);
    set_entries(letter, free_list(entries));
  }
}
