#ifndef __TM_DLL__C
#define __TM_DLL__C 1234

#include<tm_dll.h>
#include<stdlib.h>
DoublyLinkedList * createDoublyLinkedList(bool *success)
{
if(success) *success=true;
DoublyLinkedList *doublyLinkedList;
doublyLinkedList=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
if(doublyLinkedList==NULL) return NULL;
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
if(success) *success=true;
return doublyLinkedList;
}
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL) return;
clearDoublyLinkedList(doublyLinkedList); //its work is to remove all the nodes in a doublyLinkedList
free(doublyLinkedList);     //its work is to free doublyList node(main node)

}

int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL) return 0;
return doublyLinkedList->size;
}

void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
DoublyLinkedListNode *node;
if(doublyLinkedList==NULL) return;
node=(DoublyLinkedListNode *)doublyLinkedList->start;
while(doublyLinkedList->start!=NULL)
{
node=(DoublyLinkedListNode *)doublyLinkedList->start;
doublyLinkedList->start=doublyLinkedList->start->next;
free(node);  //it is like popping from the stack and changing the value of top
}
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
}

void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success)
{
DoublyLinkedListNode *node;
if(success) *success=false;
if(doublyLinkedList==NULL) return;
node = (DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
node->previous=NULL;
if(doublyLinkedList->start==NULL) //this is the first node
{
doublyLinkedList->start=node;
doublyLinkedList->end=node;
}
else
{
doublyLinkedList->end->next=node;
node->previous=doublyLinkedList->end;
doublyLinkedList->end=node;
}
doublyLinkedList->size++;
if(success) *success=true;
}


/*
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int index, void *ptr, bool *success)
{
DoublyLinkedListNode *node,*p1,*p2;
int x;
if(success) *success=false;
if(index<0 || index>doublyLinkedList->size) return;
if(doublyLinkedList==NULL) return;
node = (DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->ptr = ptr;
node->next=NULL;
if(index==doublyLinkedList->size)
{
doublyLinkedList->end->next=node;
doublyLinkedList->end=node;
}
if(index==0)
{
node->next=doublyLinkedList->start;
doublyLinkedList->start=node;
doublyLinkedList->size++;
if(success) *success=true;
return;
}
p1=doublyLinkedList->start;
x=0;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
node->next=p1;
p2->next=node;
doublyLinkedList->size++;
if(success) *success=true;
}

void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int index, bool *success)
{
void *ptr;
int x;
DoublyLinkedListNode *p1,*p2;
if(success) *success=false;
if(doublyLinkedList==NULL) return NULL;
if(index<0 || index>=doublyLinkedList->size) return NULL;
p1=doublyLinkedList->start;
x=0;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(doublyLinkedList->start==p1 && doublyLinkedList->end==p1)
{
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
}else if(doublyLinkedList->start==p1)
{
doublyLinkedList->start=doublyLinkedList->start->next;
}else if(doublyLinkedList->end==p1)
{
doublyLinkedList->end=p2;
p2->next=NULL;
}
else
{
p2->next=p1->next;
}
free(p1);
doublyLinkedList->size--;
if(success) *success=true;
return ptr;
}

void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList, DoublyLinkedList *sourceDoublyLinkedList, bool *success)
{
DoublyLinkedListNode *s,*e,*t,*node;
bool done;  //we have taken a flag variable
if(success) *success=false;
if(targetDoublyLinkedList==NULL) return;
if(sourceDoublyLinkedList==NULL || sourceDoublyLinkedList->size==0)
{
          //if this is the case then we will simply say we have appended the list
if(success) *success=true; 
return;
}
s=NULL;  //this is for maintaing our addtional doublylinkedlist, that we are going to attach with our target doublylinkedlist
e=NULL;
done=true;
t=sourceDoublyLinkedList->start;
while(t!=NULL)
{
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=t->ptr;
node->next=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
e=node;
}

t=t->next;
}
if(done==false)
{
while(s!=NULL)  //if memory not allocated according for all the nodes then we will release the memory of all the nodes
{
node=s;
s=s->next;
free(node);
}
return;
}

if(targetDoublyLinkedList->start==NULL)  //when our target list is empty
{
targetDoublyLinkedList->start=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size=sourceDoublyLinkedList->size;
}
else
{
targetDoublyLinkedList->end->next=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size+=sourceDoublyLinkedList->size;
}
if(success) *success=true;
}

*/

void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int index, bool *success)
{
DoublyLinkedListNode *p1;
int x;
if(success) *success=false;
if(doublyLinkedList==NULL) return NULL;
if(index<0 || index>=doublyLinkedList->size) return NULL;
x=0;
p1= doublyLinkedList->start;
while(x<index)
{
p1=p1->next;
x++;
}
if(success) *success=true;
return p1->ptr;
}

/*
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList, bool *success)
{
DoublyLinkedListIterator doublyLinkedListIterator;
doublyLinkedListIterator.node=NULL;
if(success) *success=false;
if(doublyLinkedList==NULL) return doublyLinkedListIterator;
if(doublyLinkedList->start==NULL)
{
if(success) *success=true;
return doublyLinkedListIterator;
}
if(success) *success=true;
doublyLinkedListIterator.node=doublyLinkedList->start;
return doublyLinkedListIterator;
}

bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator)
{
if(doublyLinkedListIterator==NULL) return false;
if(doublyLinkedListIterator->node==NULL) return false;
return true;
}

void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator, bool *success)
{
void *ptr=NULL;
if(success) *success= false;
if(doublyLinkedListIterator==NULL || doublyLinkedListIterator->node==NULL) return ptr;
ptr=doublyLinkedListIterator->node->ptr;
doublyLinkedListIterator->node=doublyLinkedListIterator->node->next;
if(success) *success=true;
return ptr;
}

*/

#endif