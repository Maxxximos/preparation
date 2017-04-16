/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   adjacent_words.cc
 * Author: mzhirkov
 *
 * Created on March 9, 2017, 1:30 PM
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void print_indices_of_adjacent_words(const std::vector<std::string>& vec, const std::string& str1, const std::string& str2)
{
    for (int i = 0; i<vec.size()-1; ++i)
    {
        if (vec[i] == str1)
        {
            if (vec[i+1] == str2) std::cout << i << " " << i+1 << "\n";
        }
        else if (vec[i] == str2)
        {
            if (vec[i+1] == str1) std::cout << i << " " << i+1 << "\n";
        }
    }
}


int main(int argc, char** argv)
{
    std::vector<std::string> v = {"hello", "my", "name", "name", "name", "Jhon", "Jhon", "name", "Jhon", "how", "are", "are", "name", "name", "you", "name"};
    
    print_indices_of_adjacent_words(v, "name", "Jhon");

    return 0;
}

