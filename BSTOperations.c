#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct node 
{
  int data;
  struct node *left;
  struct node *right;
};

// Function prototypes
struct node *createNode(int data);
struct node *insert(struct node *root, int data);
void inorderTraversal(struct node *root);
void preorderTraversal(struct node *root);
void postorderTraversal(struct node *root);
struct node *deleteNode(struct node *root, int data);
struct node *findMinNode(struct node *node);

int main() 
{
  // Root of the binary search tree
  struct node *root = NULL;

  int choice, data;

  while (1) 
  {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert a new node\n");
    printf("2. Inorder traversal\n");
    printf("3. Preorder traversal\n");
    printf("4. Postorder traversal\n");
    printf("5. Delete a node\n");
    printf("6. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) 
    {
      case 1:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = insert(root, data);
        break;
      case 2:
        printf("Inorder traversal: ");
        inorderTraversal(root);
        printf("\n");
        break;
      case 3:
        printf("Preorder traversal: ");
        preorderTraversal(root);
        printf("\n");
        break;
      case 4:
        printf("Postorder traversal: ");
        postorderTraversal(root);
        printf("\n");
        break;
      case 5:
        printf("Enter data to delete: ");
        scanf("%d", &data);
        root = deleteNode(root, data);
        break;
      case 6:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}

// Creates a new node with the given data and returns a pointer to it
struct node *createNode(int data) 
{
  struct node *newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Inserts a new node with the given data into the binary search tree
struct node *insert(struct node *root, int data) 
{
    // If the tree is empty, create a new node and return it
    if (root == NULL) 
        return createNode(data);
    // If the data is less than the root data, insert the node into the left subtree
    if (data < root->data) 
        root->left = insert(root->left, data);
    // If the data is greater than or equal to the root data, insert the node into the right subtree
    else 
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Perform an inorder traversal of the binary search tree, printing the data of each node
void inorderTraversal(struct node *root) 
{
    if (root != NULL) 
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
// Perform a preorder traversal of the binary search tree, printing the data of each node
void preorderTraversal(struct node *root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
// Perform a postorder traversal of the binary search tree, printing the data of each node
void postorderTraversal(struct node *root) 
{
    if (root != NULL) 
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
// Delete a node with the given data from the binary search tree
struct node *deleteNode(struct node *root, int data) 
{
    // If the tree is empty, return NULL
    if (root == NULL) 
        return root;
    // If the data is less than the root data, delete the node from the left subtree
    if (data < root->data) 
    {
        root->left = deleteNode(root->left, data);
    }
    // If the data is greater than the root data, delete the node from the right subtree
    else if (data > root->data) 
    {
        root->right = deleteNode(root->right, data);
    }
    // If the data is equal to the root data, we have found the node to delete
    else 
    {
        // Case 1: The node has no children
        if (root->left == NULL && root->right == NULL) 
        {
            free(root);
            root = NULL;
        }
        // Case 2: The node has one child
        else if (root->left == NULL) 
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) 
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: The node has two children
        else 
        {
            // Find the minimum node in the right subtree
            struct node *minNode = findMinNode(root->right);
            // Replace the root data with the minimum node data
            root->data = minNode->data;
            // Delete the minimum node from the right subtree
            root->right = deleteNode(root->right, minNode->data);
        }
    }
    return root;
}
// Find the minimum node in a binary search tree
struct node *findMinNode(struct node *node) 
{
    // Keep going left until we reach a leaf node
    while (node->left != NULL) 
        node = node->left;
    return node;
}


