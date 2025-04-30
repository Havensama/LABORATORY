#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int choice; // Variable to store the user's choice
    char name[50]; // Array to store the user's name
    int age;       // Variable to store the user's age

    // Display the menu
    cout << "Choose an option:\n";
    cout << "1. Create and write to a file\n";
    cout << "2. Read from a file\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Clear the input buffer

    switch (choice) {
        case 1: {
            // Option 1: Create and write to a file
            ofstream outfile("user.txt");
            cout << "Enter your name: ";
            cin.getline(name, 50); // Read the user's name
            cout << "Enter your age: ";
            cin >> age;            // Read the user's age

            // Write the user's name and age to the file
            outfile << name << endl << age << endl;
            outfile.close(); // Close the output file
            cout << "Data written to file successfully.\n";
            break;
        }
        case 2: {
            // Option 2: Read from a file
            ifstream infile("user.txt");
            if (infile.is_open()) {
                infile.getline(name, 50); // Read the name from the file
                infile >> age;            // Read the age from the file
                infile.close(); // Close the input file

                // Display the name and age read from the file
                cout << "Name: " << name << ", Age: " << age << endl;
            } else {
                cout << "Unable to open file.\n";
            }
            break;
        }
        default:
            // Handle invalid choices
            cout << "Invalid choice. Please select 1 or 2.\n";
            break;
    }

    return 0;
}