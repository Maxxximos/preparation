/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sort_by_frequency.cc
 * Author: mzhirkov
 *
 * Created on February 20, 2017, 5:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    std::vector<int> vec = {7, 7, 3, 1, 5, 2, 7, 5, 3, 3, 1, 1, 1, 1, 10};

    std::unordered_map<int, int> cont;
    
    for (auto el : vec)
    {
        ++cont[el];
    }

    std::vector<std::pair<int, int>> v;
    std::copy(cont.begin(),
              cont.end(),
              std::back_inserter<std::vector<std::pair<int, int> > >(v));
    
    std::sort(v.begin(), v.end(), [](std::pair<int, int> a, std::pair<int, int> b){ return a.second > b.second; });
    
    for (auto el : v)
    {
         //std::cout << el.first << ":" << el.second << " | ";
        for (int i=0; i<el.second; ++i)
        {
            std::cout << el.first << " ";
        }
    }

    return 0;
}

