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
    Node* x=createNode(data);
    if(list->head==NULL){
      list->head=x;
    }
     if(list->tail==NULL){
      list->tail=x;
    }
    list->head->prev=x;
    x->next=list->head;
    list->head=x;

}

void pushBack(List * list, const void * data) {
    Node* x=createNode(data);
    if(list->head==NULL){
      list->head=x;
    }
    list->tail->next=x;
    x->prev=list->tail;
    list->tail=x;
}

void pushCurrent(List * list, const void * data) {
  list->current->next=list->current;
  list->current->data=data;
  list->current->prev=list->current;
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
  if(list->current==list->head){
    list->head=list->head->next;
    list->head->prev=NULL;
    list->current=NULL;

    free(list->current);
    
  }


  return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}