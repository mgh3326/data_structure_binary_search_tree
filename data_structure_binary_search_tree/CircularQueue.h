#pragma once
#include "BinaryNode.h"
#include <stdlib.h>
inline void error(char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};
#define MAX_QUEUE_SIZE 100
class CircularQueue {
	int front;//처음
	int rear;//마지막
	BinaryNode* data[MAX_QUEUE_SIZE];//요소의 배열
public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(BinaryNode* n) {//큐에 삽입
		if (isFull()) error(" Error:큐가 포화상태입니다.\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}
	BinaryNode* dequeue() {//첫 항목을 큐에서 빼서 반환
		if (isEmpty())error("Error: 큐가 공백상태입니다.\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
};