#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
   const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* list = (List*) calloc(1,sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    return list;
}

void * firstList(List * list) {
    
    if(list->head && list->head->data){
      list->current = list->head;
      void* dato = (void*) list->current->data;
      return dato;
    }
    return NULL;
}

void * nextList(List * list) {
    
    if(list->current==NULL){
      return NULL;
    }
    
    if(list->current->next!=NULL && list->current!=NULL){
       list->current=list->current->next;
       void* dato = (void*) list->current->data; 
    return dato;
    
    }

    
    return NULL;
  
    
}

void * lastList(List * list) {
  

   
    list->current=list->tail;
    void* dato = (void*) list->current->data;
    return dato;
   
    
}

void * prevList(List * list) {
    if(list->current==NULL){
      return NULL;
    }
    
    if(list->current->prev!=NULL && list->current!=NULL){
       list->current=list->current->prev;
       void* dato = (void*) list->current->data;
    return dato;
    
    }

    
    return NULL;
  
}

void pushFront(List * list, const void * data) {

  

}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {

}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    void* dato = (void*) list->current->data;
    list->current->prev->next=list->current->next;
    free (list->current);
    
    return dato;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}