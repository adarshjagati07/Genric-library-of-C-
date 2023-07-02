#ifndef __TM_DLL__H__
#define __TM_DLL__H__ 1234
#include<tm_common.h>

typedef struct __$_tm_dll_node
{
void *ptr;
struct __$_tm_dll_node *next; 
struct __$_tm_dll_node *previous; 
}DoublyLinkedListNode;

typedef struct __$_tm_dll
{
struct __$_tm_dll_node *start;
struct __$_tm_dll_node *end;
int size;
}DoublyLinkedList;

typedef struct __$__tm_dll_iterator
{
DoublyLinkedListNode *node;
}DoublyLinkedListIterator;

typedef struct __$__tm_dll_reverse_iterator
{
DoublyLinkedListNode *node;
}DoublyLinkedListReverseIterator;

DoublyLinkedList * createDoublyLinkedList(bool *success);
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success);
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int index, void *ptr, bool *success);
void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index, bool *success);
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList, DoublyLinkedList *sourceDoublyLinkedList, bool *success);
void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int index, bool *success);
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList, bool *success);
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator);
void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator, bool *success);

DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success);
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator);
void * getPreviousElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator, bool *success);

#endif