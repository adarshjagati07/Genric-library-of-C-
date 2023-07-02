#include <tm_dll.h>
#include<stdio.h>
int main()
{
DoublyLinkedList *list1;
DoublyLinkedListIterator iter;
bool succ;
int i1,i2,i3,i4,i5,i6,*x,y;
int i;
list1= createDoublyLinkedList(&succ);
printf("List created\n");
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;
addToDoublyLinkedList(list1,(void *)&i1,&succ);
addToDoublyLinkedList(list1,(void *)&i2,&succ);
addToDoublyLinkedList(list1,(void *)&i3,&succ);
addToDoublyLinkedList(list1,(void *)&i4,&succ);
addToDoublyLinkedList(list1,(void *)&i5,&succ);
addToDoublyLinkedList(list1,(void *)&i6,&succ);

for(int i=0; i<getSizeOfDoublyLinkedList(list1);i++)
{
x=(int *)getFromDoublyLinkedList(list1,i,&succ);
printf("%d\n",*x);
}


destroyDoublyLinkedList(list1);
return 0;
}