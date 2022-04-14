#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX 100000

/* Struktur Node */

typedef struct snode_t {
    char data[30];
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, char *value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->data, value);
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        
        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size) {
            slist_popBack(list);
            return;    
        }
        else if (index == 0 || index < 0) {
            slist_popFront(list);
            return;
        }
        
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

char *slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

char *slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

int slist_getAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) 
        {
            temp = temp->next;
            _i++;
        }
        if(_i != index)
        {
            printf("Hadeh\n");
            return 0;
        }
        else{
            printf("%s\n", temp->data);
            return 1;
        }
    }
    printf("Hadeh\n");
    return 0;
}

int main()
{
    SinglyList myList[MAX];
    int i;
    for(i = 0; i < MAX; i++)
        slist_init(&myList[i]);
    char str[25];
    int t, cek, x, y, j = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &cek);
        if(cek == 1)
        {
            scanf("%d", &x);
            while(x--)
            {
                scanf("%s", str);
                slist_pushBack(&myList[j], str);
            }
            j++;
        }
        else{
            scanf("%d %d", &x, &y);
            if(x > j || x > MAX || x <= 0)
            {
                printf("Hadeh\n");
                continue;
            }
            if(!slist_getAt(&myList[x - 1], y - 1))
                continue;
            slist_removeAt(&myList[x - 1], y - 1);
        }
    }
}
