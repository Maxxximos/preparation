/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   zeroes_to_end.cc
 * Author: mzhirkov
 *
 * Created on March 19, 2017, 10:48 PM
 */

#include <iostream>
#include <vector>

using namespace std;

void arrange_zeroes_to_the_end(std::vector<int>& vec)
{ 
    int count = 0;
    
    for (int i=0; i<vec.size(); ++i)
    {
        if (vec[i] != 0)
        {
            vec[count++] = vec[i];
        }
    }
    
    for (int k=count; k<vec.size(); ++k)
    {
        vec[k] = 0;
    }
}

int main(int argc, char** argv)
{
    std::vector<int> vec = {0,1,2,0,3,0,5,6,0,0,1,9,3,0,0};
    
    arrange_zeroes_to_the_end(vec);
    
    for (auto el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";
    return 0;
}

