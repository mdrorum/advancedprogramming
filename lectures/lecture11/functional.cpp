#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <class c, int n>
struct add {
    c operator()(c & a) {
        a += n;
    }
};

int main() {
    std::vector<int> v = {1, 2, 3, 4};
    add<int, 10> a;
    std::for_each(v.begin(), v.end(), a);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));
    return 0;
}

