#include <stdio.h>
#include <stdbool.h>

#define MAX_PILHA 5

struct Stack {
    int topo;
    int pilha[MAX_PILHA];
} typedef Stack;

bool IsEmpty (Stack *pi){
    if(pi->topo == -1)
        return true;
    else
        return false;
}

bool Push (Stack *pi, int novoElemento){
    if(pi->topo < MAX_PILHA - 1){
        pi->topo++;
        pi->pilha[pi->topo] = novoElemento;
        return false;
    } else {
        printf("ERROR: Stack Overflow!\n");
        return true;
    }
}

bool Pop (Stack *pi, int *p){
    if(!IsEmpty(pi)){
        int Aux = pi->topo;
        pi->topo--;
        *p = pi->pilha[Aux];
        return true;
    } else {
        printf("ERROR: Stack Underflow!\n");
        return false;
    }
}

bool Top (Stack *pi, int *p){
    if(!IsEmpty(pi)){
    *p = pi->pilha[pi->topo];
    return true;
    } else {
    printf("Não há nenhum elemento no topo da Pilha");
    return false;
    }    
}

bool PrintPilha (Stack stack){
    if(!IsEmpty(&stack)){
        while(!IsEmpty(&stack)){
            printf("%dº Elemento - %d\n", stack.topo + 1, stack.pilha[stack.topo]);
            stack.topo--;
        }
        return 1;
    } else {
        printf("A Pilha está vázia!\n");
        return 0;
    }
}

bool Dup (Stack *pi){
    if(!IsEmpty(pi)){
        Push(pi,pi->pilha[pi->topo]);
        return true;
    } else {
        printf("A Pilha está vázia!\n");
        return 0;
    }
}

bool Count (Stack stack){
    int value, count = 0;
    if(!IsEmpty(&stack)){
        while(!IsEmpty(&stack)){
            Pop(&stack, &value);
            count++; 
        }
        printf("A pilha possui %d elementos!\n", count);
        return true;
    } else {
        printf("A pilha está vázia!\n", count);
        return false;
    }
}


int main() {
    
    Stack stack;
    stack.topo = -1;
    int value = 0;
    if(IsEmpty(&stack)) 
        printf("A pilha está vazia!\n");
    else 
        printf("A pilha possui elementos!\n");
    Push(&stack,10);
    Push(&stack,7);
    Pop(&stack,&value);
    printf("Valor guardado = %d\n", value);
    Push(&stack,87);
    Push(&stack,40);
    Top(&stack,&value);
    printf("Valor guardado = %d\n", value);
    Push(&stack,12);
    Dup(&stack);
    Dup(&stack);
    PrintPilha(stack);
    Count(stack);

    return 0;
}