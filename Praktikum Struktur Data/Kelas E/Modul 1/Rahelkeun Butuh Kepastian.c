#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
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
//void cekQueue(Queue *x, Queue *y, int n)
//{
//    QueueNode *tempx = x->_rear;
//    QueueNode *tempy = y->_rear;
//    bool flag = false;
//    int i;
//    if(!queue_isEmpty(x) && !queue_isEmpty(y))
//    {
//        for(i = 0; i < x->_size; i++)
//        {
//            printf("x : %d \n", tempx->data);
//            printf("y : %d \n", tempy->data);
//            tempx = tempx->next;
//            tempy = tempy->next;
//            if(tempx->data != tempy->data)
//            {
//                flag = true;
//                break;
//            }
//        }
//        if(!flag)
//        {
//            printf("SIP SI PALING JUJUR");
//        }
//        else{
//            printf("DIH TUKANG NYONTEK");
//        }
//    }
//}

int main()
{
    Deque myDeqx, myDeqy;
    deq_init(&myDeqx);
    deq_init(&myDeqy);
    int n, x;
    char str[10];
    scanf("%d", &n);
    int countx = 0, county = 0;
    while(n--)
    {
        scanf("%s", str);
        if(!strcmp(str, "IAN"))
        {
            countx++;
            scanf("%d", &x);
            deq_pushBack(&myDeqx, x);
        }
        else if(!strcmp(str, "AAN"))
        {
            county++;
            scanf("%d", &x);
            deq_pushBack(&myDeqy, x);
        }
        else if(!strcmp(str, "mundur")){
            deq_popBack(&myDeqx);
            deq_popBack(&myDeqy);
        }
    }
    bool flag = false;
    //cekQueue(&myQueuex, &myQueuey, sum / 2);
    while(!deq_isEmpty(&myDeqx) && !deq_isEmpty(&myDeqy))
    {
        if(deq_front(&myDeqx) != deq_front(&myDeqy))
            flag = true;
        deq_popFront(&myDeqx);
        deq_popFront(&myDeqy);
    }
    if(flag)
        printf("SIP SI PALING JUJUR");
    else
        printf("DIH TUKANG NYONTEK");
}
