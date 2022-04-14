#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct dnode_t {
    int data;
    struct dnode_t *next, *prev;
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */

typedef struct deque_t {
    DListNode *_head, *_tail;
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

void printList(Deque *deque)
{
    int i;
    DListNode *temp = deque->_head;
    if(!deq_isEmpty(deque))
    {
        for(i = 0; i < deque->_size; i++)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else{
        printf("Mamat gabut\n");
    }
}

void printListRev(Deque *deque)
{
    int i;
    DListNode *temp = deque->_tail;
    if(!deq_isEmpty(deque))
    {
        for(i = 0; i < deque->_size; i++)
        {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }
    else{
        printf("Mamat gabut\n");
    }
}

int main()
{
    Deque myDeq;
    deq_init(&myDeq);
    char str[20];
    int n, x;
    scanf("%d", &n);
    bool flag = false;
    while(n--)
    {
        scanf("%s", str);
        if(!flag)
        {
            if(!strcmp(str, "Push_Back"))
            {
                scanf("%d", &x);
                deq_pushBack(&myDeq, x);
            }
            else if(!strcmp(str, "toFront"))
            {
                scanf("%d", &x);
                deq_pushFront(&myDeq, x);
            }
            else if(!strcmp(str, "Front"))
            {
                if(!deq_isEmpty(&myDeq))
                {
                    printf("%d\n", deq_front(&myDeq));
                    deq_popFront(&myDeq);
                }
                else{
                    printf("Mamat gabut\n");
                }
            }
            else if(!strcmp(str, "Back"))
            {
                if(!deq_isEmpty(&myDeq))
                {
                    printf("%d\n", deq_back(&myDeq));
                    deq_popBack(&myDeq);
                }
                else{
                    printf("Mamat gabut\n");
                }
            }
            else if(!strcmp(str, "List"))
            {
                printList(&myDeq);
            }
            else if(!strcmp(str, "Reverse")){
                flag = true;
            }
        }
        else{
            if(!strcmp(str, "Push_Back"))
            {
                scanf("%d", &x);
                deq_pushFront(&myDeq, x);
            }
            else if(!strcmp(str, "toFront"))
            {
                scanf("%d", &x);
                deq_pushBack(&myDeq, x);
            }
            else if(!strcmp(str, "Front"))
            {
                if(!deq_isEmpty(&myDeq))
                {
                    printf("%d\n", deq_back(&myDeq));
                    deq_popBack(&myDeq);
                }
                else{
                    printf("Mamat gabut\n");
                }
            }
            else if(!strcmp(str, "Back"))
            {
                if(!deq_isEmpty(&myDeq))
                {
                    printf("%d\n", deq_front(&myDeq));
                    deq_popFront(&myDeq);
                }
                else{
                    printf("Mamat gabut\n");
                }
            }
            else if(!strcmp(str, "List"))
            {
                printListRev(&myDeq);
            }
            else if(!strcmp(str, "Reverse")){
                flag = false;
            }
        }
    }
    return 0;
}
