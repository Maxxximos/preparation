/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   experiments.cc
 * Author: mzhirkov
 *
 * Created on March 10, 2017, 12:41 PM
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

void reverse_number(int val)
{
    int val_fl = val;
    int len = 1;
    int fin = 0;
    
    while (val_fl /= 10)
    {
        ++len;
    }
    
    for (int i=len; i>0; --i)
    {
        int tmp = 0;
        int aux = (val / pow(10, (len - i)));
        tmp = aux % 10;
        fin += tmp * pow(10, i - 1);
    }
    std::cout << fin << "\n";
}

void sum_of_each_three_element(std::vector<int> vec)
{
    std::vector<int> sums;

    int j = -1;
    for (int i=0; i<vec.size(); ++i)
    {
        if (i % 3 == 0)
        {
            std::cout << "push " << vec[i] << "\n";
            sums.push_back(vec[i]);
            ++j;
        }
        else
        {
            std::cout << "calc " << vec[i] << "\n";
            sums[j] += vec[i];
            std::cout << "sum " << sums[j] << "\n";
        }
    }
    
    for (auto el : sums)
    {
        std::cout << el << "\n";
    }
}

void multiplication_of_each_except_current()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> mults;
    int mult = 1;
    
    for (int i=0; i<vec.size(); ++i)
    {
        mult *= vec[i];
    }

    for (int k=0; k<vec.size(); ++k)
    {
        mults.push_back(mult/vec[k]);
    }

    for (auto el : mults)
    {
        std::cout << el << "\n";
    }
    
}

struct A
{
    virtual void foo() {};
};

class B final : public A
{
public:
    virtual void foo() final
    {};
    mutable int x;
};

class C
{
public: 
    void foo() const { x = 100;};
        mutable int x;
};



int main(int argc, char** argv)
{

}

