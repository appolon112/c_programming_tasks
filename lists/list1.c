#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти\n");
        return 0;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node* *head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int N;
    printf("Введите длину списка: ");
    scanf("%d", &N);

    Node* head = NULL;

   
    for (int i = 1; i <= N; i++) {
        appendNode(&head, i);
    }
    
    printf("Содержимое списка: ");
    printList(head);
   
    freeList(head);

    return 0;
}
