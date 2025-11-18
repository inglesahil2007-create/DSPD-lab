#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
};


struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}


void search(struct node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }

    if (root->data == key) {
        printf("Found\n");
        return;
    } else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

int isLeaf(struct node* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}


struct node* deleteLeaf(struct node* root, int key) {
    if (root == NULL)
        return NULL;

 
    if (root->data == key) {
        if (isLeaf(root)) {
            free(root);
            printf("Leaf node %d deleted successfully.\n", key);
            return NULL;
        } else {
            printf("Cannot delete %d — not a leaf node.\n", key);
            return root;
        }
    }


    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else
        root->right = deleteLeaf(root->right, key);

    return root;
}


void inorder(struct node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {
    struct node* root = NULL;
    int choice, key, value;

    while (1) {
        printf("\n Binary Search Tree Menu\n");
        printf("1. Search an element\n");
        printf("2. Insert an element\n");
        printf("3. Delete a leaf element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(root, key);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Element %d inserted.\n", value);
                printf("Current Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter leaf node to delete: ");
                scanf("%d", &key);
                root = deleteLeaf(root, key);
                printf("Current Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}