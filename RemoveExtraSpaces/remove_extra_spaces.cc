/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   remove_extra_spaces.cc
 * Author: mzhirkov
 *
 * Created on March 6, 2017, 11:18 AM
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


void remove_extra_spaces(std::string& str)
{
    int j = 0;
    int space_count = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] != ' ')
        {
            str[j] = str[i];
            ++j;
            space_count = 0;
        }
        else if (str[i] == ' ')
        {
            ++space_count;
            if (space_count <= 1)
            {
                str[j] = str[i];
                ++j;
            }
        }
    }
    str.resize(j);
}

std::string reduced_str(const std::string& str)
{
    std::string str2;
    
    int count = 1;

    for (int i=0; i<str.size()-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            ++count;
        }
        else if (str[i] != str[i+1] && count != 1)
        {
            str2 += std::to_string(count);
            str2.push_back(str[i]);
            count = 1;
        }
        else
        {
            str2.push_back(str[i]);
        }
    }
    
    if (count == 1)
    {
        str2.push_back(str[str.size()-1]);
    }
    else
    {
        str2 += std::to_string(count);
        str2.push_back(str[str.size()-1]);
    }
    
    return str2;
}


/*
 * 
 */
int main(int argc, char** argv)
{
    std::string str = "bbbcbbbaaaffdddd";
    std::string str2(str);
    
    str.erase(std::remove_if(str.begin(), str.end(), [](char ch){}))
    
    std::cout << str2 << "\n";
    return 0;
}

