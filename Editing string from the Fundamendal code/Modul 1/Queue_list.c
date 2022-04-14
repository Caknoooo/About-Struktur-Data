/**
 * This code is creating by Bayu Laksana
 	I just changed to string 
 	
 * Implementasi ADT Queue (Queue menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX 1000

/* Struktur Node */

typedef struct queueNode_t {
    char data[MAX];
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, char value[]);
void queue_pop(Queue *queue);
char *queue_front(Queue *queue);
int  queue_size(Queue *queue);

/* Function definition below */

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, char value[])
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        strcpy(newNode->data, value); // copy value to newNode->data
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

char *queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data); // return of string
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

int main(int argc, char const *argv[])
{
    // Buat objek QueueArray
    Queue myQueue;

    // PENTING! Jangan lupa diinisialisasi
    queue_init(&myQueue);

    // Operasi pada queue
    queue_push(&myQueue, "I");
    queue_push(&myQueue, "Like");
    queue_push(&myQueue, "You <3");

    // cetak isi queue
    while (!queue_isEmpty(&myQueue)) {
        printf("%s ", queue_front(&myQueue));
        queue_pop(&myQueue);
    }
    puts("");
    return 0;
}
