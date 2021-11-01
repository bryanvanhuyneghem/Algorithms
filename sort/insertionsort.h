#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>

template <typename T>
class InsertionSort
{
public:
    void operator()(std::vector<T> &v);
};

template <typename T>
void InsertionSort<T>::operator()(std::vector<T> &v) 
{
    for (int i = 1; i < v.size(); i++)
    {
        int j = i - 1;
        while (j > -1 && v[j] > v[j + 1])
        {
            std::swap(v[j], v[j + 1]);
            j--;
        }
    }
}

#endif