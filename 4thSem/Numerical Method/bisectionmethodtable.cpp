#include <iostream>
#include <cmath>
#include <iomanip> // For output formatting
using namespace std;

// Define the function for which the root is to be found
double f(double x) {
    return x * x - 4; // Question: f(x) = x^2 - 4
}

int main() {
    double a, b, mid, tolerance;
    int maxIterations, iterations = 0;

    // Input the interval [a, b], tolerance, and max iterations
    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter the tolerance: ";
    cin >> tolerance;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    // Validate the interval
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. The function must have opposite signs at a and b.\n";
        return 1;
    }

    // Header for tabulated output
    cout << "\nIteration   a           b           mid         f(mid)\n";
    cout << "----------------------------------------------------------\n";

    // Bisection Method
    do {
        mid = (a + b) / 2.0; // Calculate the midpoint
        cout << setw(10) << iterations + 1 << setw(12) << a << setw(12) << b
             << setw(12) << mid << setw(12) << f(mid) << endl;

        // Check if f(mid) is close enough to zero
        if (fabs(f(mid)) <= tolerance) {
            cout << "\nRoot found at x = " << mid << " after " << iterations + 1 << " iterations.\n";
            return 0;
        }

        // Update the interval
        if (f(a) * f(mid) < 0) {
            b = mid; // Root is in the left subinterval
        } else {
            a = mid; // Root is in the right subinterval
        }

        iterations++;
    } while (iterations < maxIterations);

    // If the root is not found within the maximum iterations
    cout << "\nThe root was not found within " << maxIterations << " iterations.\n";
    cout << "Closest approximation is x = " << mid << " with f(x) = " << f(mid) << endl;

    return 0;
}
