#include "Arithmetic.h"
#include <cstdint>

bool Arithmetic::checkOverflow(long long val) {
    return val > INT32_MAX || val < INT32_MIN;
}

void Arithmetic::raiseOverflow(int a, int b, long long res, const string& op) {
    if (Overflow) {
        OverflowEventArgs args{ a, b, res, op };
        Overflow(this, args);
    }
}

int Arithmetic::Add(int a, int b) {
    long long r = (long long)a + b;
    if (checkOverflow(r)) raiseOverflow(a, b, r, "Add");
    return (int)r;
}

int Arithmetic::Sub(int a, int b) {
    long long r = (long long)a - b;
    if (checkOverflow(r)) raiseOverflow(a, b, r, "Sub");
    return (int)r;
}

int Arithmetic::Mul(int a, int b) {
    long long r = (long long)a * b;
    if (checkOverflow(r)) raiseOverflow(a, b, r, "Mul");
    return (int)r;
}
