#include <stdio.h>

#include "linked_list.h"

int main() {
  printf("LINKED LIST TESTS\n\n");

  //insert_front and insert_in_order
  song_node *list = insert_front(NULL, "My house", "Alice");
  printf("print_node:\n");
  print_node(list);

  
  list = insert_in_order(list, "Cars", "Alice");
  list = insert_in_order(list, "SBCL", "Steele");
  printf("print_list:\n");
  print_list(list);

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
