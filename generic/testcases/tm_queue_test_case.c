#include<tm_queue.h>
#include<stdio.h>

int main()
{
int succ;
Queue *queue;
int x1,x2,x3,x4;
int *x;
x1=10;
x2=20;
x3=30;
x4=40;
queue = createQueue(&succ);
if(queue==false)
{
printf("Queue cannot be created\n");
return 0;
}
if(isQueueEmpty(queue))
{
printf("Queue is empty\n");
}
addToQueue(queue,&x1,&succ);
if(succ) printf("%d added successfully onto queue\n",x1);
else printf("%d cannot added\n",x1);

addToQueue(queue,&x2,&succ);
if(succ) printf("%d added successfully onto queue\n",x2);
else printf("%d cannot added\n",x2);

addToQueue(queue,&x3,&succ);
if(succ) printf("%d added successfully onto queue\n",x3);
else printf("%d cannot added\n",x3);

addToQueue(queue,&x4,&succ);
if(succ) printf("%d added successfully onto queue\n",x4);
else printf("%d cannot added\n",x4);

printf("Size Of queue is: %d\n",getSizeOfQueue(queue));
x=(int *)elementAtFrontOfQueue(queue, &succ);
printf("Element at Front of queue is %d\n",*x);

if(isQueueEmpty(queue)) printf("Queue is empty\n");
else printf("Queue not empty\n");
printf("Now removing all elements from queue\n");
while(!isQueueEmpty(queue))
{
x=(int *)removeFromQueue(queue,&succ);
printf("%d is removed from queue\n",*x);
}
destroyQueue(queue);
return 0;
}