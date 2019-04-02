#include <stdio.h>

#define MAXSIZE 128

int f(int n);
int f1(int n);

int main(void)
{
    int n = 0;
    printf("please input the number: ");
    scanf("%d", &n);
    printf("the result is : %d\n", f(n));
    printf("the result of recursive version is : %d\n", f1(n));

    return 0;
}

int f1(int n)
{
    if(n == 0)return 1;
    return n*f1(n/2);
}

int f(int n)
{
    if(n == 0)return 1;
    int stack[MAXSIZE];
    int top = -1;
    while(n != 0){
        stack[++top] = n;
        n/=2;
    }

    //stack[++top] = 1;
    int product = 1;
    while(top!=-1){
        product *= stack[top--];
    }

    return product;
}

int f3(int n)
{
    //[][0] = f(n) [][1] = n [][2] = f(n/2)
    int stack[MAXSIZE][3];
}