#include <stdio.h>
#include <stdlib.h>

/*
 *
 * Traversal In Order: Left Subtree -> Root -> Right Subtree
 * Includes Searching for a specific element
 *
 * */

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

struct Node* createNode(int data) {
    struct Node *n;
    n = (struct Node *) malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root->right);
    }
}

int searchInTree(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == key) {
        return 1;
    }

    return searchInTree(root->left, key) || searchInTree(root->right, key);
}

int main() {

    struct Node *p = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("In-order traversal: ");
    inOrder(p);

    int key;
    printf("\nEnter a value to search: ");
    scanf("%d", &key);

    if (searchInTree(p, key)) {
        printf("Element %d found in the Graph.\n", key);
    } else {
        printf("Element %d not found in the Graph.\n", key);
    }

    return 0;
}