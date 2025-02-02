#include <iostream>
#include <string>
using namespace std;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
 Scheduler scheduler; // Create an instance of the scheduler
    string command;

    while (true) {
        getline(cin, command);
        // Read an entire line of input
        if (command == "EXIT")
            break;
        // Parse the command and execute appropriate actions
        if (command.rfind("ADD", 0) == 0)
        {
            // Format: ADD <timestamp> <eventData>
            string timestamp = command.substr(4, 16);
            string eventData = command.substr(21); // Extract the event data
            if (!eventData.empty() && (eventData.back() == '\n' || eventData.back() == '\r')) {
                eventData.pop_back();
            }
            scheduler.addEvent(timestamp, eventData);
        }
        else if (command.rfind("REMOVE", 0) == 0)
        {
            // Format: REMOVE <timestamp>
            string timestamp = command.substr(7, 16);
            scheduler.removeEvent(timestamp);
        }
        else if (command.rfind("QUERY", 0) == 0 && command.find("QUERYRANGE") == string::npos)
        {
            // Format: QUERY <timestamp>
            string timestamp = command.substr(6, 16);
            Event* event = scheduler.queryEvent(timestamp);
            if (event)
            {
                event->display();
            }
            else
            {
                cout << "Event not found at timestamp " << timestamp << endl;
            }
        }
        else if (command.rfind("SNAPSHOT", 0) == 0)
        {
            // Manually create a snapshot
            scheduler.addSnapshot();
            cout << "Snapshot created." << endl;
        }
        else if (command.rfind("QUERYRANGE", 0) == 0)
        {
            // Format: QUERYRANGE <startTimestamp> <endTimestamp>
            size_t spacePos = command.find(' ', 11);
            size_t nextSpacePos = command.find(' ', spacePos + 1);

            string startTS = command.substr(11, nextSpacePos - 11);
            string endTS = command.substr(nextSpacePos + 1);
            int count = 0;
            Event* events = scheduler.queryRange(startTS, endTS, count);
            if (events)
            {
                for (int i = 0; i < count; ++i)
                {
                    events[i].display();
                }
                delete[] events; // Free the dynamically allocated memory
            }
            else
            {
                cout << "No events found in the range " << startTS << " to " << endTS << endl;
            }
        }
        else if (command.rfind("DISPLAY", 0) == 0)
        {
            scheduler.displayEvents();
        }
        else if (command.rfind("SHOWSNAPSHOTS", 0) == 0)
        {
            // Display available snapshots
            scheduler.displayHistory();
        }
        else if (command.rfind("TIMETRAVEL", 0) == 0)
        {
            // Format: TIMETRAVEL <snapshotIndex>
            int snapshotIndex = stoi(command.substr(11));
            scheduler.timeTravel(snapshotIndex);
            cout << "Time traveled to snapshot " << snapshotIndex << "." << endl;
        }

    }

    cout << "Scheduler program exited." << endl;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.