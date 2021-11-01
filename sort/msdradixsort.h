#ifndef MSDRADIXSORT_H
#define MSDRADIXSORT_H

#include <vector>

template <typename T>
class MSDRadixSort
{
public:
    void operator()(std::vector<T> &v);
};

template <class T>
void radix_counting_sort(std::vector<T> &v, int exp)
{
    T max = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    std::vector<T> temp(max + 1, 0);
    std::vector<T> freq(max + 1, 0);

    for (int i = 0; i < v.size(); i++)
    {
        freq[v[i] / exp]++;
    }

    for (int i = 1; i <= max; i++)
    {
        freq[i] += freq[i - 1];
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        temp[freq[v[i] / exp] - 1] = v[i];
        freq[v[i] / exp]--;
    }

    for (int i = 0; i < v.size(); i++)
    {
        v[i] = std::move(temp[i]);
    }
}

// O(N lg_m(N)) time complexity with N being the number of elements and m the radix
template <typename T>
void MSDRadixSort<T>::operator()(std::vector<T> &v)
{
    T max = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (max < v[i])
        {
            max = v[i];
        }
    }

    int digits = 1;
    int count = 0;
    while (digits < max)
    {
        digits *= 10;
        count++;
    }

    for (count; count > 0; count--)
    {
        digits /= 10;
        radix_counting_sort(v, digits);
    }
}

#endif