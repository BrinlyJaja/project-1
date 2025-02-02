


class Event;

class Snapshot {
protected:
    Event* events; // Pointer to a dynamic array of events
    int numEvents; // Number of events in the snapshot
public:
    // Constructor
    Snapshot(Event* eventsArray, int size)
        :numEvents(size) {
        events = new Event[size];
        for (int i = 0; i < size; i++) {
            Events[i] = eventsArray[i];
        }
    }
    //you need to copy from eventsArray
    //to events one by one with a loop
    // Destructor
    ~Snapshot() {
        delete[] Events;
    }
    // Accessors
    Event* getEvents() const{ return events; };
    int getNumEvents() const{ return numEvents; };
    // Utility
    void displaySnapshot() const {
        for (int i = 0; i < numEvents; i++) {
            Events[i].display();
        }
    };
};
