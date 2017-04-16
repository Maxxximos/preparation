/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   btree.cc
 * Author: mzhirkov
 *
 * Created on February 12, 2017, 3:44 AM
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <memory>

using namespace std;

class TrieNode
{
public:
    TrieNode() 
    {

    }
    
    ~TrieNode()
    {
        //delete head;
    }
private:
    std::unordered_map<char, std::shared_ptr<TrieNode>> child;
    bool is_end;
    int prefix_count = 0;
    std::shared_ptr<TrieNode> head = nullptr;
    
public:
    void add(std::string str) {
        if (head == nullptr) {
            head = std::make_shared<TrieNode>();
            head->is_end = false;
            ++head->prefix_count;
        }
        std::shared_ptr<TrieNode> cur = head;
        
        for (auto ch : str) {
            auto it = cur->child.find(ch);
            
            if (it == child.end()) {
                std::shared_ptr<TrieNode> new_node = std::make_shared<TrieNode>();
                new_node->is_end = false;
                it = cur->child.insert({ch, new_node}).first;
            }
            ++it->second->prefix_count;
            cur = it->second;
        }
        cur->is_end = true;
    }

    int find(std::string str) {
        if (head == nullptr) {
            return 0;
        }

        std::shared_ptr<TrieNode> cur = head;
        
        for (auto ch : str) {            
            auto it = cur->child.find(ch);
            
            if (it == child.end()) {
                return 0;
            }
            cur = it->second;
        }
        
        return cur->prefix_count;
    }
};

int main(){
    TrieNode trie;
    int n, count = 0;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;

        if (op == "add")
        {
            trie.add(contact);
        }
        else if (op == "find")
        {
            count += trie.find(contact);
            std::cout << count << std::endl;
            count = 0;
        }
    }

    return 0;
}