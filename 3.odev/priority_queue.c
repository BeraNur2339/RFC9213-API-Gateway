#include "priority_queue.h"

PriorityQueue* create_queue(int capacity) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->data = (Request*)malloc(sizeof(Request) * capacity);
    return pq;
}

void swap(Request *a, Request *b) {
    Request temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(PriorityQueue *pq, int index) {
    while (index > 0 && pq->data[(index - 1) / 2].urgency > pq->data[index].urgency) {
        swap(&pq->data[(index - 1) / 2], &pq->data[index]);
        index = (index - 1) / 2;
    }
}

void heapify_down(PriorityQueue *pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->data[left].urgency < pq->data[smallest].urgency)
        smallest = left;
    if (right < pq->size && pq->data[right].urgency < pq->data[smallest].urgency)
        smallest = right;

    if (smallest != index) {
        swap(&pq->data[index], &pq->data[smallest]);
        heapify_down(pq, smallest);
    }
}

void push(PriorityQueue *pq, Request req) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->data = (Request*)realloc(pq->data, sizeof(Request) * pq->capacity);
    }
    pq->data[pq->size] = req;
    heapify_up(pq, pq->size);
    pq->size++;
}

Request pop(PriorityQueue *pq) {
    if (pq->size <= 0) return (Request){-1, -1, ""};
    Request root = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapify_down(pq, 0);
    return root;
}

void free_queue(PriorityQueue *pq) {
    free(pq->data);
    free(pq);
}