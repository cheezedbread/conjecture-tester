# conjecture-tester
A simple C++ program that brute-forces mathematical conjectures over increasingly large ranges.
Tries not to retest what has already been tested.

## Setup (Linux/macOS)
1. Clone this repository with `git clone https://github.com/cheezedbread/conjecture-tester`
2. Change your directory to `conjecture-tester` with `cd conjecture-tester`
3. Read the comments in brute-force-math.cpp, and edit the source code as instructed.
4. Compile with `g++ -std=c++17 -Wall -Wextra brute-force-math.cpp -o brute-force-math`
5. Run with `./brute-force-math`

## Warning:
This program uses a deliberately straightforward brute-force approach and is not designed for computational efficiency.<br>
With default settings, stage 8 alone checks an estimated **10 nonillion numbers (2 × 10^31)** with **zero multithreading, SIMD/AVX and little compiler optimization**<br>
<br>
**Do not assume that higher stages will finish in a reasonable amount of time.**

## To-do:
- [x] Make the core functions exist (the actual testing and range-adjustment)
- [ ] Add option to zoom in on critical areas of conjecture, adjusting precision if needed.
- [ ] Math lexer/parser (Shunting-yard -> RPN)
- [ ] Actual UI
