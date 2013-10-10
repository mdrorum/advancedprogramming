#include <iostream>
#include <random>
#include <vector>

#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;



// adapted from 
// http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Bubble_sort#C.2B.2B
void bubbleSort(vector<int> & list)
{
    auto first = list.begin();
    auto last = list.end();

    for (auto i = first; i != last; i++) {
        for (auto j = first; j < i; j++) {
            if(*i < *j) {
                iter_swap(i, j);
            }
        }
    }
}


// adapted from
// http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Quicksort#C.2B.2B
void quick_sort(typename vector<int>::iterator first, typename vector<int>::iterator last) {

    if( first != last ) {
        auto left  = first;
        auto right = last;
        auto pivot = left++;
 
        while( left != right ) {
            if( *left <= *pivot ) {
                ++left;
            } else {
                while( (left != right) && (*left <= *pivot) ) {
                    --right;
                }
                iter_swap( left, right );
            }
        }
 
        --left;
        iter_swap( pivot, left );
 
        quick_sort( first, left );
        quick_sort( right, last );
    }
}
 
void quick_sort( vector<int> & list ) {
    quick_sort(list.begin(), list.end());
}


 
template <typename T>
void sort(T begin, T end) {
    if (begin != end) {
        T middle = partition (begin, end, bind2nd(
                    less<typename iterator_traits<T>::value_type>(), *begin));
        sort (begin, middle);
//        sort (max(begin + 1, middle), end);
        T new_middle = begin;
        sort (++new_middle, end);
    }
}

//template <typename T>
//void sort(vector<T> & list) {
    //sort(list.begin(), list.end());
//}


int main(int argc, char const *argv[])
{

    cout << "big o notation sample" << endl;

    random_device rd;
    std::mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100);

    vector<int> list;

    for (int n = 0; n < 4; ++n) {
        list.push_back(dis(gen));
    }

    //bubbleSort(list);
    //quick_sort(list);
    //sort(list);
    sort(list.begin(), list.end());
    
    // http://www.cprogramming.com/c++11/c++11-ranged-for-loop.html   
    for(int i : list) {
        cout << i << endl;
    }

    return 0;
}
