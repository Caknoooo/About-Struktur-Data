#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    double key;
    char nama[100];
    double fisika, mtk, karate;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(char *str, double fisika, double mtk, double karate, double rata) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    strcpy(newNode->nama, str);
    newNode->fisika = fisika;
    newNode->karate = karate;
    newNode->mtk = mtk;
    newNode->key = rata;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, char *str, double fisika, double mtk, double karate, double rata) {
    if (root == NULL) 
        return __bst__createNode(str, fisika, mtk, karate, rata);

    if (rata < root->key)
        root->left = __bst__insert(root->left, str, fisika, mtk, karate, rata);
    else if (rata > root->key)
        root->right = __bst__insert(root->right, str, fisika, mtk, karate, rata);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("Nama: %s\n", root->nama);
        printf("Fisika: %.2lf\n", root->fisika);
        printf("Matematika: %.2lf\n", root->mtk);
        printf("Karate: %.2lf\n", root->karate);
        printf("Rerata: %.2lf\n\n", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("Nama: %s\n", root->nama);
        printf("Fisika: %.2lf\n", root->fisika);
        printf("Matematika: %.2lf\n", root->mtk);
        printf("Karate: %.2lf\n", root->karate);
        printf("Rerata: %.2lf\n\n", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("Nama: %s\n", root->nama);
        printf("Fisika: %.2lf\n", root->fisika);
        printf("Matematika: %.2lf\n", root->mtk);
        printf("Karate: %.2lf\n", root->karate);
        printf("Rerata: %.2lf\n\n", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, double value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, char *str, double fisika, double mtk, double karate, double rata) {
    if (!bst_find(bst, rata)) {
        bst->_root = __bst__insert(bst->_root, str, fisika, mtk, karate, rata);
        bst->_size++;
    }
}

int main()
{
    BST set;
    bst_init(&set);
    int t;
    double fisika, mtk, karate;
    char str[100];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s %lf %lf %lf", str, &fisika, &mtk, &karate);
        double rerata = (fisika + mtk + karate) / 3; 
        bst_insert(&set, str, fisika, mtk, karate, rerata);
    }
    puts("================");
    puts("PRE ORDER");
    __bst__preorder(set._root);
    puts("================");
    puts("IN ORDER");
    __bst__inorder(set._root);
    puts("================");
    puts("POST ORDER");
    __bst__postorder(set._root);
}
