#include <iostream>
#include <vector>
#include <functional>
#include "Arithmetic.h"

using namespace std;

// ---------- Event Handler ----------
void OnOverflow(const Arithmetic* sender, const OverflowEventArgs& args) {
    cout << "\n=== OVERFLOW EVENT ===\n";
    cout << "Operation: " << args.operation << "\n";
    cout << "Operands: " << args.a << ", " << args.b << "\n";
    cout << "Overflowed result: " << args.result << "\n";
    cout << "=======================\n\n";
}

// ---------- Function-like “delegate” ----------
int sum2D(const vector<vector<int>>& arr) {
    int sum = 0;
    for (auto& row : arr)
        for (int x : row) sum += x;
    return sum;
}

// ---------- Menu Interface ----------
void menu() {
    cout << "=============================\n";
    cout << "     Arithmetic Program\n";
    cout << "=============================\n";
    cout << "1. Add\n";
    cout << "2. Sub\n";
    cout << "3. Mul\n";
    cout << "4. Test 2D array sum (delegate)\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

int main() {
    Arithmetic a;
    a.Overflow = OnOverflow;

    int choice;

    // Delegate demonstration
    function<int(const vector<vector<int>>&)> sumDelegate;

    // Assign lambda
    sumDelegate = [](const vector<vector<int>>& arr) {
        int s = 0;
        for (auto& row : arr)
            for (int x : row) s += x;
        return s;
    };

    while (true) {
        menu();
        cin >> choice;

        if (choice == 0) break;

        if (choice == 4) {
            vector<vector<int>> arr = {{1, 2}, {3, 4}};
            cout << "Sum by lambda: " << sumDelegate(arr) << "\n";

            // Anonymous function
            sumDelegate = function<int(const vector<vector<int>>&)>{
                [](const vector<vector<int>>& a) {
                    int s = 0;
                    for (auto& row : a)
                        for (int x : row) s += x;
                    return s;
                }
            };
            cout << "Sum by anonymous: " << sumDelegate(arr) << "\n\n";
            continue;
        }

        int x, y;
        cout << "Enter a and b: ";
        cin >> x >> y;

        try {
            switch (choice) {
                case 1: cout << "Result: " << a.Add(x, y) << "\n\n"; break;
                case 2: cout << "Result: " << a.Sub(x, y) << "\n\n"; break;
                case 3: cout << "Result: " << a.Mul(x, y) << "\n\n"; break;
                default: cout << "Invalid choice\n\n";
            }
        }
        catch (...) {
            cout << "Unexpected error!\n";
        }
    }

    return 0;
}
