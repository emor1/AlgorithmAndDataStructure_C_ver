#include <stdio.h>
#include <stdlib.h>

/**
 * 概要：nの階乗を求めるプログラム
 * 再帰を使ったものと、使っていないものの２つの関数を実装
*/

int factional_not_recursion(int n){
    int f;
    if(n==0)
        return 1;
    f = 1;
    for(int i=1;i<=n;i++){
        f = f*i;
    }
    return f;
}

int factional_recursion(int n){
    if(n==0)
        return 1;
    else
        return (n*factional_recursion(n-1));
}

int main(int argc, char const *argv[])
{
    int N=atoi(argv[1]);
    printf("%d\n",factional_not_recursion(N));
    printf("%d\n",factional_recursion(N));
    return 0;
}
