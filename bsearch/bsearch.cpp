#include <vector>
#include <iostream>
#include <string>
#include <cassert>

// #undef assert

using namespace std;


template<class It, class T>
It last_less(It beg, It end, const T& value)
{
    // size_t size = end - beg;
    size_t low = 0, high = end - beg;
    while(low < high){
        size_t mid = (low + high) / 2;
        if(*(beg+mid)>=value){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    return beg+(low - 1);
}

template<class It, class T>
It first_greater(It beg, It end, const T& value)
{
    size_t low = 0, high = end - beg;
    while(low < high){
        size_t mid = (low + high) / 2;
        if(*(beg+mid)>value){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    return beg + low;
}

int main()
{
    vector<string> strs{"a","b", "c", "c", "c","d","end", "end"};
    assert(*last_less(strs.begin(),strs.end(),"c")=="b");
    assert(*last_less(strs.begin(),strs.end(),"end")=="d");
    // assert(0);
    assert(*first_greater(strs.begin(),strs.end(),"d")=="end");
    assert(*first_greater(strs.begin(),strs.end(),"a")=="b");
    assert(first_greater(strs.begin(),strs.end(),"end")==strs.end());

    cout<<"done!\n";

    return 0;
}