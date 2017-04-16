/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reduced_string.cc
 * Author: mzhirkov
 *
 * Created on February 26, 2017, 1:29 PM
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    std::string str("baaba");
    std::unordered_multimap<char, int> umap;
    int i = 0;
    
    for (auto el : str)
    {
//        umap.insert({el, ++i});
    }
    
    for (auto el : str)
    {
        auto it = umap.find(el);
        
        if (it != umap.end())
        {
//            std::cout << it->first << " " << it->second << "\n";
            ++it->second;
        }
        else
        {
            umap.insert({el, 1});
        }
    }
    
    for (auto it = umap.begin(); it != umap.end(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
    return 0;
}

