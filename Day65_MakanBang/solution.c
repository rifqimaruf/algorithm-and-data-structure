#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

void addEdge(Node* adj[], int u, int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

typedef struct {
    int items[MAX_N];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int value) {
    q->items[q->rear++] = value;
}

int dequeue(Queue* q) {
    return q->items[q->front++];
}

int main() {
    int N, M, S, T;
    scanf("%d %d %d %d", &N, &M, &S, &T);

    Node* adj[MAX_N] = {NULL};
    for (int i = 0; i < M; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u); 
    }

    int visited[MAX_N] = {0};
    int distance[MAX_N];
    for (int i = 0; i < N; ++i) distance[i] = -1;

    Queue q;
    initQueue(&q);
    enqueue(&q, S);
    visited[S] = 1;
    distance[S] = 0;

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        Node* temp = adj[current];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                distance[neighbor] = distance[current] + 1;
                enqueue(&q, neighbor);
            }
            temp = temp->next;
        }
    }

    printf("%d\n", distance[T]);

    for (int i = 0; i < N; ++i) {
        Node* curr = adj[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    return 0;
}
