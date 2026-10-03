#include <iostream>
#include <cmath>

using namespace std;

/*
To test a conjecture A(x):
- Replace the placeholder left hand side (remnants from the placeholder conjecture) with your left hand side
- Replace the placeholder right hand side (remnants from the placeholder conjecture) with your right hand side
- Replace the comparison sign of the placeholder conjecture with yours (options: >, <, =, >=, <=)

The placeholder conjecture (x^2 + 20 > 10|x|)is intentionally designed to fail at x=-7.236 (LHS = 72.3597; RHS = 72.36).
*/

double lhs(double input) {
    return ( ((input * input) + 20) ); // insert new left hand side - REMEMBER TO WRAP IN PARENTHESIES!!!!!!!!
}

double rhs(double input) {
    return ( 10 * abs(input) ); // insert new right hand side - REMEMBER TO WRAP IN PARENTHESIES!!!!!!!!
}

bool conjTest(double input) {
    return ( lhs(input) > rhs(input) ); // insert comparison of sides here (options: >, <, =, >=, <=)
}

int main() {
    constexpr bool verbose = false; // change to true if you want to send every attempt to output - warning: very slow! - default: false
    constexpr double precision = 0.001; // change to adjust precision of testing/steps - warning: the smaller the precision, the longer it takes - default: 0.001
    double attempt = 0;
    double attemptMax = 0;
    double attemptMin = 0;
    double prev_attemptMax = 0;
    double prev_attemptMin = 0;
    int scale = 0;
    double mult = 0;
    double boundNeg = 0;
    double boundPos = 0;
    bool stage1 = true;
    bool skipToEnd = false;

    if (stage1 == true && skipToEnd == false) {
        attempt = -1;
        attemptMin = attempt;
        attemptMax = abs(attemptMin);
        prev_attemptMax = attemptMax;
        prev_attemptMin = attemptMin;
        for (; attempt < attemptMax; attempt += precision) {
            if (conjTest(attempt) == false) {
                cout << "stage 1: counterexample found at x=" << attempt << " (LHS = " << lhs(attempt) << "; RHS = " << rhs(attempt) << ")" << endl;
                skipToEnd = true;
                break;
            }
            else if (verbose == true){
                cout << "stage 1: conjecture true at x=" << attempt << endl;
            }
            else {
                // do nothing
            }
        }
        if (skipToEnd == false) {
            cout << "=============================================" << endl;
            cout << "stage 1: ";
            cout << "no counterexample found for x = -1 -> x = 1 (step: " << precision << ")" << endl;
            cout << "=============================================" << endl;
            stage1 = false;
        }
        if (skipToEnd == true) {
            cout << "=============================================" << endl;
        }
    }

    if (stage1 == false && skipToEnd == false) {
        while (conjTest(attempt) == true && skipToEnd == false) {
            scale++;
            mult = pow(10,scale);
            boundNeg = prev_attemptMin - precision;
            boundPos = prev_attemptMax + precision;
            attempt = prev_attemptMin * mult;
            prev_attemptMin = attempt;
            prev_attemptMax = abs(attempt);
            attemptMax = prev_attemptMax;
            if (skipToEnd == false){
                for (;attempt < boundNeg; attempt += precision) {
                    if (conjTest(attempt) == false) {
                        cout << "stage " << (scale + 1) << ": counterexample found at x=" << attempt << " (LHS = " << lhs(attempt) << "; RHS = " << rhs(attempt) << ")" << endl;
                        skipToEnd = true;
                        break;
                    }
                    else if (verbose == true){
                        cout << "stage " << (scale + 1) << ": conjecture true at x=" << attempt << endl;
                    }
                    else {
                        // do nothing
                    }
                }
                if (skipToEnd == false) {
                    cout << "stage " << (scale + 1)  << ":" << endl;
                    cout << "no counterexample found for x = " << prev_attemptMin << " -> x = " << boundNeg << " (step: " << precision  << ")" << endl;
                    attempt = boundPos;
                }
                if (skipToEnd == false) {
                    for (;attempt < attemptMax; attempt += precision) {
                        if (conjTest(attempt) == false) {
                            cout << "stage " << (scale + 1) << ": counterexample found at x=" << attempt << " (LHS = " << lhs(attempt) << "; RHS = " << rhs(attempt) << ")" << endl;
                            skipToEnd = true;
                            break;
                        }
                        else if (verbose == true){
                            cout << "stage " << (scale + 1) << ": conjecture true at x=" << attempt << endl;
                        }
                        else {
                            // do nothing
                        }
                    }
                    if (skipToEnd == false) {
                    cout << "no counterexample found for x = " << boundPos << " -> x = " << attemptMax << " (step: " << precision  << ")" << endl;
                    cout << "=============================================" << endl;
                    }
                }
            }
            if (skipToEnd == true) {
                cout << "=============================================" << endl;
            }
        }
    }
    return 0;
}
