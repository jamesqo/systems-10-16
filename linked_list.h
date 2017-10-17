typedef struct song_node { 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node* insert_front(song_node* list, char* name, char* artist);

song_node* insert_in_order(song_node* list, char* name, char* artist);

void print_list(song_node* list);

song_node* search_for_name(song_node* list, char* name);

song_node* search_for_artist(song_node* list, char* artist);

song_node* random_song(song_node* list);

song_node* remove_node(song_node* list, song_node* to_remove);

song_node* free_list(song_node* list);