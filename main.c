#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  
  list_t* linked_list = list_alloc();
  
  list_add_to_back(linked_list, 1);
  list_add_to_back(linked_list, 2);
  list_add_to_back(linked_list, 3);
  list_add_to_back(linked_list, 4);
  list_add_to_back(linked_list, 5);
  list_add_to_back(linked_list, 6);
  list_add_to_back(linked_list, 7);
  list_add_to_back(linked_list, 8);
  list_add_to_back(linked_list, 9);
  
  list_print(linked_list);
  
  list_add_to_front(linked_list, 10);
  list_add_to_front(linked_list, 11);
  list_add_to_front(linked_list, 12);
  list_add_to_front(linked_list, 13);
  list_add_to_front(linked_list, 14);
  list_add_to_front(linked_list, 15);
  list_add_to_front(linked_list, 16);
  list_add_to_front(linked_list, 17);
  
  list_print(linked_list);

  list_add_at_index(linked_list, 18, 3);
  list_add_at_index(linked_list, 19, 3);
  list_add_at_index(linked_list, 20, 3);
  list_add_at_index(linked_list, 21, 3);
  list_add_at_index(linked_list, 22, 3);
  list_add_at_index(linked_list, 23, 3);
  list_add_at_index(linked_list, 24, 3);

  list_print(linked_list);
  
  printf("17 is at %d \n", list_get_index_of(linked_list, 17));
  printf("15 is at %d \n", list_get_index_of(linked_list, 15));
  printf("24 is at %d \n", list_get_index_of(linked_list, 24));
  printf("11 is at %d \n", list_get_index_of(linked_list, 24));

  printf("position 3: %d \n", list_get_elem_at(linked_list, 0));
  printf("position 3: %d \n", list_get_elem_at(linked_list, 2));
  printf("position 3: %d \n", list_get_elem_at(linked_list, 4));
  printf("position 3: %d \n", list_get_elem_at(linked_list, 6));

  printf("5 is in the list: %d \n", list_is_in(linked_list, 5));
  printf("5 is in the list: %d \n", list_is_in(linked_list, 23));
  printf("5 is in the list: %d \n", list_is_in(linked_list, 14));
  printf("5 is in the list: %d \n", list_is_in(linked_list, 500));
  printf("5 is in the list: %d \n", list_is_in(linked_list, 534));
  
  list_remove_from_back(linked_list);
  list_remove_from_back(linked_list);
  list_remove_from_back(linked_list);
  list_remove_from_back(linked_list);

  list_print(linked_list);

  list_remove_from_front(linked_list);
  list_remove_from_front(linked_list);
  list_remove_from_front(linked_list);
  list_remove_from_front(linked_list);

  list_print(linked_list);

  list_remove_at_index(linked_list, 2);
  list_remove_at_index(linked_list, 2);
  list_remove_at_index(linked_list, 2);
  list_remove_at_index(linked_list, 2);
  
  list_print(linked_list);
  
  list_free(linked_list);
  return 0;
}
