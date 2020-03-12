#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
} Node, *NodePtr;

typedef struct stackType{
    NodePtr top;
} StackType, *Stack;

NodePtr makeNode(int x){
	NodePtr np = new node();
	np->next = NULL;
	np->data = x;
	return np;
}

// BASIC OPERATIONS
Stack initStack(){
	Stack sp = new stackType();
	sp->top = NULL;
	return sp;
}

bool emptyStack(Stack s){
    return s->top == NULL;
}

void push(Stack s, int x){
    NodePtr np = makeNode(x);
    np->next = s->top;
    s->top = np;
}

int pop(Stack s){
    if(emptyStack(s)){
        printf("Stack is empty!\n");
        return -1;
    }
    int data = s->top->data;
    Node *p = s->top;
    s->top = s->top->next;
    free(p);
    return data;
}

int peek(Stack s){
	return s->top->data;
}
//
