#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/* Struktur Node */

typedef struct dnode_t {
    int data;
    struct dnode_t *next,
                   *prev;
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */

typedef struct deque_t {
    DListNode *_head, 
              *_tail;
    unsigned _size;
} Deque;

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
        //newNode->next = deque->_head; // 
    }
}

int deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

int deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

//void eksekusiBiner(Deque *deque)
//{
//    Deque myCode;
//    deq_init(&myCode);
//    DListNode *cur, *prevy, *prevx, *first;
//    int n = deque->_size, b = 1, a = 0, i;
//    for(i = a; i < n; i++)
//    { // 1 0 0 1 0
//        cur = deque->_head; // 1
//        for(i = 0; i < b; i++)
//        {
//            prevx = cur;
//            prevy = cur->next; // 0
//            if(cur->data != prevy->data)
//            {
//                deq_pushBack(&myCode, cur->data); // 1
//                prevy->next = prevx->next; // 
//                free(cur);
//                deque->_head = deque->_head->next;
//                break;
//            }
//            else{
//                prevx->next = prevy;
//                free(cur);
//                free(prevy);
//                deque->_head = deque->_head->next->next;
//            }
//        }
//        if(deq_isEmpty(deque))
//            break;
//    }
//    
//    while(!deq_isEmpty(&myCode))
//    {
//        printf("%c ", deq_back(&myCode));
//        deq_popBack(&myCode);
//    }
//}

int main()
{
    Deque myDeq;
    int t, x, a;
    scanf("%d", &t);
    while(t--)
    {
        deq_init(&myDeq);
        int sum = 0, count = 0;
        scanf("%d", &x);
        while(x)
        {
            a = x % 2;
            if(a == 1)
            {
                if(!deq_isEmpty(&myDeq) && deq_front(&myDeq) == a)
                    deq_popFront(&myDeq);
                else{
                    deq_pushFront(&myDeq, a);
                }
            }
            else{
                if(!deq_isEmpty(&myDeq) && deq_front(&myDeq) == a)
                    deq_popFront(&myDeq);
                else{
                    deq_pushFront(&myDeq, a);
                }
            }
            x = x / 2;
        }
        //eksekusiBiner(&myDeq);
        if(!deq_isEmpty(&myDeq))
        {
            while(!deq_isEmpty(&myDeq))
            {
                if(deq_back(&myDeq) == 1)
                    sum += deq_back(&myDeq) * pow(2, count);
                count++;
                deq_popBack(&myDeq);
            }
            printf("%d\n", sum);
        }
        else{
            printf("0\n");
        }
    }
}
