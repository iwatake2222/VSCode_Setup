#include <stdio.h>
#include "ClassA.h"
#include "SubClassB.h"

int funcA(int x);

int main()
{
    printf("Hello World\n");
    int a = 10;
    int b = 20;
    int c = a + b;
    printf("c = %d\n", c);

    printf("%d\n", funcA(5));

    ClassA classA;
    classA.setValue(8);
    printf("%d\n", classA.getValue());

    SubClassB *p_subClassB = new SubClassB();
    p_subClassB->setValue(9);
    printf("%d\n", p_subClassB->getValue());

    printf("exit\n");
}


int funcA(int x)
{
    return x*2;
}