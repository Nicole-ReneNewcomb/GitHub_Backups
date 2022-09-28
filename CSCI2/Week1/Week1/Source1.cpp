#include <iostream>

void sumAll(int* ptr1, int* ptr2, int* ptr3);

int main()
{
    int a = 5;
    int b = 10;
    int c = 15;
    sumAll(&a, &b, &c);

        std::cout << "sum: " << a << std::endl;
    return 0;
}

void sumAll(int* ptr1, int* ptr2, int* ptr3)
{
    *ptr1 = *ptr1 + *ptr2 + *ptr3;
}