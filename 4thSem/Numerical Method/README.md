# Lab 1: Bisection Method for Root Finding

## Description
This lab implements the **Bisection Method**, a numerical technique used to find the root of a non-linear equation. The method is based on repeatedly bisecting an interval and selecting the subinterval in which the root lies.

## Concept
The Bisection Method relies on the **Intermediate Value Theorem**, which states that if a continuous function changes sign over an interval, it must have at least one root within that interval. The method narrows down the interval by repeatedly dividing it into two halves and selecting the half that contains the root.

## Algorithm
1. Start with an interval `[x1, x2]` where `f(x1)` and `f(x2)` have opposite signs.
2. Compute the midpoint `xm = (x1 + x2) / 2`.
3. Evaluate `f(xm)`:
   - If `f(xm) == 0`, then `xm` is the root.
   - If `f(xm)` has the same sign as `f(x1)`, update `x1 = xm`.
   - Otherwise, update `x2 = xm`.
4. Repeat steps 2-3 until the interval width `(x2 - x1)` is less than a specified tolerance `E`.

## Code Explanation
The provided C++ code implements the Bisection Method:
- The function `f(x)` defines the equation `x^2 - 3x + 2`.
- The user is prompted to enter two initial guesses `x1` and `x2` that bracket the root.
- The `while` loop ensures the guesses are valid (i.e., `f(x1)` and `f(x2)` have opposite signs).
- The bisection loop calculates the midpoint `xm` and updates the interval until the root is found within the specified tolerance `E`.

## Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/Numerical-Methods.git

## OUTPUT

Enter Two Initial Guesses:
-1
1.5
The root is: 1.00012




#### `LICENSE`
Choose an appropriate open-source license (e.g., MIT, Apache 2.0) and include it in the repository.

#### `Makefile`
```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = bisection

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

clean:
	rm -f $(TARGET)