#include <stdio.h>
#include <stdlib.h>

struct Queue {
	int* array;
	int capacity;
	int front;
	int rear;
};

struct Queue* createQueue(int capacity) {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = 0;
	queue->rear = -1;
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

int isFull(struct Queue* queue) {
	return (queue->rear == queue->capacity - 1);
}

int isEmpty(struct Queue* queue) {
	return (queue->front > queue->rear);
}

void enqueue(struct Queue* queue, int item) {
	if (isFull(queue)) {
		printf("Queue is full, cannot enqueue element.\n");
	}
	else {
		queue->rear++;
		queue->array[queue->rear] = item;
		printf("%d enqueued to the queue.\n", item);
	}
}

int dequeue(struct Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty, cannot dequeue element.\n");
		return -1;
	}
	else {
		int item = queue->array[queue->front];
		queue->front++;
		return item;
	}
}

void display(struct Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty.\n");
	}
	else {
		printf("Queue elements: ");
		for (int i = queue->front; i <= queue->rear; i++) {
			printf("%d ", queue->array[i]);
		}
		printf("\n");
	}
}

int main() {
	int capacity, choice, element;
	printf("Enter the capacity of the queue: ");
	scanf_s("%d", &capacity);

	struct Queue* queue = createQueue(capacity);

	while (1) {
		printf("\n1. Enqueue element\n");
		printf("2. Dequeue element\n");
		printf("3. Display elements\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter element to enqueue: ");
			scanf_s("%d", &element);
			enqueue(queue, element);
			break;
		case 2:
			printf("Dequeued element: %d\n", dequeue(queue));
			break;
		case 3:
			display(queue);
			break;
		case 4:
			free(queue->array);
			free(queue);
			exit(0);
		default:
			printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}
