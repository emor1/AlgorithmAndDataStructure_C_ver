#include <stdio.h>
#include <stdlib.h>

#define qMax 5

struct queue
{
    char box[qMax+1];
    int front, rear;
};

void initialize(struct queue *q){
    q->front = 1;
    q->rear = 0;
}

void insert(struct queue *q, char item){
    q->box[++q->rear] = item;
}

// 先頭要素を削除
void delete(struct queue *q){
    ++q->front;
}

int empty(struct queue *q){
    return(q->rear < q->front);
}

char top(struct queue *q){
    return(q->box[q->front]);
}

int main(int argc, char const *argv[])
{
    printf("Queue\n");

    struct queue q;
    initialize(&q);

    insert(&q, '1');
    insert(&q, '2');
    insert(&q, '3');

    printf("%c \n", top(&q));
    insert(&q, '4');
    delete(&q);
    printf("%c \n", top(&q));
    delete(&q);
    printf("%c \n", top(&q));
    delete(&q);
    printf("%c \n", top(&q));

    return 0;
}

