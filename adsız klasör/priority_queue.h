#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int urgency; 
    char api_path[128];
} Request;

typedef struct {
    Request *data;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* create_queue(int capacity);
void push(PriorityQueue *pq, Request req);
Request pop(PriorityQueue *pq);
void free_queue(PriorityQueue *pq);

#endif