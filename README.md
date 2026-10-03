# conjecture-tester
A simple C++ program that brute-forces mathematical conjectures over increasingly large ranges.
Tries not to retest what has already been tested.

## Setup (Linux/macOS)
1. Clone this repository with `git clone https://github.com/cheezedbread/conjecture-tester`
2. Change your directory to `conjecture-tester` with `cd conjecture-tester`
3. Read the comments in brute-force-math.cpp, and edit the source code as instructed.
4. Compile with `g++ -std=c++17 -Wall -Wextra brute-force-math.cpp -o brute-force-math`
5. Run with ./brute-force-math

## Warning:
This program is intentionally stupid.
Stage 8 alone checks about **10 nonillion numbers (2 × 10^31)** with **zero multithreading, SIMD/AVX or compiler optimization** with default values.
It still uses `namespace std` for fuck's sake.
God forbid anyone seriously uses this to actually test conjectures.
