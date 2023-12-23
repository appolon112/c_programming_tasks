#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createCircularList(int N) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 1; i <= N; i++) {
        Node* newNode = createNode(i);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head; 
    return head;
}

void removeKthNode(Node** head, int K) {
    Node* prev = NULL;
    Node* curr = *head;
    while (curr->next != curr) { 
        int count = 1;
        while (count != K) {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        if (curr == *head) {
            *head = prev->next;
        }
        free(curr);
        curr = prev->next;
    }
}


int main() {
    int N, K;
    printf("Введите N и K: ");
    scanf("%d %d", &N, &K);

    Node* head = createCircularList(N);
    removeKthNode(&head, K);

    printf("Оставшийся номер: %d\n", head->data);

    free(head); 
    return 0;
}
