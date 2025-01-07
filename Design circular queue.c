#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *queue;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularQueue;

// Function to initialize the circular queue
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    queue->queue = (int*)malloc(sizeof(int) * k);
    queue->capacity = k;
    queue->size = 0;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

// Function to add an element to the circular queue
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    // Check if the queue is full
    if (obj->size == obj->capacity) {
        return false;
    }
    obj->queue[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->size++;
    return true;
}

// Function to remove an element from the circular queue
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    // Check if the queue is empty
    if (obj->size == 0) {
        return false;
    }
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

// Function to get the front element of the circular queue
int myCircularQueueFront(MyCircularQueue* obj) {
    // Check if the queue is empty
    if (obj->size == 0) {
        return -1;
    }
    return obj->queue[obj->front];
}

// Function to get the last element of the circular queue
int myCircularQueueRear(MyCircularQueue* obj) {
    // Check if the queue is empty
    if (obj->size == 0) {
        return -1;
    }
    // We need to check the element before the front, since rear is always one step ahead
    int rearIndex = (obj->rear - 1 + obj->capacity) % obj->capacity;
    return obj->queue[rearIndex];
}

// Function to check if the circular queue is empty
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

// Function to check if the circular queue is full
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

// Function to free the memory of the circular queue
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}
