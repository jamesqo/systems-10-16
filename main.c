#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "music_lib.h"

void linked_list_tests() {
  printf("LINKED LIST TESTS\n\n");

  //insert_front, print_node
  song_node *list = insert_front(NULL, "My house", "Alice");
  printf("print_node:\n");
  print_node(list);

  //insert_in_order, print_list
  list = insert_in_order(list, "Cars", "Alice");
  list = insert_in_order(list, "CL", "Steele");
  list = insert_in_order(list, "Python", "Rossum");
  list = insert_in_order(list, "C++", "Bjorne");
  printf("print_list:\n");
  print_list(list);

  //search_for_song
  printf("search_for_song:\n");
  song_node *song = search_for_song(list, "My house", "Alice");
  if (song) {
    printf("Song found\n");
    print_node(song);
  }
  song = search_for_song(list, "Dogs", "Alice");
  if (!song) {
    printf("Song not found\n\n");
  }

  //search_for_artist
  printf("search_for_artist:\n");
  song = search_for_artist(list, "Steele");
  if (song) {
    printf("Song found\n");
    print_node(song);
  }
  song = search_for_artist(list, "Joe");
  if (!song) {
    printf("Song not found\n\n");
  }

  //random_song
  printf("random_song:\n");
  print_node(random_song(list));
  print_node(random_song(list));
  print_node(random_song(list));

  //remove_song
  printf("remove_song:\n");
  printf("before:\n");
  print_list(list);
  list = remove_song(list, "Cars", "Alice");
  printf("after:\n");
  print_list(list);
  list = remove_song(list, "Dogs", "Alice"); //no song to remove
  printf("after:\n");
  print_list(list);

  //free_list
  printf("free_list:\n");
  list = free_list(list);
  printf("%p\n\n", list);

  //songcmp
  song_node *n1 = insert_front(NULL, "C++", "Bjorne");
  song_node *n2 = insert_front(NULL, "C*", "Steel");
  song_node *n3 = insert_front(NULL, "CL", "Steel");
  printf("songcmp:\n");
  printf("%d\n", songcmp(n1, n2));
  printf("%d\n", songcmp(n2, n1));
  printf("%d\n", songcmp(n2, n3));
  printf("%d\n\n", songcmp(n3, n2));

  //length
  printf("length:\n");
  printf("%d\n", length(NULL));
  printf("%d\n", length(n1));
  n1->next = n2;
  printf("%d\n", length(n1));
  n2->next = n3;
  printf("%d\n", length(n1));

  free_list(n1);
}

void music_lib_tests() {
  printf("MUSIC LIB TESTS\n\n");

  printf("Testing add_song:\n");
  music_lib_add_song("classical Music title", "mozArt");
  music_lib_add_song("blAnk space", "taylor sWift");
  music_lib_add_song("suGar", "Maroon 5");

  printf("Testing search_for_song:\n");
  song_node* sfs_result = music_lib_search_for_song("CLASSICAL MUSIC TITLE", "Mozart");
  print_node(sfs_result);

  printf("Testing search_for_artist:\n");
  song_node* sfa_result = music_lib_search_for_artist("mOzart");
  print_node(sfa_result);

  printf("Testing print_entries_with_first_letter:\n");
  music_lib_print_entries_with_first_letter('M');
  music_lib_print_entries_with_first_letter('T');

  printf("Testing print_songs_of_artist:\n");
  music_lib_print_songs_of_artist("MOZART");
  music_lib_print_songs_of_artist("TAYLOR SWIFT");
  music_lib_print_songs_of_artist("MAROON 5");

  printf("Testing print_whole_library:\n");
  music_lib_print_whole_library();

  printf("Testing shuffle:\n");
  music_lib_shuffle(1);
  music_lib_shuffle(1);

  music_lib_shuffle(2);
  music_lib_shuffle(2);

  music_lib_shuffle(3);
  music_lib_shuffle(3);

  printf("Testing delete_song:\n");
  music_lib_delete_song("clAssical music title", "moZart");
  printf("After delete_song, this is the whole library:\n");
  music_lib_print_whole_library();

  printf("Testing delete_whole_library:\n");
  music_lib_delete_whole_library();
  printf("After delete_whole_library, this is the whole library:\n");
  music_lib_print_whole_library();
}

int main() {
  srand(time(NULL));

  linked_list_tests();
  music_lib_tests();

  return 0;
}
