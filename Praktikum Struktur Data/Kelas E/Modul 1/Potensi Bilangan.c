#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Struktur Node */

typedef struct pqueueNode_t {
    char data;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, char value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value < pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

char pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}
int main()
{
    PriorityQueue myQueue;
    int t, x, a;
    scanf("%d", &t);
    while(t--)
    {
        pqueue_init(&myQueue);
        scanf("%d", &x);
        int sum = 0, count= 0;
        while(x)
        { // 8
            a = x % 2;
            if(a == 1)
                pqueue_push(&myQueue, '1');
            else
                pqueue_push(&myQueue, '0');
            x = x / 2;
        }
        while (!pqueue_isEmpty(&myQueue)) 
        {
            if(pqueue_top(&myQueue) == '1')
                sum += pow(2, count);
            count++;
            pqueue_pop(&myQueue);
        }
        printf("%d\n", sum);
    }
    return 0;
}
