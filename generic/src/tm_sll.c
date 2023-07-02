#ifndef __TM_SLL__C
#define __TM_SLL__C 1234

#include<tm_sll.h>
#include<stdlib.h>
#include<stdio.h>
SinglyLinkedList * createSinglyLinkedList(bool *success)
{
if(success) *success=true;
SinglyLinkedList *singlyLinkedList;
singlyLinkedList=(SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
if(singlyLinkedList==NULL) return NULL;
singlyLinkedList->start=NULL;
singlyLinkedList->end=NULL;
singlyLinkedList->size=0;
if(success) *success=true;
return singlyLinkedList;
}
void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
if(singlyLinkedList==NULL) return;
clearSinglyLinkedList(singlyLinkedList); //its work is to remove all the nodes in a singlyLinkedList
free(singlyLinkedList);     //its work is to free singlyList node(main node)

}

int getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
if(singlyLinkedList==NULL) return 0;
return singlyLinkedList->size;
}

void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
SinglyLinkedListNode *node;
if(singlyLinkedList==NULL) return;
node=(SinglyLinkedListNode *)singlyLinkedList->start;
while(singlyLinkedList->start!=NULL)
{
node=(SinglyLinkedListNode *)singlyLinkedList->start;
singlyLinkedList->start=singlyLinkedList->start->next;
free(node);  //it is like popping from the stack and changing the value of top
}
singlyLinkedList->end=NULL;
singlyLinkedList->size=0;
}

void addToSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,bool *success)
{
SinglyLinkedListNode *node;
if(success) *success=false;
if(singlyLinkedList==NULL) return;
node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
if(singlyLinkedList->start==NULL) //this is the first node
{
singlyLinkedList->start=node;
singlyLinkedList->end=node;
}
else
{
singlyLinkedList->end->next=node;
singlyLinkedList->end=node;
}
singlyLinkedList->size++;
if(success) *success=true;
}

void insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int index, void *ptr, bool *success)
{
SinglyLinkedListNode *node,*p1,*p2;
int x;
if(success) *success=false;
if(index<0 || index>singlyLinkedList->size) return;
if(singlyLinkedList==NULL) return;
if(index==singlyLinkedList->size)
{
addToSinglyLinkedList(singlyLinkedList,ptr,success);
return; 
}
node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL) return;
node->ptr = ptr;
node->next=NULL;

if(index==0)
{
node->next=singlyLinkedList->start;
singlyLinkedList->start=node;
singlyLinkedList->size++;
if(success) *success=true;
return;
}
p1=singlyLinkedList->start;
x=0;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
node->next=p1;
p2->next=node;
singlyLinkedList->size++;
if(success) *success=true;
}

void * removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int index, bool *success)
{
void *ptr;
int x;
SinglyLinkedListNode *p1,*p2;
if(success) *success=false;
if(singlyLinkedList==NULL) return NULL;
if(index<0 || index>=singlyLinkedList->size) return NULL;
p1=singlyLinkedList->start;
x=0;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(singlyLinkedList->start==p1 && singlyLinkedList->end==p1)
{
singlyLinkedList->start=NULL;
singlyLinkedList->end=NULL;
}else if(singlyLinkedList->start==p1)
{
singlyLinkedList->start=singlyLinkedList->start->next;
}else if(singlyLinkedList->end==p1)
{
singlyLinkedList->end=p2;
p2->next=NULL;
}
else
{
p2->next=p1->next;
}
free(p1);
singlyLinkedList->size--;
if(success) *success=true;
return ptr;
}

void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList, SinglyLinkedList *sourceSinglyLinkedList, bool *success)
{
SinglyLinkedListNode *s,*e,*t,*node;
bool done;  //we have taken a flag variable
if(success) *success=false;
if(targetSinglyLinkedList==NULL) return;
if(sourceSinglyLinkedList==NULL || sourceSinglyLinkedList->size==0)
{
          //if this is the case then we will simply say we have appended the list
if(success) *success=true; 
return;
}
s=NULL;  //this is for maintaing our addtional singlylinkedlist, that we are going to attach with our target singlylinkedlist
e=NULL;
done=true;
t=sourceSinglyLinkedList->start;
while(t!=NULL)
{
node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
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

if(targetSinglyLinkedList->start==NULL)  //when our target list is empty
{
targetSinglyLinkedList->start=s;
targetSinglyLinkedList->end=e;
targetSinglyLinkedList->size=sourceSinglyLinkedList->size;
}
else
{
targetSinglyLinkedList->end->next=s;
targetSinglyLinkedList->end=e;
targetSinglyLinkedList->size+=sourceSinglyLinkedList->size;
}
if(success) *success=true;
}

void * getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int index, bool *success)
{
SinglyLinkedListNode *p1;
int x;
if(success) *success=false;
if(singlyLinkedList==NULL) return NULL;
if(index<0 || index>=singlyLinkedList->size) return NULL;
x=0;
p1= singlyLinkedList->start;
while(x<index)
{
p1=p1->next;
x++;
}
if(success) *success=true;
return p1->ptr;
}

SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList, bool *success)
{
SinglyLinkedListIterator singlyLinkedListIterator;
singlyLinkedListIterator.node=NULL;
if(success) *success=false;
if(singlyLinkedList==NULL) return singlyLinkedListIterator;
if(singlyLinkedList->start==NULL)
{
if(success) *success=true;
return singlyLinkedListIterator;
}
if(success) *success=true;
singlyLinkedListIterator.node=singlyLinkedList->start;
return singlyLinkedListIterator;
}

bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator)
{
if(singlyLinkedListIterator==NULL) return false;
if(singlyLinkedListIterator->node==NULL) return false;
return true;
}

void * getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator, bool *success)
{
void *ptr=NULL;
if(success) *success= false;
if(singlyLinkedListIterator==NULL || singlyLinkedListIterator->node==NULL) return ptr;
ptr=singlyLinkedListIterator->node->ptr;
singlyLinkedListIterator->node=singlyLinkedListIterator->node->next;
if(success) *success=true;
return ptr;
}

#endif