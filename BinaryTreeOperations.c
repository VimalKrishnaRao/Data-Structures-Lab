#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) 
{
  struct node *node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void insert(struct node *root, int data) 
{
  if (data < root->data) 
  {
    if (root->left == NULL) 
    {
        root->left = newNode(data);
    } 
    else 
    {
        insert(root->left, data);
    }
  }
  else 
  {
    if (root->right == NULL) 
    {
        root->right = newNode(data);
    }
    else 
    {
        insert(root->right, data);
    }
  }
}

void inorder(struct node *root) 
{
  if (root == NULL) 
    return;

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void preorder(struct node *root) 
{
  if (root == NULL) 
    return;

  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(struct node *root) 
{
  if (root == NULL) 
    return;

  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

struct node *findMinNode(struct node *root) 
{
  while (root->left != NULL) 
    root = root->left;
  return root;
}

struct node *deleteNode(struct node *root, int data) 
{
  if (root == NULL) 
    return root;

  if (data < root->data) 
  {
    root->left = deleteNode(root->left, data);
  } 
  else if (data > root->data) 
  {
    root->right = deleteNode(root->right, data);
  } 
  else 
  {
    if (root->left == NULL) 
    {
      struct node *temp = root->right;
      free(root);
      return temp;
    } 
    else if (root->right == NULL) 
    {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *temp = findMinNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int main() 
{
  int choice, data;
  struct node *root = NULL;

  while (1) 
  {
    printf("\n\nMenu:\n");
    printf("1. Insert a new node\n");
    printf("2. Inorder traversal\n");
    printf("3. Preorder traversal\n");
    printf("4. Postorder traversal\n");
    printf("5. Delete a node\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) 
    {
      printf("Enter the data to be inserted: ");
      scanf("%d", &data);

      if (root == NULL) 
      {
        root = newNode(data);
      } 
      else 
      {
        insert(root, data);
      }
    } 
    else if (choice == 2) 
    {
      printf("Inorder traversal: ");
      inorder(root);
      printf("\n");
    } 
    else if (choice == 3) 
    {
      printf("Preorder traversal: ");
      preorder(root);
      printf("\n");
    } 
    else if (choice == 4) 
    {
      printf("Postorder traversal: ");
      postorder(root);
      printf("\n");
    } 
    else if (choice == 5) 
    {
      printf("Enter the data to be deleted: ");
      scanf("%d", &data);
      root = deleteNode(root, data);
    } 
    else 
    {
      break;
    }
  }
  return 0;
}
