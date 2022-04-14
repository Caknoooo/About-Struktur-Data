#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main()
{
    Stack myStackx, myStacky, myStack;
    stack_init(&myStack);
    stack_init(&myStackx);
    stack_init(&myStacky);
    int t, i, arr[2002], x, n;
    scanf("%d", &t);
    char str[20];
    for(i = 0; i < t; i++)
    {
        scanf("%d", &arr[i]);
        stack_push(&myStack, arr[i]);
    }
    scanf("%d", &x);
    int count = 0;
    while(x--)
    {
        scanf("%s", str);
        if(!strcmp(str, "CLEAN"))
        {
            if(!stack_isEmpty(&myStack))
            {
                count = stack_top(&myStack);
                stack_pop(&myStack);
                stack_push(&myStackx, count);
            }
        }
        else if(!strcmp(str, "RINSE"))
        {
            if(!stack_isEmpty(&myStackx))
            {
                count = stack_top(&myStackx);
                stack_pop(&myStackx);
                stack_push(&myStacky, count);
            }
        }
        else{
            scanf("%d", &n);
            while(n--)
            {
                if(!stack_isEmpty(&myStack))
                {
                    count = stack_top(&myStack);
                    stack_pop(&myStack);
                    stack_push(&myStacky, count);
                }
            }
        }
    }
    if(!stack_isEmpty(&myStack))
    {
        printf("KOTOR: ");
        while(!stack_isEmpty(&myStack))
        {
            printf("%d ", stack_top(&myStack));
            stack_pop(&myStack);
        }
        printf("\n");
    }
    else
        printf("KOTOR: 0\n");
    if(!stack_isEmpty(&myStackx))
    {
        printf("SABUN: ");
        while(!stack_isEmpty(&myStackx))
        {
            printf("%d ", stack_top(&myStackx));
            stack_pop(&myStackx);
        }
        printf("\n");
    }
    else{
        printf("SABUN: 0\n");
    }
    if(!stack_isEmpty(&myStacky))
    {
        printf("BERSIH: ");
        while(!stack_isEmpty(&myStacky))
        {
            printf("%d ", stack_top(&myStacky));
            stack_pop(&myStacky);
        }
        printf("\n");
    }
    else{
        printf("BERSIH: 0\n");
    }
}
