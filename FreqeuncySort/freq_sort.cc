/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   freq_sort.cc
 * Author: mzhirkov
 *
 * Created on March 19, 2017, 11:36 PM
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void freq_sort(std::vector<int>& vec)
{
    std::vector<int> tmp(vec.size());
    
    for (auto el : vec)
    {
        ++tmp[el];
    }
    
    std::sort(vec.begin(), vec.end(), [&tmp](int a, int b) 
                                      {
                                         return tmp[a] > tmp[b] || (tmp[a] == tmp[b] && a < b); 
                                      } );
}

int main(int argc, char** argv)
{
    std::vector<int> vec = {2,5,1,4,5,7,6,5,5,7,2,4,8,7,3};
    
    freq_sort(vec);
    
    for (auto el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";
    return 0;
}

