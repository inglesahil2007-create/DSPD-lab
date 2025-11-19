#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(struct node* root, int data) {
    struct node *temp = root;
    int choice;

    while (1) {
        printf("Current Node = %d\n", temp->data);
        printf("Where to insert %d?\n1. Left\n2. Right\nEnter choice: ", data);
        scanf("%d", &choice);

        if (choice == 1) {  
            if (temp->left == NULL) {
                temp->left = createNode(data);
                printf("Inserted %d to LEFT of %d\n", data, temp->data);
                return;
            } else {
                temp = temp->left; 
            }
        }

        else if (choice == 2) { 
            if (temp->right == NULL) {
                temp->right = createNode(data);
                printf("Inserted %d to RIGHT of %d\n", data, temp->data);
                return;
            } else {
                temp = temp->right; 
            }
        }

        else {
            printf("Invalid choice! Try again.\n");
        }
    }
}


void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct node* root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    return search(root->left, key) || search(root->right, key);
}

int main() {
    struct node* root = NULL;
    int n, data, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return 0;
    }

    printf("Enter root element: ");
    scanf("%d", &data);
    root = createNode(data);

    for (int i = 1; i < n; i++) {
        printf("Enter next element: ");
        scanf("%d", &data);
        insert(root, data);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nEnter element to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("Found\n");
    else
        printf("NULL\n");

    return 0;
}