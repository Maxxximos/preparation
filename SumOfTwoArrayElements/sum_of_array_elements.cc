/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sum_of_array_elements.cc
 * Author: mzhirkov
 *
 * Created on February 19, 2017, 10:40 AM
 */

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void print_pairs_add_up_to_number(std::vector<int>& vec, int sum)
{
    std::unordered_set<int> uset;

    for (auto val : vec)
    {
        if (uset.find(val) != uset.end())
        {
            std::cout << sum-val << " " << val << "\n";
        }
        uset.insert(sum - val);
    }
    
}

/*
 * 
 */
int main(int argc, char** argv)
{
    std::map<int, unsigned> occurrences;
    std::vector<int> vec = { 1,2,3,4,5,6 };
    int sum = 0;
    
    std::cin >> sum;
    
    print_pairs_add_up_to_number(vec, sum);

    return 0;
}

