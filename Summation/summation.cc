/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   summation.cc
 * Author: mzhirkov
 *
 * Created on February 20, 2017, 2:30 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;


double sum1(std::vector<double>& v)
{ 
if (v.empty()) {
return 0.0;
}
for(size_t i = 0; i < v.size() - 1; ++i) {
std::sort(v.begin()+i, v.end());
v[i+1] += v[i];
}
return v.back();
}

double sum2(std::vector<double>& v)
{ 
if (v.empty()) {
return 0.0;
}
for(size_t i = 0; i < v.size() - 1; ++i) {
std::partial_sort(v.begin() + i, v.begin() + i + 2, v.end());
v[i+1] += v[i];
}
return v.back();
}

double sum3(std::vector<double>& v)
{ 
    std::multiset<double> set(v.begin(), v.end());
    while (set.size() > 1) {
        std::multiset<double>::const_iterator itA = set.begin();
        std::multiset<double>::const_iterator itB = ++set.begin();
        double c = *itA + *itB;
        std::cout << c << "\n";
        set.erase(itA, ++itB);
        set.insert(c);
        std::cout << set.size() << "\n";
    }
    return !set.empty() ? *set.begin() : 0.0;
}

double nextLetter()
{
    double r = ((double) rand() / (double) RAND_MAX) * 100 ;
    return r;
}

#define MAX_NO 10000
#include <chrono>
int main(int argc, char** argv)
{
//    std::vector<double> arr1(MAX_NO);
//    std::vector<double> arr2(MAX_NO);
//    std::vector<double> arr3(MAX_NO);
//
//    std::generate_n( arr1.begin(), MAX_NO, nextLetter );
//    random_shuffle(arr1.begin(), arr1.end());
//    arr3 = arr2 = arr1;
//
//    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//    sum3(arr1);
//    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "\n";
//    return 0;
    
}

