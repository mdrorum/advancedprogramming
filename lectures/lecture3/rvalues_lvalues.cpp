#include<iostream>
#include<map>

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


    // pointers and references
    int val = 7;
    int *p = &val;
    std::cout << *p << std::endl;

    // [] returns a l-value
    std::map<int, float> mymap;
    mymap[10] = 5.6;

    return 0;
}

