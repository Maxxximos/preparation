/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   first_unique_character.cc
 * Author: mzhirkov
 *
 * Created on March 19, 2017, 1:09 PM
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <utility>
#include <limits>

using namespace std;

std::pair<char, int> get_first_unique_character(const std::string& str)
{
    std::unordered_map<char, std::pair<int, int>> umap;
    
    int idx = 0;
    for (auto el : str)
    {
        ++umap[el].first;
        umap[el].second = ++idx;
    }
    
    int min_idx = std::numeric_limits<int>::max();
    for (auto it = umap.begin(); it != umap.end(); ++it)
    {
        std::cout << "ch " << it->first  << " no_of_occ " << it->second.first << " idx " << it->second.second << "\n";
        
        if (it->second.first == 1 && it->second.second < min_idx)
        {
            std::cout << "it->second.second " << it->second.second << "\n";
            min_idx = it->second.second;
        }
    }
    
    
    return std::make_pair<char, int>(static_cast<char>(str[min_idx-1]), static_cast<int>(min_idx-1));
}

int main(int argc, char** argv)
{

    std::pair<char, int> pair = get_first_unique_character("abcabrrqcbcaac");
    std::cout << pair.first << " " << pair.second << "\n";
    return 0;
}

