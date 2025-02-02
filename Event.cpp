#include <iostream>
#include <string>
using namespace std;

class Event {
protected:
    string timestamp; // Timestamp of the event
    string eventData; // Description or data associated with the event
public:
    // Constructor
    Event(const string& timestamp, const string& eventData)
        : timestamp(timestamp), eventData(eventData) {}
    // Getters
    string getTimestamp() const{return timestamp;};
    string getEventData() const{return eventData;};
    // Setters
    void setTimestamp(const string& timestamp){this->timestamp = timestamp;};
    void setEventData(const string& eventData){this-> eventData = eventData;};
    // Comparison Operators (for sorting and searching)
    bool operator< (const Event& other) const{return timestamp < other.timestamp;};
    bool operator> (const Event& other) const{return timestamp > other.timestamp;};
    bool operator== (const Event& other) const{return timestamp == other.timestamp;};
    // Display Method
    void display() const {
        cout << timestamp << " " << eventData << endl;
    }
};//
// Created by brinly belema jaja on 1/25/25.
//
