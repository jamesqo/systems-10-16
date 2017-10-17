#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

song_node* insert_front(song_node* list, char* name, char* artist) {
  song_node *new = (song_node *)malloc(sizeof(song_node));
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  return new;
}

song_node* insert_in_order(song_node* list, char* name, char* artist) {

}

void print_list(song_node* list){
  while (list) {
    print_node(list);
    list = list->next;
  }
  printf("NULL\n");
}

song_node* search_for_name(song_node* list, char* name){
  
}

song_node* search_for_artist(song_node* list, char* artist){
  while (list) {
    if (strcmp(list->artist, artist) == 0)
      return list;
    list = list->next;
  }
  //node couldn't be found
  return NULL;
}

song_node* random_song(song_node* list){
  
}

song_node* remove_node(song_node* list, song_node* to_remove){
  
}

song_node* free_list(song_node* list){
  
}
