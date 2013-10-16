#include<iostream>

int x;

int & getX() {
    return x;

}

int main()
{
    std::cout << "original x = " << x << std::endl;
    getX() = 5;
    std::cout << "original x = " << x << std::endl;
    return 0;
}

