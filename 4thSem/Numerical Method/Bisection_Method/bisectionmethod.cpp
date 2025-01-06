// Program to find the roots of a non-linear equation using the Bisection Method
#include<iostream>
#include<math.h> // For fabs() function
#include<conio.h> 

// Define the function f(x) = x^2 - 3x + 2
#define f(x) (x * x - 3 * x + 2)

// Define the tolerance for the root approximation
#define E 0.001

using namespace std;

int main() {
    float x1, x2, xm; // Variables for initial guesses and midpoint

    // Loop to ensure the initial guesses bracket the root
    do {
        cout << "Enter Two Initial Guesses: " << endl;
        cin >> x1 >> x2;
    } while (f(x1) * f(x2) > 0); // Check if f(x1) and f(x2) have opposite signs

    // Bisection Method Iteration
    do {
        xm = (x1 + x2) / 2; // Calculate the midpoint

        // Update the interval based on the sign of f(xm)
        if (f(xm) * f(x1) < 0) {
            x2 = xm; // Root lies in the left subinterval
        } else {
            x1 = xm; // Root lies in the right subinterval
        }
    } while (fabs(x1 - x2) > E); // Repeat until the interval width is within tolerance

    // Output the approximate root
    cout << "The root is: " << xm;

    getch(); // Wait for user input before closing the console (not recommended for modern C++)
    return 0;
}

/*
OUTPUT:
Enter Two Initial Guesses:
-1
1.5
The root is: 1.00012
*/
