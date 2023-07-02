#include<tm_avl_tree.h>
#include<stdio.h>
#include<stdlib.h>
int myComparator(void *left,void *right)
{
int *leftInt, *rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return(*leftInt)-(*rightInt);
}
int main()
{
AVLTreeInOrderIterator inOrderIterator;
AVLTreePreOrderIterator preOrderIterator;
AVLTreePostOrderIterator postOrderIterator;
char more;
int *x;
int ch;
int num;
AVLTree *tree;
int success;
tree=createAVLTree(&success,myComparator);
if(success==false)
{
printf("Unable to create tree, low on memory\n");
return 0;
}
while(1)
{
printf("1. Insert\n");
printf("2. In Order Traversal\n");
printf("3. Remove \n");
printf("4. Search\n");
printf("5. Height of AVLTree\n");
printf("6. Pre Order Traversal\n");
printf("7. Post Order Traversal\n");
printf("8. Exit\n");
printf("Select from the above operations : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter number to be inserted in tree : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertIntoAVLTree(tree, (void *)x, &success);
if(success) printf("Address of item that contain %d inserted in tree\n",*x);
else printf("Unable to insert in tree\n");
}
if(ch==2)
{
printf("In order Iteration starts\n");
inOrderIterator=getAVLTreeInOrderIterator(tree,&success);
if(success)
{
while(hasNextInOrderElementInAVLTree(&inOrderIterator))
{
x=(int *)getNextInOrderElementFromAVLTree(&inOrderIterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==3)
{
printf("Enter the number to be removed : ");
scanf("%d",&num);
fflush(stdin);
x=removeFromAVLTree(tree,&num,&success);
if(success) printf("%d found and removed\n",*x);
else printf("%d not found\n",num);
}
if(ch==4)
{
printf("Enter the number to be searched : ");
scanf("%d",&num);
fflush(stdin);
x=getFromAVLTree(tree,&num,&success);
if(success) printf("%d found\n",*x);
else printf("%d not found\n",num);
}
if(ch==5)
{
int height= getHeightOfAVLTree(tree->start);
printf("Height of AVL Tree is : %d\n",height);
}
if(ch==6)
{
printf("Pre order Iteration starts\n");
preOrderIterator=getAVLTreePreOrderIterator(tree,&success);
if(success)
{
while(hasNextPreOrderElementInAVLTree(&preOrderIterator))
{
x=(int *)getNextPreOrderElementFromAVLTree(&preOrderIterator,&success);
printf("%d\n",*x);
}
}
}

if(ch==7)
{
printf("Post order Iteration starts\n");
postOrderIterator=getAVLTreePostOrderIterator(tree,&success);
if(success)
{
while(hasNextPostOrderElementInAVLTree(&postOrderIterator))
{
x=(int *)getNextPostOrderElementFromAVLTree(&postOrderIterator,&success);
printf("%d\n",*x);
}
}
}

if(ch==8) break;
}

destroyAVLTree(tree);
return 0;
}