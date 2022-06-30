#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node {
  int data;
  struct Node* next;
};
void insertAtBeginning(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref;

  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }
  while (last->next != NULL) last = last->next;
  last->next = new_node;
  return;
}
void printList(struct Node* node) {
  while (node != NULL) {
  cout << node->data << " ";
  node = node->next;
  }
}
int main() {
  struct Node* head = NULL;
 cout << "Linked list: ";
    insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  printList(head);
   cout << "\nLinked list after insertion at tail: ";
   insertAtEnd(&head, 5);
  printList(head);

 }

