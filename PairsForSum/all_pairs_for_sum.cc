/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   all_pairs_for_sum.cc
 * Author: mzhirkov
 *
 * Created on February 20, 2017, 11:21 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unistd.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    int sum = 10;
    std::vector<int> vec = {2, 3, 5, 1, 7, 8, 5, 2, 5, 5,5};
    std::unordered_map<int, int> umap;
    
    for (int i=0; i<vec.size(); ++i)
    {
        umap[vec[i]] = 1;
    }
    
    for (int i=0; i<vec.size(); ++i)
    {
//        std::cout << "vec idx " << (sum-vec[i]) << "\n";
        if (umap[sum-vec[i]]) 
        {
            //if (((sum-vec[i]) + (sum-vec[i]) == sum) && umap[sum-vec[i]] == 1) continue;
//            std::cout << "vec idx " << sum-vec[i] << "\n";
            std::cout << vec[i] << " " << sum-vec[i] << "\n";
            umap[vec[i]] = 0;
        }
    }
  

/* Second O(n*log(n))*/    
    
//    std::sort(vec.begin(), vec.end());
//    
//    auto left = vec.begin();
//    auto right = vec.end()-1;
//    while (left < right)
//    {
//        if ((*left + *right) < sum)
//        {
//            ++left;
//        }
//        else if ((*left + *right) > sum)
//        {
//            --right;
//        }
//        else if ((*left + *right) == sum)
//        {
//            std::cout << *left << " " << *right << "\n";
//            ++left;
//            --right;
//        }
//    }

    return 0;
}

