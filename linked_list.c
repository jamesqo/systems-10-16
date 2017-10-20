#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

void print_node(song_node *node) {
  if (!node) {
    printf("null node\n\n");
    return;
  }

  printf("name: %s\nartist: %s\n\n", node->name, node->artist);
}

song_node* insert_front(song_node* list, char* name, char* artist) {
  song_node *new = (song_node *)malloc(sizeof(song_node));
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = list;
  return new;
}

//return front of list
song_node* insert_in_order(song_node* list, char* name, char* artist) {
  song_node *new = insert_front(NULL, name, artist);

  song_node *last = NULL;
  song_node *node = list;
  while (node && songcmp(node, new) < 0) {
    last = node;
    node = node->next;
  }
  //node points to node after where new should be
  
  //last is still null -> new is the front
  if (!last) {
    new->next = list;
    return new;
  }
  new->next = node;
  last->next = new;
  return list;
}

void print_list(song_node* list) {
  while (list) {
    print_node(list);
    list = list->next;
  }
}

song_node* search_for_song(song_node* list, char* name, char* artist) {
  while (list) {
    if (strcmp(list->name, name) == 0 &&
        strcmp(list->artist, artist) == 0)
      return list;
    list = list->next;
  }
  return NULL;
}

song_node* search_for_artist(song_node* list, char* artist) {
  while (list) {
    if (strcmp(list->artist, artist) == 0)
      return list;
    list = list->next;
  }
  //node couldn't be found
  return NULL;
}

song_node* random_song(song_node* list) {
  if (!list) {
    return NULL;
  }

  //assume srand called
  int num = rand() % length(list);
  while (list) {
    if (num == 0)
      return list;
    num--;
    list = list->next;
  }
  //list is null in the first place
  return NULL;
}

//return front of list
song_node* remove_song(song_node* list, char* name, char* artist) {
  song_node *last = NULL;
  song_node *node = list;
  while (node) {
    if (strcmp(node->name, name) == 0 &&
        strcmp(node->artist, artist) == 0) {
      //song to remove is the front of list?
      if (last == NULL)
        list = list->next;
      else
        last->next = node->next;
      //free node too
      free(node);
      return list;
    }
    last = node;
    node = node->next;
  }
  //couldn't find it...
  return list;
}

//return pointer to beginning of list (null)
song_node* free_list(song_node* list) {
  while (list) {
    song_node *next = list->next;
    free(list);
    list = next;
  }
  return NULL;
}

int songcmp(song_node* node1, song_node* node2) {
  //compare artist, then compare name
  int artistcmp = strcmp(node1->artist, node2->artist);
  if (artistcmp)
    return artistcmp;
  return strcmp(node1->name, node2->name);
}

int length(song_node *list) {
  int len = 0;
  while (list) {
    len++;
    list = list->next;
  }
  return len;
}
