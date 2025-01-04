// Program to solve Tower of Hanoi for 3 or higher disks.
#include <iostream>
#include <conio.h> // for getch()

using namespace std;

int count = 0; // Global variable to count the number of steps

// Recursive function to solve Tower of Hanoi
void TOH(int n, string src, string helper, string dest) {
    if (n == 1) {
        // Base case: move one disk directly
        cout << "Move disk 1 from " << src << " to " << dest << "." << endl;
        count++; // Increment step count
    } else {
        // Recursive case
        TOH(n - 1, src, dest, helper); // Move n-1 disks from src to helper
        cout << "Move disk " << n << " from " << src << " to " << dest << "." << endl;
        count++; // Increment step count
        TOH(n - 1, helper, src, dest); // Move n-1 disks from helper to dest
    }
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of disks must be greater than 0!" << endl;
        return 0;
    }

    // Solve Tower of Hanoi
    TOH(n, "A", "B", "C"); // A: source, B: helper, C: destination

    // Display total number of steps
    cout << "\nTotal number of steps: " << count << endl;

    getch(); // Wait for user input before exiting (specific to Windows)
    return 0;
}
