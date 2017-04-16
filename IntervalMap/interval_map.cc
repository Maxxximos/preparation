/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interval_map.cc
 * Author: mzhirkov
 *
 * Created on March 11, 2017, 2:17 AM
 */

#include <iostream>
#include <assert.h>
#include <map>
#include <limits>

template<class K, class V>
class interval_map {
    friend void IntervalMapTest();

private:
    std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val ) {
        m_map.insert(m_map.begin(), std::make_pair(std::numeric_limits<K>::lowest(),val));
    };

    // Assign value val to interval [keyBegin, keyEnd). 
    // Overwrite previous values in this interval. 
    // Do not change values outside this interval.
    // Conforming to the C++ Standard Library conventions, the interval 
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval, 
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, const V& val ) {    
        if ( !( keyBegin < keyEnd ) ) return;

        auto start_interval_iter = m_map.lower_bound(keyBegin);
        auto end_interval_iter = m_map.upper_bound(keyEnd);

        // If interval_map does not contain any elements except the first one which is added from constructor
        if (start_interval_iter == m_map.end())
        {
            auto tmp_it = (--end_interval_iter);
            std::pair<K, V> tmp_pair = std::make_pair(keyEnd, tmp_it->second);
            m_map.insert({keyBegin, val});
            m_map.insert(tmp_pair);
        }
        // If interval_map contains lower bound element
        else
        {
            auto end_it = end_interval_iter;
            auto tmp_it = (--end_interval_iter);
            std::pair<K, V> tmp_pair = std::make_pair(keyEnd, tmp_it->second);
            
            // If lower bound element key is equal to keyBegin
            if (start_interval_iter->first == keyBegin)
            {
                auto start_interval_iter = m_map.lower_bound(keyBegin);

                start_interval_iter->second = val;
            }
            // If lower bound element key is not equal to keyBegin
            else
            {
                m_map.insert({keyBegin, val});

                start_interval_iter = m_map.lower_bound(keyBegin);
            }

            typename std::map<K, V>::iterator cur_iter = start_interval_iter;
            ++cur_iter;
            while (cur_iter != end_it)
            {
                if (cur_iter != end_it)
                {
                    m_map.erase(cur_iter);
                }
                cur_iter = start_interval_iter;
                ++cur_iter;
            }
            m_map.insert(tmp_pair);
        }

        // Remove duplicates from our interval_map (consecutive map entries must not have the same value: ..., (0,'A'), (3,'A'), ...)
        auto iter_cur_adjacent = m_map.begin();
        ++iter_cur_adjacent;
        for (auto iter_next_adjacent = m_map.begin(); iter_next_adjacent != m_map.end(); ++iter_next_adjacent)
        {
            if (iter_cur_adjacent->second == iter_next_adjacent->second)
            {
                m_map.erase(iter_cur_adjacent);
                iter_cur_adjacent = m_map.begin();
            }
            
            ++iter_cur_adjacent;
        }
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a function IntervalMapTest() here that tests the
// functionality of the interval_map, for example using a map of unsigned int
// intervals to char.
void IntervalMapTest()
{
    interval_map<int, char> imap('A');
    


    imap.assign(4, 9, 'T');
    imap.assign(1, 6, 'W');
    imap.assign(0, 5, '*');
   

    
    std::cout << imap[0] << "\n";
    std::cout << imap[1] << "\n";
    std::cout << imap[2] << "\n";
    std::cout << imap[3] << "\n";
    std::cout << imap[4] << "\n";
    std::cout << imap[5] << "\n";
    std::cout << imap[6] << "\n";
    std::cout << imap[7] << "\n";
    std::cout << imap[8] << "\n";
    std::cout << imap[9] << "\n";
    std::cout << imap[10] << "\n";
    std::cout << imap[11] << "\n";
    std::cout << imap[12] << "\n";
    std::cout << imap[13] << "\n";
    std::cout << imap[14] << "\n";
    std::cout << imap[15] << "\n";
//    for (auto it = imap.m_map.begin(); it != imap.m_map.end(); ++it)
//    {
//        std::cout << it->first << " " << it->second << "\n";
//    }
    std::cout << "\n";
    
    return;
}

int main(int argc, char* argv[]) {
    IntervalMapTest();
    return 0;
}

