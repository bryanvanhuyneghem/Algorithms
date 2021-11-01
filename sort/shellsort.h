#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <vector>

template <typename T>
class ShellSort
{
public:
    void operator()(std::vector<T> &v);
    std::vector<long long> sedgewick(int size) const;
};

template <typename T>
std::vector<long long> ShellSort<T>::sedgewick(int size) const
{
    std::vector<long long> sedgewick;

    int k = 0;
    int s;

    while (1)
    {
        if (k % 2 == 0)
        {
            s = 9 * (pow(2, k) - pow(2, k / 2)) + 1;
        }
        else
        {
            s = 8 * pow(2, k) - 6 * pow(2, (k + 1) / 2) + 1;
        }
        k++;

        if (s < size)
        {
            sedgewick.push_back(s);
        }
        else
        {
            break;
        }
    }

    return sedgewick;
}

template <typename T>
void ShellSort<T>::operator()(std::vector<T> &v)
{
    // The Sedgewick's sequence (O(N^4/3) in case of large N)
    std::vector<long long> gaps = sedgewick(v.size());

    for (auto it = gaps.rbegin(); it != gaps.rend(); ++it)
    {
        long long k = *it;

        for (int i = k; i < v.size(); i += 1)
        {
            int j = i - k;

            while (j > -1 && v[j] > v[j + k])
            {
                std::swap(v[j], v[j + k]);
                j -= k;
            }
        }
    }
}

#endif