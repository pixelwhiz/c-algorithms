#include <stdio.h>
#include <stdlib.h>

/*
 *
 * Traversal Pre Order: Root -> Left Subtree -> Right Subtree
 * Includes searching for a specific element
 *
 * */

struct Node {
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

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
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

    printf("Pre-order traversal: ");
    preOrder(p);

    int key;
    printf("\nEnter a value to seach: ");
    scanf("%d", &key);

    if (searchInTree(p, key)) {
        printf("Element %d found in the tree.\n", key);
    } else {
        printf("Element %d not found in the tree.\n", key);
    }

    return 0;
}