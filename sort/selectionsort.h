#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>

template <typename T>
class SelectionSort
{
public:
    void operator()(std::vector<T> &v);
};

template <typename T>
void SelectionSort<T>::operator()(std::vector<T> &v)
{
    for (int i = v.size() - 1; i > 0; i--)
    {
        int maxIndex = i;
        for (int j = 0; j < i; j++)
        {
            if (v[maxIndex] < v[j])
            {
                maxIndex = j;
            }
        }
        std::swap(v[i], v[maxIndex]);
    }
}

#endif