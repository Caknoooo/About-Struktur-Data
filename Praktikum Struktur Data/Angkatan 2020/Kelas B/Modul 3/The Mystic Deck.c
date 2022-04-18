// ========[AVL Tree]======== //
/*
    Dibuat dan ditulis oleh ABDUR ROCHMAN
    28-03-2020
    Struktur Data 2020
    For C
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX 1000

typedef struct AVLNode_t
{
    char data[MAX];
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

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
        strcpy(newNode->data, value);
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
        return (queue->_front->data);
    }
    return "NULL";
}


AVLNode* _avl_createNode(char value[]) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    strcpy(newNode->data, value);
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, char value[]) {
    while (root != NULL) {
        if (strcmp(value, root->data) < 0)
            root = root->left;
        else if (strcmp(value, root->data) > 0)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,char value[]) {
    
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if(strcmp(value, node->data) < 0)
        node->left = _insert_AVL(avl,node->left,value);
    else if(strcmp(value, node->data) > 0)
        node->right = _insert_AVL(avl,node->right,value);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && strcmp(value, node->left->data) < 0) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && strcmp(value, node->left->data) > 0) // 
        return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && strcmp(value, node->right->data) > 0)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && strcmp(value, node->right->data) < 0)
        return _rightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode* _remove_AVL(AVLNode* node,char value[]){
    if(node==NULL)
        return node;
    if(strcmp(value, node->data) > 0)
        node->right=_remove_AVL(node->right,value);
    else if(strcmp(value, node->data) < 0)
        node->left=_remove_AVL(node->left,value);
    else{
        AVLNode *temp;
        if((node->left==NULL)||(node->right==NULL)){
            temp=NULL;
            if(node->left==NULL) temp=node->right;  
            else if(node->right==NULL) temp=node->left;
            
            if(temp==NULL){
                temp=node;
                node=NULL;
            }
            else
                *node=*temp;   
            free(temp);
        }
        else{
            temp = _findMinNode(node->right);
            strcpy(node->data, temp->data);
            node->right=_remove_AVL(node->right,temp->data);
        }    
    }

    if(node==NULL) return node;
    
    node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

    int balanceFactor= _getBalanceFactor(node);
    
    if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
        return _leftCaseRotate(node);

    if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
        return _leftRightCaseRotate(node);
  
    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0) 
        return _rightCaseRotate(node);

    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0) 
        return _rightLeftCaseRotate(node);
    
    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, char value[]) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (!strcmp(temp->data, value))
    {
        return true;
    }
    else
        return false;
}

void avl_insert(Queue *queue, AVL *avl,char value[]){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }
    else{
        queue_push(queue, value);
    }
}

void avl_remove(AVL *avl,char value[]){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}

int count = 0;

void cari(Queue *queue, char cari[])
{
    QueueNode *temp = queue->_front;
    if(!queue_isEmpty(queue))
    {
        for(int i = 0; i < queue->_size; i++)
        {
            if(!strcmp(cari, temp->data))
            {
                printf("%s\n", temp->data);
                count++;
            }
            temp = temp->next;
        }
    }
}

void preorder(Queue *queue, AVLNode *root, int cek) {
    if (root) {
        preorder(queue, root->right, cek);
        if(root->data && count < cek)
        {
            printf("%s\n", root->data);
            count++;
            cari(queue, root->data);
        }
        preorder(queue, root->left, cek);
    }
}

int main(){
    AVL avlku;
    Queue myQueue;
    queue_init(&myQueue);
    avl_init(&avlku);
    int t, cmd, cari;
    char in[MAX];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &cmd);
        if(cmd == 1)
        {
            scanf("%s", in);
            avl_insert(&myQueue, &avlku, in);
        }
        else if(cmd == 2)
        {
            scanf("%s", in);
            avl_remove(&avlku, in);
        }
        else{
            scanf("%d", &cari);
            preorder(&myQueue, avlku._root, cari);
            puts("---");
            count = 0;
        }
    }
}
