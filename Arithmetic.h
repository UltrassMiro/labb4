#pragma once
#include <iostream>
#include <functional>
#include <string>
#include <cstdint>

using namespace std;

// EventArgs
struct OverflowEventArgs {
    int a, b;
    long long result;
    string operation;
};

// Interface
class IArithmetic {
public:
    virtual int Add(int a, int b) = 0;
    virtual int Sub(int a, int b) = 0;
    virtual int Mul(int a, int b) = 0;
    virtual ~IArithmetic() {}
};

class Arithmetic : public IArithmetic {
public:
    function<void(const Arithmetic*, const OverflowEventArgs&)> Overflow;

    int Add(int a, int b) override;
    int Sub(int a, int b) override;
    int Mul(int a, int b) override;

private:
    bool checkOverflow(long long);
    void raiseOverflow(int a, int b, long long result, const string& operation);
};
