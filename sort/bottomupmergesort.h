#ifndef BOTTOMUPMERGESORT_H
#define BOTTOMUPMERGESORT_H

#include <vector>

template <typename T>
class BottomUpMergeSort
{
public:
    void operator()(std::vector<T> &v);

private:
    void merge(std::vector<T> &, std::vector<T> &, int, int, int);
};

int min(int x, int y) { return (x < y) ? x : y; }

// O(N*lg(N)) time complexity and O(N) space complexity
template <typename T>
void BottomUpMergeSort<T>::operator()(std::vector<T> &v)
{
    std::vector<T> temp(v.size());

    // loop over all subparts starting at size 1
    for (int curr_size = 1; curr_size <= v.size() - 1; curr_size *= 2)
    {
        // loop over all left part start positions
        for (int l = 0; l < v.size() - 1; l += 2 * curr_size)
        {
            // find middle of left subpart
            int m = min(l + curr_size - 1, v.size() - 1);
            int r = min(l + 2 * curr_size - 1, v.size() - 1);

            // merge left and right subpart
            merge(v, temp, l, m, r);
        }
    }
}

template <typename T>
void BottomUpMergeSort<T>::merge(std::vector<T> &v, std::vector<T> &temp, int l, int m, int r)
{
    // copy the first part to a temp vector
    int p = l;
    while (p <= m)
    {
        temp[p - l] = std::move(v[p]);
        p++;
    }

    p = 0;
    int q = m + 1;
    int k = l;

    // merge both parts in the initial vector
    while (p <= m - l && q <= r)
    {
        if (temp[p] <= v[q])
        {
            std::swap(temp[p++], v[k++]);
        }
        else
        {
            std::swap(v[q++], v[k++]);
        }
    }

    // swap the remaining elements of the left subpart
    while (p <= m - l)
    {
        std::swap(temp[p++], v[k++]);
    }

    // swap the remaining elements of the right subpart
    while (q <= r)
    {
        std::swap(v[q++], v[k++]);
    }
}

#endif