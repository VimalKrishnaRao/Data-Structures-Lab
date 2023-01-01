#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes of the linked list
struct Node 
{
  int data;
  struct Node* next;
};

  // Function to insert a new element as the first node in the linked list
void insertFirst(struct Node** head, int data) 
{
  // Allocate memory for the new node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;

  // Set the next pointer of the new node to point to the current head
  newNode->next = *head;

  // Update the head to point to the new node
  *head = newNode;
}

// Function to insert a new element as an intermediate node in the linked list
void insertIntermediate(struct Node* head, int data, int position) 
{
  // Allocate memory for the new node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;

  // Find the node at the specified position
  struct Node* cur = head;
  for (int i = 1; i < position-1 && cur != NULL; i++) 
    cur = cur->next;

  // If the position is not valid, return
  if (cur == NULL) 
  {
    printf("Invalid position\n");
    free(newNode);
    return;
  }

  // Insert the new node after the node at the specified position
  newNode->next = cur->next;
  cur->next = newNode;
}

// Function to insert a new element as the last node in the linked list
void insertLast(struct Node* head, int data) 
{
  // Allocate memory for the new node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  // Find the last node in the linked list
  struct Node* cur = head;
  while (cur->next != NULL) 
    cur = cur->next;
  // Insert the new node after the last node
  cur->next = newNode;
}

// Function to delete a node with the specified data from the linked list
void deleteNode(struct Node** head, int data) 
{
  // Store the current head
  struct Node* cur = *head;

  // If the head node contains the data to be deleted, update the head to point to the next node
  if (cur != NULL && cur->data == data) 
  {
    *head = cur->next;
    free(cur);
    return;
  }

  // Find the node with the specified data
  struct Node* prev;
  while (cur != NULL && cur->data != data) 
  {
    prev = cur;
    cur = cur->next;
  }

  // If the data is not found, return
  if (cur == NULL) 
  {
    printf("Data not found\n");
    return;
  }

  // Unlink the node with the specified data and free its memory
  prev->next = cur->next;
  free(cur);
}

// Function to search for a node with the specified data in the linked list
void searchNode(struct Node* head, int data) 
{
  // Iterate through the linked list and search for the node with the specified data
  struct Node* cur = head;
  int pos = 1;
  while (cur != NULL && cur->data != data) 
  {
    cur = cur->next;
    pos++;
  }

  // If the data is found, print its position, otherwise print a message indicating that it was not found
  if (cur != NULL) 
  {
    printf("Data found at position %d\n", pos);
  } else {
    printf("Data not found\n");
  }
}

// Function to print the linked list
void printList(struct Node* head) 
{
  printf("Linked list: ");
  struct Node* cur = head;
  while (cur != NULL) 
  {
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
}

int main() 
{
  // Create an empty linked list
  struct Node* head = NULL;

  int choice;
  int data, position;

  // Menu-driven loop to allow the user to perform various operations on the linked list
  do 
  {
    printf("\n-----Menu-----\n");
    printf("1. Insert a new element as the first node\n");
    printf("2. Insert a new element as an intermediate node\n");
    printf("3. Insert a new element as the last node\n");
    printf("4. Delete a node with a user-inputted element\n");
    printf("5. Search for a node with a user-inputted element\n");
    printf("6. Exit\n");
    printf("\nEnter your choice:\n");

    scanf("%d", &choice);

    switch (choice) 
    {
      case 1:
        printf("Enter the data for the new element: ");
        scanf("%d", &data);
        insertFirst(&head, data);
        break;
      case 2:
        printf("Enter the data for the new element: ");
        scanf("%d", &data);
        printf("Enter the position for the new element (1-based index): ");
        scanf("%d", &position);
        insertIntermediate(head, data, position);
        break;
      case 3:
        printf("Enter the data for the new element: ");
        scanf("%d", &data);
        insertLast(head, data);
        break;
      case 4:
        printf("Enter the data of the element to delete: ");
        scanf("%d", &data);
        deleteNode(&head, data);
        break;
      case 5:
        printf("Enter the data of the element to search for: ");
        scanf("%d", &data);
        searchNode(head, data);
        break;
      case 6:
        break;
      default:
        printf("Invalid choice\n");
        break;
    }

    // Print the updated list after each operation
    printList(head);

  } 
  while (choice !=6);
}

