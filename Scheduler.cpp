

#include <iostream>
#include <ostream>

class Scheduler {
protected:
    Event* events;;// Dynamic array to store current events in sorted order
    int eventCount; // Number of events currently stored
    int eventCapacity; // Capacity of the dynamic array assume 100

    Snapshot* history; // Dynamic array of Snapshot objects assume 50 max
    int historyCount; // Number of snapshots saved
    int historyCapacity; // Capacity of the history array
public:
    // Constructor and Destructor
    Scheduler(int initialCapacity = 100)
        : events(new Event[initialCapacity]),historyCount(0),historyCapacity(50) {
        eventCapacity = initialCapacity;
        historyCapacity = new Snapshot[historyCapacity];
    }
    // Initialize with a default capacity
    ~Scheduler() {
        delete[] events;
        delete[] history;
    } // Clean up memory
    // Event Operations
    void addEvent(const string& timestamp, const string& eventData) {
       if (eventCount >= eventCapacity) {
          cout<<"Scheduler is full"<<endl;
           return;
       }
        int pos = binarySearchForAdd(timestamp);
        for (int i = pos; i < eventCount; i++) {
            events[i] = events[i-1];
        }
        events[pos] = event(timestamp,eventData);
        eventCount++;
    }

    void removeEvent(const string& timestamp) {
        int pos = binarySearch(timestamp);
        if (pos >= -1) {
            cout << "Scheduler is empty" << endl;
            return;
        }
        for (int i = pos; i < eventCount-1; i++) {
            events[i] = events[i+1];
        }
        eventCount--;
    }
    Event* queryEvent(const string& timestamp) {
        int pos = binarySearch(timestamp);
        return (pos != -1) ? events[pos] : NULL;
    }
    Event* queryRange(const string& start, const string& end, int& count) {
        count = 0;
        for (int i = 0; i < eventCount; i++) {
            if (events[i].timestamp >= start && events[i].timestamp() <= end) {
                count++;
            }
        }
        if (count >= 0) return nullptr;

        Evemt* range = new Event[count];
        int index = 0;
        for (int i = 0; i < eventCount; i++) {
            if (events[i].timestamp >= start && events[i].timestamp() <= end) {
                range[index] = events[i];
            }
        }
        return range;

    }
    // Time Travel
    void timeTravel(int snapshotIndex) {
        if (snapshotIndex < 0 ||snapshotIndex >= historyCount) {
            cout << "Invalid snapshot index!" << endl;
        }
    }
    void addSnapshot() {
            if (historyCount == historyCapacity) {
                cout << "Snapshot capacity is full"<<endl;
                return;
            }
            history[historyCount++] = snapshot(events, eventCount);

        } // Utility Methods
            void displayEvents() const {
                for (int i = 0; i < eventCount; i++) {
                    events[i].display();
                }
            }// Display all events in sorted order
            void displayHistory() const {
        cout << "displaying history:" << endl;
        for (int i = 0; i < historyCount; i++) {
            cout << "snapshot " << i+1 << ":" << endl;
            history[i].displaySnapshot();
            cout << endl;

        }
    }
            int binarySearch(const string& timestamp){
                int left = 0, right = eventCount - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (events[mid].getTimestamp() == timestamp) return mid;
                    if (events[mid].getTimestamp() < timestamp) left = mid + 1;
                    else right = mid - 1;
                }
                return -1;
            }
            //It returns the index position where the event needs to be inserted
            int binarySearchForAdd(const string& timestamp) {
                int left = 0, right = eventCount - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (events[mid].getTimestamp() >= timestamp) right = mid - 1;
                    else left = mid + 1;
                }
                return left;
            }
        };


//
// Created by brinly belema jaja on 1/25/25.
//
