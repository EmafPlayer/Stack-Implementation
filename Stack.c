#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE_STACK 5

struct Stack {
    int top;
    int stack[MAX_SIZE_STACK];
} typedef Stack;

bool isEmpty (Stack *pstack){
    return pstack->top == -1;
}

void push (Stack *pstack, int newElement){
    if(pstack->top < MAX_SIZE_STACK - 1)
        pstack->stack[++pstack->top] = newElement;
    else
        printf("ERROR: Stack Overflow!\n");
}

int pop (Stack *pstack){
    if(!isEmpty(pstack))
        return pstack->stack[pstack->top--];
    else {
        printf("ERROR: Stack Underflow!\n");
        return -1;
    }
}

int top (Stack *pstack){
    if(!isEmpty(pstack))
        return pstack->stack[pstack->top];
    else {
        printf("Não há nenhum elemento no top da Pilha");
        return -1;
    }    
}

void printPilha (Stack stack){
    if(!isEmpty(&stack)){
        while(!isEmpty(&stack)){
            printf("%dº Elemento - %d\n", stack.top + 1, stack.stack[stack.top]);
            stack.top--;
        }
    } else
        printf("A Pilha está vázia!\n");
}

void dup (Stack *pstack){
    if(!isEmpty(pstack))
        push(pstack,pstack->stack[pstack->top]);
    else
        printf("A Pilha está vázia!\n");
}

void count (Stack stack){
    int count = 0;
    if(!isEmpty(&stack)){
        while(!isEmpty(&stack)){
            pop(&stack);
            count++; 
        }
        printf("A pilha possui %d elementos!\n", count);
    } else
        printf("A pilha está vázia!\n");
}


int main() {
    
    Stack stack;
    stack.top = -1;
    int value = 0;
    
    /*
    if(isEmpty(&stack)) 
        printf("A pilha está vazia!\n");
    else 
        printf("A pilha possui elementos!\n");
    */
        
    // push(&stack,10);
    // push(&stack,7);
    // printf("Valor guardado = %d\n", pop(&stack));
    // push(&stack,87);
    // push(&stack,40);
    // printf("top stack = %d\n", top(&stack));
    // push(&stack,12);
    // dup(&stack);
    // dup(&stack);
    // printPilha(stack);
    // count(stack);

    return 0;
}