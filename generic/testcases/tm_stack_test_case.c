#include<tm_stack.h>
#include<stdio.h>

int main()
{
int succ;
Stack *stack;
int x1,x2,x3,x4;
int *x;
x1=10;
x2=20;
x3=30;
x4=40;
stack = createStack(&succ);
if(stack==false)
{
printf("Stack cannot be created\n");
return 0;
}
if(isStackEmpty(stack))
{
printf("Stack is empty\n");
}
pushOnStack(stack,&x1,&succ);
if(succ) printf("%d pushed successfully onto stack\n",x1);
else printf("%d cannot pushed\n",x1);

pushOnStack(stack,&x2,&succ);
if(succ) printf("%d pushed successfully onto stack\n",x2);
else printf("%d cannot pushed\n",x1);

pushOnStack(stack,&x3,&succ);
if(succ) printf("%d pushed successfully onto stack\n",x3);
else printf("%d cannot pushed\n",x1);

pushOnStack(stack,&x4,&succ);
if(succ) printf("%d pushed successfully onto stack\n",x4);
else printf("%d cannot pushed\n",x1);

printf("Size Of stack is: %d\n",getSizeOfStack(stack));
x=(int *)elementAtTopOfStack(stack, &succ);
printf("Element at top of stack is %d\n",*x);

if(isStackEmpty(stack)) printf("Stack is empty\n");
else printf("Stack not empty\n");
printf("Now popping all elements from stack\n");
while(!isStackEmpty(stack))
{
x=(int *)popFromStack(stack,&succ);
printf("%d\n",*x);
}
destroyStack(stack);
return 0;
}