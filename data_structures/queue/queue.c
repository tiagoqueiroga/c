#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *head;
    Node *tail;
    unsigned int size;
} Queue;

Queue *create_queue()
{
    Queue *q = malloc(sizeof(Queue));

    if (q == NULL)
    {
        fprintf(stdout, "Error while malloc queue");
        exit(EXIT_FAILURE);
    }

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

bool is_empty(Queue *queue)
{
    return queue->size == 0;
}

int get_size(Queue *queue)
{
    if (queue->head == NULL)
    {
        return -1;
    }
    else
    {
        return queue->size;
    }
}

Node *get_head_node(Queue *queue)
{
    return queue->head;
}

Node *get_tail_node(Queue *queue)
{
    return queue->tail;
}

int get_head_value(Queue *queue)
{
    return queue->head->value;
}

int get_tail_value(Queue *queue)
{
    return queue->tail->value;
}

void enqueue(Queue *queue, int value)
{
    Node *n = malloc(sizeof(Node));

    if (n == NULL)
    {
        fprintf(stdout, "Error while malloc node");
        exit(EXIT_FAILURE);
    }

    n->next = NULL;
    n->value = value;

    if (is_empty(queue))
    {
        queue->head = n;
        queue->tail = n;
    }
    else
    {
        queue->tail->next = n;
        queue->tail = n;
    }

    queue->size++;
}

int dequeue(Queue *queue)
{
    if (!is_empty(queue))
    {
        int temp_value = queue->head->value;

        Node *old_head = queue->head;

        if (queue->size == 1)
        {
            queue->head = NULL;
            queue->tail = NULL;
        }

        else
        {
            queue->head = queue->head->next;
        }

        free(old_head);

        queue->size--;

        return temp_value;
    }
    else
    {
        return -1;
    }
}

void print_head_tail(Queue *queue)
{
    if (queue->head == NULL)
    {
        printf("\tempty queue\n");
    }
    else
    {
        printf("\thead value:%d\n", get_head_value(queue));
        printf("\ttail value:%d\n", get_tail_value(queue));
    }
}

int main()
{
    Queue *q1 = create_queue();

    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);

    printf("Enqueued\n");

    print_head_tail(q1);

    printf("Dequeued\n");

    dequeue(q1);
    dequeue(q1);

    print_head_tail(q1);

    free(q1);

    return 0;
}
