#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <vector>

template <typename T>
class BucketSort
{
public:
    void operator()(std::vector<T> &v);
};

// O(N) time complexity but O(N^2) in worst case
template <typename T>
void BucketSort<T>::operator()(std::vector<T> &v)
{
    vector<vector<float>> b(v.size());

    for (int i = 0; i < v.size(); i++)
    {
        int bi = v.size() * v[i];
        b[bi].push_back(v[i]);
    }

    for (int i = 0; i < v.size(); i++)
        std::sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < b[i].size(); j++)
            v[index++] = b[i][j];
}

#endif