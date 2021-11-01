#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>

template <typename T>
class BinarySearch
{
public:
    int operator()(std::vector<T> &v, int value) const;
    int binary_search_recursive(std::vector<T> &v, int l, int r, int value) const;
    int binary_search_iterative(std::vector<T> &v, int l, int r, int value) const;
};

template <typename T>
int BinarySearch<T>::operator()(std::vector<T> &v, int value) const
{
    return binary_search_iterative(v, 0, v.size() - 1, value);
}

// Time complexity: O(lg(N)); space complexity: O(1)
template <typename T>
int BinarySearch<T>::binary_search_recursive(std::vector<T> &v, int l, int r, int value) const
{
    if (l <= r)
    {
        // locate middle of vector
        int mid = l + (r - l) / 2;

        if (value == v[mid])
        {
            return mid;
        }
        else if (value < v[mid])
        {
            // continue with left-most section of vector
            return binary_search_recursive(v, l, mid - 1, value);
        }

        // continue with right-most section of vector
        return binary_search_recursive(v, mid + 1, r, value);
    }
    // value could not be found in the vector
    return -1;
}

// Time complexity: O(lg(N)); space complexity: O(1).
// Although the time and space complities are the same as the recursive implemention,
// the iterative version has better practical performance because it does not use
// recursive function calls.
int BinarySearch<T>::binary_search_iterative(std::vector<T> &v, int l, int r, int value) const
{
    while (l <= r)
    {
        // locate middle of vector
        int mid = l + (r - l) / 2;

        if (value == v[mid])
        {
            return mid;
        }
        else if (value < v[mid])
        {
            // continue with left-most section of vector
            r = mid - 1;
        }
        else
        {
            // continue with right-most section of vector
            l = mid - 1;
        }
    }
    // value could not be found in the vector
    return -1;
}

#endif