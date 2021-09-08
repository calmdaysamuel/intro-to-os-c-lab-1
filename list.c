// list/list.c
//
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() 
{ 
    list_t *l = malloc(sizeof(list_t));
    return l;
}

void list_free(list_t *l) 
{
    while( l->head != NULL) 
    {
        node_t * temp = l->head;
        l->head = l->head->next;

        free(temp);
    }

    return;
}

void list_print(list_t *l)
{
  node_t* copy = l->head;
    while (l->head != NULL)
    {

        printf("%d -> ", l->head->value);
        l->head = l->head->next;
    }

    l->head = copy;
    printf("\n");
}

int list_length(list_t *l)
{
    node_t* copy = l->head;
    int count = 0;
    while (l->head != NULL)
    {

        count += 1;
        l->head = l->head->next;
        
    }
    l->head = copy;
    return count;
}

void list_add_to_back(list_t *l, elem value) 
{
  
    node_t* copy = l->head;
    if(l->head == NULL) 
    {
      node_t *new_node = malloc(sizeof(node_t));
      new_node->value = value;
      l->head = new_node;
      return;
    } else 
    {
      while(l->head->next != NULL) 
      {
          l->head = l->head->next;
          
      }
      node_t *new_node = malloc(sizeof(node_t));
      new_node->value = value;
      l->head->next = new_node;
    }
    
    l->head = copy;
    return;
}

void list_add_to_front(list_t *l, elem value) 
{
    node_t *new_head = malloc(sizeof(node_t));
    new_head->value = value;
    new_head->next = l->head;
    l->head = new_head;
}

void list_add_at_index(list_t *l, elem value, int index)
{
    node_t* copy = l->head;
    if(index == 0) 
    {
        list_add_to_front(l, value);
        return;
    }

    if(index == list_length(l) - 1) 
    {
        list_add_to_back(l, value);
        return;
    }


    if (index >= list_length(l) ) {
        return;
    }
    while(index != 1) 
    {
        index -= 1;
        l->head = l->head->next;
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = l->head->next;
    l->head->next = new_node;


    l->head = copy;
}

elem list_remove_from_back(list_t *l) 
{ 
    node_t* copy = l->head;
    if (list_length(l) == 1)
    {
        list_remove_from_front(l);
    }
    
    while(l->head->next->next != NULL) 
    {
        l->head = l->head->next;
    }
    free(l->head->next);
    l->head->next = NULL;
    l->head = copy;
    return 1;
}

elem list_remove_from_front(list_t *l) {
    
  node_t *temp = l->head;
  l->head = l->head->next;

  free(temp);
  return l->head->value;
}
elem list_remove_at_index(list_t *l, int index) 
{ 
  node_t* copy = l->head;
    
  while(index != 1) 
  {
      index -= 1;
      l->head = l->head->next;
  }
  node_t* temp = l->head->next;
  l->head->next  = l->head->next->next;
  l->head = copy;

  free(temp);
  return -1;
}

bool list_is_in(list_t *l, elem value)
{
  node_t* copy = l->head;
  while (l->head != NULL)
  {

      if (l->head->value != value)
      {
          l->head = l->head->next;
      }
      else
      {
          l->head = copy;
          return true;
      }
  }
  l->head = copy;
  return false;
}
elem list_get_elem_at(list_t *l, int index)
{
  node_t* copy = l->head;
  while (l->head != NULL)
  {

    if (index != 0)
    {
        l->head = l->head->next;
    }
    else
    {
        int temp = l->head->value;
        l->head = copy;
        return temp;
    }
    index -= 1;
  }
  l->head = copy;
  return -1;
}

int list_get_index_of(list_t *l, elem value)
{
  node_t* copy = l->head;
  int count = 0;
  while (l->head != NULL)
  {

      if (l->head->value != value)
      {
          l->head = l->head->next;
          count += 1;
      }
      else
      {
          l->head = copy;
          return count;
      }
  }
  l->head = copy;
  return -1;
}
