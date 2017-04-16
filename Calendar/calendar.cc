/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   calendar.cc
 * Author: mzhirkov
 *
 * Created on April 16, 2017, 12:21 PM
 */

#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <chrono>
#include <map>
#include <set>
#include <vector>

using namespace std;


class ConflictedTimeWindow {
 public:
  ConflictedTimeWindow(const string& start_date, const string& end_date, const set<int>& conflicted_event_ids) 
             : start_date_(start_date), end_date_(end_date), conflicted_event_ids_(conflicted_event_ids) {}

  string start_date() { return start_date_; }
  string end_date() { return end_date_; }
  set<int> conflicted_event_ids() { return conflicted_event_ids_; }

 private:
  string start_date_;
  string end_date_;
  set<int> conflicted_event_ids_;
};

class Event {
 public:
  Event(const int id, const string& start_date, const string& end_date) : id_(id), start_date_(start_date), end_date_(end_date) {}

  int id() { return id_; };
  string start_date() { return start_date_; }
  string end_date() { return end_date_; }

 private:
  int id_;
  string start_date_;
  string end_date_;
};

class Calendar {
public:
    // Should allow multiple events to be scheduled over the same time window.
    void Schedule(Event* event)
    {
        _event_map.emplace(to_unix_timestamp(event->start_date()), event);
    }
    
    vector<ConflictedTimeWindow> FindConflictedTimeWindows()
    {
        vector<ConflictedTimeWindow> output;
        
        Event* event = nullptr;
        for (auto it = _event_map.begin(); it != _event_map.end(); ++it)
        {
            if ( event == nullptr )
            {
                event = it->second;
                continue;
            }
            else if ( to_unix_timestamp(event->end_date()) <= it->first )
            {
                std::cout << "No intersection\n";
                event = it->second;
            }
            else if ( to_unix_timestamp(event->end_date()) > it->first )
            {
                //std::cout << it->second->start_date() << "    " << it->second->end_date() << "\n";
            }
        }

        for (auto it : _event_map)
        {
            std::cout << it.second->start_date() << "    " << it.second->end_date() << "\n";
        }
        
        return output;
    }
  
private:
    std::map<long, Event*> _event_map;
    
    long to_unix_timestamp(const std::string& date)
    {
        std::tm tm = {};
        std::stringstream ss(date);
        ss >> std::get_time(&tm, "%y-%m-%d %H:%M");
        //std::cout << asctime(&tm);
        std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
        std::chrono::system_clock::duration dtn = tp.time_since_epoch();
       // std::cout << dtn.count() << "\n";
        return dtn.count();
    }
};

// Helper Function for logging
string ToString(const set<int>& input) {
  ostringstream sstream;
  sstream << "[";
  bool has_data = false;
  for (set<int>::iterator it = input.begin(); it != input.end(); ++it) {
    has_data = true;
    sstream << *it;
    sstream << ", ";
  }
  string output = sstream.str();
  if (has_data) {
    output = output.substr(0, output.length() - 2);
  }
  return output + "]";
}

int main(int argc, char** argv)
{
//    std::tm tm = {};
//    std::stringstream ss("2014-01-01 10:00");
//    ss >> std::get_time(&tm, "%y-%m-%d %H:%M");
//    std::cout << asctime(&tm);
//    std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
//    std::chrono::system_clock::duration dtn = tp.time_since_epoch();
//    std::cout << dtn.count() << "\n";
//
//    std::tm tm2 = {};
//    std::stringstream ss2("2014-01-01 11:00");
//    ss2 >> std::get_time(&tm2, "%y-%m-%d %H:%M");
//    std::cout << asctime(&tm2);
//    std::chrono::system_clock::time_point tp2 = std::chrono::system_clock::from_time_t(std::mktime(&tm2));
//    std::chrono::system_clock::duration dtn2 = tp2.time_since_epoch();
//    std::cout << dtn2.count() << "\n";
//
//    std::cout << std::chrono::duration_cast<std::chrono::minutes>(tp2.time_since_epoch()).count() - std::chrono::duration_cast<std::chrono::minutes>(tp.time_since_epoch()).count() << "\n";
//    
    
    
    
    Calendar calendar;

    calendar.Schedule(new Event(1, "2014-01-01 10:00", "2014-01-01 11:00"));
    calendar.Schedule(new Event(2, "2014-01-01 11:00", "2014-01-01 12:00"));
    calendar.Schedule(new Event(3, "2014-01-01 12:00", "2014-01-01 13:00"));

    calendar.Schedule(new Event(4, "2014-01-02 10:00", "2014-01-02 11:00"));
    calendar.Schedule(new Event(5, "2014-01-02 09:30", "2014-01-02 11:30"));
    calendar.Schedule(new Event(6, "2014-01-02 08:30", "2014-01-02 12:30"));

    calendar.Schedule(new Event(7, "2014-01-03 10:00", "2014-01-03 11:00"));
    calendar.Schedule(new Event(8, "2014-01-03 09:30", "2014-01-03 10:30"));
    calendar.Schedule(new Event(9, "2014-01-03 09:45", "2014-01-03 10:45"));

    vector<ConflictedTimeWindow> conflicted_time_windows = calendar.FindConflictedTimeWindows();
    for (size_t i = 0; i < conflicted_time_windows.size(); ++i)
    {
        cout << conflicted_time_windows[i].start_date() << "-" << conflicted_time_windows[i].end_date() << ToString(conflicted_time_windows[i].conflicted_event_ids()) << endl;
    }
    // should print something like the following
    // 2014-01-02 09:30-2014-01-02 10:00[5, 6]
    // 2014-01-02 10:00-2014-01-02 11:00[4, 5, 6]
    // 2014-01-02 11:00-2014-01-02 11:30[5, 6]
    // 2014-01-03 09:45-2014-01-03 10:00[8, 9]
    // 2014-01-03 10:00-2014-01-03 10:30[7, 8, 9]
    // 2014-01-03 10:30-2014-01-03 10:45[7, 9]
    
    return 0;
}

