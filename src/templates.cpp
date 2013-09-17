#include<vector>
#include<iostream>
#include<algorithm>

template <typename T>
class Templates
{
private:
    std::vector<T> * mList;
public:
    Templates () {
        mList = new std::vector<T>;

    }
    virtual ~Templates () {
        delete mList;
    }
    void Add(const T & element) {
        mList->push_back(element);
    }
    void Nothing() const {
        for_each(mList->begin(), mList->end(), [] (const int& i) { 
                std::cout << i << std::endl; 
                });
    }

};

int main()
{
    Templates<int> t;
    t.Add(5);
    t.Add(6);
    t.Nothing();
    return 0;
}
