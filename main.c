#include <stdio.h>

#include "linked_list.h"

int main() {
  song_node *list = NULL;
  list = insert_front(list, "My house", "Alice");
  print_node(list);
  
  return 0;
}
