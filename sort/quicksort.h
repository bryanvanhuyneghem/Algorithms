#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

template <typename T>
class Quicksort
{
public:
    void operator()(std::vector<T> &v);

private:
    void quicksort(std::vector<T> &, int, int);
};

template <typename T>
void Quicksort<T>::operator()(std::vector<T> &v)
{
    quicksort(v, 0, v.size());
}

template <typename T>
void Quicksort<T>::quicksort(std::vector<T> &v, int l, int r)
{
    if (l < r - 1)
    {
        T pivot = v[l];

        int i = l;
        int j = r - 1;

        while (v[j] > pivot)
        {
            j--;
        }

        while (i < j)
        {
            std::swap(v[i], v[j]);
            i++;
            while (v[i] < pivot)
            {
                i++;
            }
            j--;
            while (v[j] > pivot)
            {
                j--;
            }
        }

        quicksort(v, l, j + 1);
        quicksort(v, j + 1, r);
    }
}

#endif