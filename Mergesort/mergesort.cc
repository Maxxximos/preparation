/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mergesort.cc
 * Author: mzhirkov
 *
 * Created on March 4, 2017, 9:03 AM
 */

#include <iostream>
#include <vector>

using namespace std;

void merge(std::vector<int>& vec, int left, int pivot, int right)
{
    std::vector<int> a(right-left+1);
    int i = left;
    int j = pivot+1;
    int pos = 0;
    while (i <= pivot && j <= right)
    {
        if (vec[i] < vec[j])
        {
            a[pos++] = vec[i++];
        }
        else
        {
            a[pos++] = vec[j++];
        }
    }
    
    while (i <= pivot) a[pos++] = vec[i++];
    while (j <= right) a[pos++] = vec[j++];
    
    for (int i = left; i<right-left+1; ++i)
    {
        std::cout << a[i] << " ";
        vec[right+i] = a[i];
    }
    std::cout << "\n=========\n";
}

void mergesort(std::vector<int>& vec, int left, int right)
{
    if (left < right)
    {
        int pivot = (right + left)/2;

        mergesort(vec, left, pivot);
        mergesort(vec, pivot+1, right);
        merge(vec, left, pivot, right);
    }
}

int main()
{
    std::vector<int> vec = {3, 7, 8, 2, 4, 6, 1, 5};

    mergesort(vec, 0, 5);

    for (auto el : vec) std::cout << el << "\n";
    return 0;
}