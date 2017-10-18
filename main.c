#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

int main() {
  srand(time(NULL));
  
  printf("LINKED LIST TESTS\n\n");

  //insert_front, print_node
  song_node *list = insert_front(NULL, "My house", "Alice");
  printf("print_node:\n");
  print_node(list);

  //insert_in_order, print_list
  list = insert_in_order(list, "Cars", "Alice");
  list = insert_in_order(list, "SBCL", "Steele");
  list = insert_in_order(list, "Python", "Rossum");
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

  
  
  //songcmp
  song_node *n1 = insert_front(NULL, "C", "Bjorne");
  song_node *n2 = insert_front(NULL, "D", "Bjorne");
  song_node *n3 = insert_front(NULL, "A", "Google");
  printf("songcmp:\n");
  printf("%d\n", songcmp(n1, n2));
  printf("%d\n", songcmp(n2, n1));
  printf("%d\n", songcmp(n1, n3));
  printf("%d\n", songcmp(n3, n1));

  
  return 0;
}
