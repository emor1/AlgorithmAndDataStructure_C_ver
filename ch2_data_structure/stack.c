#include <stdio.h>
#include <stdlib.h>

// stackのマックス数
#define smax 5


// Stackの実装

struct  stack
{
    char box[smax+1];
    int top;
};

void initialize(struct stack *s)
{
    s->top = 0;
};

void push(struct stack *s, char item)
{
    s->box[++s->top] = item;
};

void pop(struct stack *s){
    --s->top;
}

int empty(struct stack *s){
    return(s->top == 0);
}

char top(struct stack *s){
    return(s->box[s->top]);
}


int main(int argc, char const *argv[])
{
    printf("Start stack\n");
    struct stack *s;
    initialize(s);

    push(s, 't');
    push(s, 's');
    push(s, 'e');
    push(s, 't');

    printf("%c \n",top(s));
    pop(s);
    printf("%c \n",top(s));
    pop(s);
    printf("%c \n",top(s));
    pop(s);
    printf("%c \n",top(s));
    return 0;
}
