#include <iostream>
#include <string>
using namespace std;

// Maximum number of tasks
const int MAX_TASKS = 10;

// Struct to represent a task
struct Task {
    string description;
    bool completed;
};

class ToDoListManager {
private:
    Task tasks[MAX_TASKS];
    int numTasks;

public:
    ToDoListManager() : numTasks(0) {}

    // Add a task to the list
    void addTask(const string &description) {
        if (numTasks < MAX_TASKS) {
            tasks[numTasks] = {description, false};
            numTasks++;
            cout << "Task added successfully." << endl;
        } else {
            cout << "Task list is full. Cannot add more tasks." << endl;
        }
    }

    // View all tasks
    void viewTasks() {
        if (numTasks == 0) {
            cout << "No tasks to display.\n" << endl;
        } else {
            cout << "Tasks:" << endl;
            for (int i = 0; i < numTasks; ++i) {
                cout << i + 1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
            }
        }
    }

    // Mark a task as completed
    void markTaskAsCompleted(int index) {
        if (index >= 1 && index <= numTasks) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    // Remove a task
    void removeTask(int index) {
        if (index >= 1 && index <= numTasks) {
            for (int i = index - 1; i < numTasks - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            numTasks--;
            cout << "Task removed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

// Main function
int main() {
    ToDoListManager manager;
    int choice = 0;

    // Menu
    while (true) {
        cout << "\n1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform action based on user choice
        if (choice == 1) {
            cout << "Enter task description: ";
            std::string description;
            cin.ignore();
            std::getline(cin, description);
            manager.addTask(description);
        } else if (choice == 2) {
            manager.viewTasks();
        } else if (choice == 3) {
            cout << "Enter the index of the task to mark as completed: ";
            int index;
            cin >> index;
            manager.markTaskAsCompleted(index);
        } else if (choice == 4) {
            cout << "Enter the index of the task to remove: ";
            int index;
            cin >> index;
            manager.removeTask(index);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}





