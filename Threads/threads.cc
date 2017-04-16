/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   threads.cc
 * Author: mzhirkov
 *
 * Created on February 28, 2017, 2:01 PM
 */

#include <iostream>
#include <thread>
#include <string>

using namespace std;

void execute(std::string& str) //-- (1) 
{
    str.assign("Hallo Welt!"); 
}
void oops(const char* parameter)
{ 
    std::string greeting("Hello World!");
    std::thread worker_thread(execute, std::ref(greeting)); //-- (2) 
    worker_thread.join();
    std::cout<< greeting << std::endl; //-- (3)
}

int main(int argc, char** argv)
{

    oops("QQQ");
    return 0;
}

