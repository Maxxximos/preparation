/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.cc
 * Author: mzhirkov
 *
 * Created on February 12, 2017, 3:13 AM
 */


#include <iostream>
#include <cstdio>

#include <unistd.h>
#include <memory>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <math.h>
#include <thread>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>
#include <queue>
#include <mutex>
#include <algorithm>
#include <functional>
#include <iterator>
#include <fstream>
#include <atomic>

class List
{
private:
    List* head, *tail, *prev, *next;
    int value;
    int size = 0;

    List(int val)
        : value(val),
          head(nullptr),
          tail(nullptr),
          prev(nullptr),
          next(nullptr) {};

public:
    explicit List()
        : head(nullptr),
          tail(nullptr),
          prev(nullptr),
          next(nullptr) {};

    explicit List(const List& lst)
    {
        std::cout << "Assignment constructor\n";
        value = lst.value;
    }

    ~List()
    {
        while (not empty())
        {
            pop_back();
        }
    }

    void push_front(int val)
    {
        if (head == nullptr and tail == nullptr)
        {
            head = new List(val);
            tail = head;
        }
        else
        {
            next = head;
            head = head->prev;
            head = new List(val);
            head->next = next;
            next->prev = head;
        }
        
        ++size;
//std::cout << "3 head: " << head << " tail: " << tail << " prev: " << head->prev << " next: " << head->next << " val " << head->value << "\n";
    }

    void pop_front()
    {
        if (empty())
        {
            return;
        }

        if (head != tail)
        {
            List* tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp;
            --size;
        }
        else
        {
            delete head;
            head = tail = nullptr;
            size = 0;
        }
//std::cout << "4 head: " << head << " tail: " << tail << " prev: " << head->prev << " next: " << head->next << " val " << head->value << "\n";
    }

    void push_back(int val)
    {
        if (tail == nullptr and head == nullptr)
        {
            tail = new List(val);
            head = tail;
        }
        else
        {
            prev = tail;
            tail = tail->next;
            tail = new List(val);
            tail->prev = prev;
            prev->next = tail;
        }
        
        ++size;
//std::cout << "1 head: " << head << " tail: " << tail << " prev: " << tail->prev << " next: " << tail->next << " val " << tail->value << "\n";
    }

    void pop_back()
    {
        if (empty())
        {std::cout << "AAA\n";
            return;
        }

        if (tail != head)
        {
            List* tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;
            --size;
        }
        else
        {
            delete tail;
            tail = head = nullptr;
            size = 0;
        }
//std::cout << "2 head: " << head << " tail: " << tail << " prev: " << tail->prev << " next: " << tail->next << " val " << tail->value << "\n";
    }

    bool empty()
    {
        if (tail == nullptr and head == nullptr) return true;

        return false;
    }

    int front()
    {
        if (tail != nullptr and head != nullptr)
        {
            return head->value;
        }
        else
        {
            return 0;
        }
    }

    int back()
    {
        if (tail != nullptr and head != nullptr)
        {
            return tail->value;
        }
        else
        {
            return 0;
        }
    }

    void erase(List* node)
    {
        if (node == nullptr) std::cout << "node is nullptr\n";
        std::cout << "Not implemented: remove " << node->value << std::endl;
    }
    
    void unique()
    {
        std::unordered_set<int> uset;
        uset.reserve(size);
        List* iter_node = head;
        while (iter_node != nullptr)
        {
            std::unordered_set<int>::iterator it = uset.find(iter_node->value);
            if (it != uset.end())
            {
                erase(iter_node);
            }
            else
            {
                uset.insert(iter_node->value);   
            }

            iter_node = iter_node->next;
        }
    }
    
    List* go_forward()
    {
        static List* current_node = head;
        if (current_node == nullptr) { std::cout << "Finish\n"; return nullptr; }
        std::cout << "1 AAA current_node: " << current_node 
                  << " prev: " << current_node->prev << " next: " << current_node->next << " val " << current_node->value << "\n";
        current_node = current_node->next;
        return current_node;
    }
    void go_backward1()
    {
        if (tail->prev == nullptr) { std::cout << "Finish\n"; return; }
        std::cout << "2 AAA tail: " << tail << " prev: " << tail->prev << " next: " << tail->next << " val " << tail->value << "\n";
        tail = tail->prev;
    }
    void go_backward2()
    {
        if (tail == nullptr) { std::cout << "Finish\n"; return; }
        std::cout << "2 AAA tail: " << tail << " prev: " << tail->prev << " next: " << tail->next << " val " << tail->value << "\n";
        tail = tail->next;
    }
};

int main()
{
    List lst;

    lst.push_back(10);
    lst.push_back(9);
    lst.push_back(9);
    lst.push_back(9);
    lst.push_back(8);
    lst.push_back(7);
    lst.push_back(7);

    lst.push_front(4);
    lst.push_front(4);
    lst.push_front(3);
    lst.push_front(2);
    lst.push_front(1);
    lst.push_front(1);

//    while(not lst.empty())
//    {
//        int front = lst.front();
//        int back = lst.back();
//        std::cout << "front: " << front << " back: " << back << "\n";
//        lst.pop_back();
//        lst.pop_front();
//    }
//    
//    lst.unique();

}
