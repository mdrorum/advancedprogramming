#include<iostream>

int x;

int & getX() {
    return x;

}

// pointers do not work here
int * getXPointer() {
    return &x;
}

int main()
{
    std::cout << "original x = " << x << std::endl;
    getX() = 5;
    std::cout << "original x = " << x << std::endl;

    getXPointer();

    //getXPointer() = 7; // &x is not a l-value
    
    //&x = 7;
    return 0;
}

