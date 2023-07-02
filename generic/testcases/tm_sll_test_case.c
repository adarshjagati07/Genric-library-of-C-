#include <tm_sll.h>
#include<stdio.h>
int main()
{
SinglyLinkedList *list1;
SinglyLinkedListIterator iter;
bool succ;
int i1,i2,i3,i4,i5,i6,i7,i8,*x,y;
list1= createSinglyLinkedList(&succ);
printf("List created\n");
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;
i7=10000;
i8=20000;
addToSinglyLinkedList(list1,(void *)&i1,&succ);
addToSinglyLinkedList(list1,(void *)&i2,&succ);
addToSinglyLinkedList(list1,(void *)&i3,&succ);
addToSinglyLinkedList(list1,(void *)&i4,&succ);
addToSinglyLinkedList(list1,(void *)&i5,&succ);
addToSinglyLinkedList(list1,(void *)&i6,&succ);
insertIntoSinglyLinkedList(list1,0,&i5,&succ);
insertIntoSinglyLinkedList(list1,3,&i7,&succ);
insertIntoSinglyLinkedList(list1,7,&i8,&succ);

iter= getSinglyLinkedListIterator(list1,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iter))
{
x=(int *)getNextElementFromSinglyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}

destroySinglyLinkedList(list1);
return 0;
}