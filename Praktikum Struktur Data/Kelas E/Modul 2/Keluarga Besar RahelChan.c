#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX 10000

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    char nama[MAX];
    struct bstnode_t *left, *right;
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

BSTNode* __bst__createNode(char* nama) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    strcpy(newNode->nama, nama);
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, char *value) {
    if (root == NULL) 
        return __bst__createNode(value);
    if (strcmp(root->nama, value) < 0)
        root->left = __bst__insert(root->left, value);
    else if (strcmp(root->nama, value) > 0)
        root->right = __bst__insert(root->right, value);
    return root;
}

BSTNode* __bst__search(BSTNode *root, char *value) {
    while (root != NULL) {
        if (strcmp(root->nama, value) < 0)
            root = root->left;
        else if (strcmp(root->nama, value) > 0)
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
        printf("%s ", root->nama);
        __bst__inorder(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, char *value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->nama == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, char *value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void searchChild(BST *bst, char *value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if(temp != NULL)
    {
        if(temp->left != NULL && temp->right != NULL)
        {
            printf("%s %s", temp->left->nama, temp->right->nama);
        }
        else if(temp->left != NULL && temp->right == NULL){
            printf("%s -", temp->left->nama);
        }
        else if(temp->left == NULL && temp->right != NULL){
            printf("- %s", temp->right->nama);
        }
        else{
            printf("Anak-aNakkuu lagi otw Gan");
        }
    }
}

BSTNode *searchParent(BSTNode *root, char *value)
{
    BSTNode *parent = NULL;
    while(root != NULL)
    {
        if(strcmp(root->nama, value) < 0){
            parent = root;
            root = root->left;
        }
        else if(strcmp(root->nama, value) > 0){
            parent = root;
            root = root->right;
        }
        else
            return parent;
    }
    return parent;
}

int main()
{
    BST set;
    bst_init(&set);
    char nama[MAX], cmd[10], cek[MAX];
    int t, n;
    scanf("%d %d", &t, &n);
    while(t--)
    {
        scanf("%s", nama);
        bst_insert(&set, nama);
    }
    while(n--)
    {
        scanf("%s", cmd);
        if(!strcmp(cmd, "anak"))
        {
            scanf("%s", cek);
            if(__bst__search(set._root, cek))
            {
                searchChild(&set, cek);
                puts("");
            }
        }
        else if(!strcmp(cmd, "ibu")){
            scanf("%s", cek);
            if(!strcmp(set._root->nama, cek))
            {
                puts("Aku adalah Komandan 1 keluarga Rahel");
            }
            else{
                BSTNode *temp = searchParent(set._root, cek);
                printf("%s\n", temp->nama);
            }
        }
    }
}
