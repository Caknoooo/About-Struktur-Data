#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int keke;
typedef struct stackNode_t
{
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t
{
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

bool stack_isEmpty(Stack *stack)
{
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode)
    {
        stack->_size++;
        newNode->data = value;

        if (stack_isEmpty(stack))
            newNode->next = NULL;
        else
            newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack)
{
    if (!stack_isEmpty(stack))
    {
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

unsigned stack_size(Stack *stack)
{
    return stack->_size;
}

typedef struct AVLNode
{
    int data;
    struct AVLNode *left, *right, *parent;
    int height;
    int status; // distance or visited
} AVLNode;

AVLNode *avl_createNode(AVLNode *parent, int value)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    newNode->parent = parent;
    newNode->status = 1;
    return newNode;
}

int _getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int _max(int a, int b)
{
    return (a > b) ? a : b;
}

int _getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

// Rotationsss

AVLNode *_rightRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->left;
    newParrent->parent = pivotNode->parent;
    pivotNode->left = newParrent->right;
    if (newParrent->right)
        newParrent->right->parent = pivotNode;
    newParrent->right = pivotNode;
    pivotNode->parent = newParrent;

    pivotNode->height = _max(_getHeight(pivotNode->left),
                             _getHeight(pivotNode->right)) +
                        1;
    newParrent->height = _max(_getHeight(newParrent->left),
                              _getHeight(newParrent->right)) +
                         1;

    return newParrent;
}

AVLNode *_leftRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->right;
    newParrent->parent = pivotNode->parent;
    pivotNode->right = newParrent->left;
    if (newParrent->left)
        newParrent->left->parent = pivotNode;
    newParrent->left = pivotNode;
    pivotNode->parent = newParrent;

    pivotNode->height = _max(_getHeight(pivotNode->left),
                             _getHeight(pivotNode->right)) +
                        1;
    newParrent->height = _max(_getHeight(newParrent->left),
                              _getHeight(newParrent->right)) +
                         1;

    return newParrent;
}

AVLNode *_leftCaseRotate(AVLNode *node)
{
    return _rightRotate(node);
}

AVLNode *_rightCaseRotate(AVLNode *node)
{
    return _leftRotate(node);
}

AVLNode *_leftRightCaseRotate(AVLNode *node)
{
    AVLNode *temp = _leftRotate(node->left);
    node->left = temp;
    temp->parent = node;
    return _rightRotate(node);
}

AVLNode *_rightLeftCaseRotate(AVLNode *node)
{
    AVLNode *temp = _rightRotate(node->right);
    node->right = temp;
    temp->parent = node;
    return _leftRotate(node);
}
//--

AVLNode *_insert_AVL(AVLNode *root, AVLNode *parent, int value)
{
    if (root == NULL) // udah mencapai leaf
        return avl_createNode(parent, value);
    if (value < root->data)
        root->left = _insert_AVL(root->left, root, value);
    else if (value > root->data)
        root->right = _insert_AVL(root->right, root, value);
    root->height = 1 + _max(_getHeight(root->left), _getHeight(root->right));
    int balanceFactor = _getBalanceFactor(root);

    if (balanceFactor > 1 && value < root->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(root);
    if (balanceFactor > 1 && value > root->left->data) //
        return _leftRightCaseRotate(root);
    if (balanceFactor < -1 && value > root->right->data)
        return _rightCaseRotate(root);
    if (balanceFactor < -1 && value < root->right->data)
        return _rightLeftCaseRotate(root);

    return root;
}

AVLNode *avl_find(AVLNode *root, int value)
{
    if (root)
    {
        if (value < root->data)
            return avl_find(root->left, value);
        if (value > root->data)
            return avl_find(root->right, value);
    }
    return root;
}

int count = 0, max_count, max_distance;

AVLNode *find_predecessor(AVLNode *root, int *distance)
{
    if (root->parent && *distance < max_distance)
    {
        root->status = -1;
        *distance += 1;
        return find_predecessor(root->parent, distance);
    }
    return root;
}

void traverse(AVLNode *root, int distance, Stack *stack)
{
    if (root && distance <= max_distance)
    {
        if (count < max_count && root->left)
            traverse(root->left, distance + root->left->status, stack);
        if (count < max_count)
        {
            // printf("%d ", root->data);
            stack_push(stack, root->data);
            count++;
        }
        if (count < max_count && root->right)
            traverse(root->right, distance + root->right->status, stack);
    }
}

void set_status(AVLNode *root)
{
    if (root)
    {
        root->status = 1;
        if (root->left)
            if (root->left->status == -1)
                set_status(root->left);
            else if (root->right)
                if (root->right->status == -1)
                    set_status(root->right);
    }
}

void solve(AVLNode *root, int value)
{
    count = 0;
    AVLNode *starting = avl_find(root, value);
    if (starting == NULL)
    {
        printf("Eyyy lom dateng :)\n");
        return;
    }
    int distance = 0;
    AVLNode *predecessor = find_predecessor(starting, &distance);
    Stack myStack;
    stack_init(&myStack);
    traverse(predecessor, distance, &myStack);
    while (keke-- && !stack_isEmpty(&myStack))
    {
        int aa = stack_top(&myStack);
        stack_pop(&myStack);
        printf("%d ", aa);
    }
    printf("\n");
    set_status(predecessor);
}

int main()
{

    AVLNode *root = NULL;
    int cmd, data, size = 0;
    while (1)
    {
        scanf("%d", &cmd);
        if (cmd == -1)
            break;
        if (cmd == 0)
        {
            scanf("%d%d%d", &data, &max_distance, &max_count);
            keke = max_count;
            if (keke == -1)
            {
                keke = size;
            }
            max_count = size;
            solve(root, data);
        }
        else
        {
            while (cmd--)
            {
                size++;
                scanf("%d", &data);
                root = _insert_AVL(root, NULL, data);
            }
        }
    }
    printf("End\n");
}
