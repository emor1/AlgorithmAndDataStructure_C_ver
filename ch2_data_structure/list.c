#include <stdio.h>
#include <stdlib.h>

// リスト
struct element
{
    char data;
    // 構造体分のポインタ
    struct element *next;
};

// メモリー上にせるの領域を確保
struct element *new()
{
    return((struct element *)malloc(sizeof(struct element)));
}

// からのリストを生成
struct element *create()
{
    struct element *p;

    p = new();
    p->next = NULL;
    return (p);
}

// リストへ要素の挿入
void insert(struct element *l, int k, char item)
{
    struct element *p;

    if(k>1){
        insert(l->next, k-1, item);
    }
    else{
        p = new();
        p->data = item;
        p->next = l->next;
        l->next = p;
    }
}

// リストから要素の削除
void delete(struct element *l, int k){
    if(k>1){
        delete(l->next, k-1);
    }else{
        l->next = l->next->next;
    }
}

char access(struct element *l, int k)
{
    if(k>1){
        return (access(l->next, k-1));
    }
    else return(l->next->data);
}


int main(int argc, char const *argv[])
{
    printf("test\n");
    struct element *list_example = create();

    // リストの先頭は値を格納しないダミーセルになっている
    insert(list_example, 1, 'a');
    printf("%c \n",access(list_example, 1));

    insert(list_example, 2, 'b');
    insert(list_example, 3, 'c');
    printf("%c \n",access(list_example, 1));
    printf("%c \n",access(list_example, 2));
    printf("%c \n",access(list_example, 3));

    delete(list_example, 2);
    printf("%c \n",access(list_example, 1));
    printf("%c \n",access(list_example, 2));
    return 0;
}
