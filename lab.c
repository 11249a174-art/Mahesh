#include <stdio.h>
int main() 
{
    int n, op = 0, front = -1, rear = -1, item;
    printf("Enter the size of the queue:\n");
    scanf("%d", &n);
    int arr[n];
    while (1) 
    {
        printf("\nSelect the operation: {1. Enqueue, 2. Dequeue, 3. Display, 4. Exit}\n");
        scanf("%d", &op);
        switch (op) {
            case 1: // Enqueue
                if ((front == 0 && rear == n - 1) || (rear + 1) % n == front) 
                {
                    printf("Queue overflow!\n");
                } else 
                {
                    printf("Enter the element to enqueue:\n");
                    scanf("%d", &item);
                    if (front == -1) 
                    {
                        front = rear = 0;
                    } 
                    else 
                    {
                        rear = (rear + 1) % n;
                    }
                    arr[rear] = item;
                    printf("%d enqueued to queue.\n", item);
                }
                break;

            case 2: // Dequeue
                if (front == -1) 
                {
                    printf("Queue underflow!\n");
                } else 
                {
                    item = arr[front];
                    if (front == rear) 
                    {
                        front = rear = -1;
                    } else 
                    {
                        front = (front + 1) % n;
                    }
                    printf("Dequeued item: %d\n", item);
                }
                break;

            case 3:
                if (front == -1) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue elements: ");
                    int i = front;
                    while (1) {
                        printf("%d ", arr[i]);
                        if (i == rear)
                            break;
                        i = (i + 1) % n;
                    }
                    printf("\n");
                }
                break;

            case 4: 
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid operation! Please enter 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}
