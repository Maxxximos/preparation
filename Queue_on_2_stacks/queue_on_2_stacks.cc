/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue_on_2_stacks.cc
 * Author: mzhirkov
 *
 * Created on February 26, 2017, 11:59 AM
 */

#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class Queue
{
private:
    std::stack<int> new_stack;
    std::stack<int> old_stack;
    
    void shift_values() {
        if (old_stack.empty()) {
            while (! new_stack.empty()) {
                old_stack.push(new_stack.top());
                new_stack.pop();
            }
        }
    }
    
public:
    void enqueue(int val) {
        new_stack.push(val);
    }
    
    int dequeue() {
        int val = 0;
        shift_values();
        
        if (! old_stack.empty()) {
            val = old_stack.top();
            old_stack.pop();
        }

        return val;
    }
    
    int front() {
        int val = 0;
        shift_values();
        
        if (! old_stack.empty()) {
            val = old_stack.top();
        }

        return val;
    }
};

int main() {
    Queue q;
    int n = 0, event_no = 0, val = 0;
    std::cin >> n;
    
    while (n--) {
        std::cin >> event_no;
        switch (event_no) {
            case 1:
                std:cin >> val;
                q.enqueue(val);
                break;
            
            case 2:
                q.dequeue();
                break;
            
            case 3:
                std::cout << q.front() << "\n";
                break;
        }
    }
    return 0;
}
