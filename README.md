# Maximum subarray frequency deviation
## Description
Find maximum freqeuncy deviation of every possible substring.
len(substring) >= 1

## Input
- only lower case alphabets
- give txt file
- max len of each line <= 10^4

## Example
- "aaabb" => a substring, 'aaab', has deviation 3. (3 'a's, 1 'b')
- "abcccbaa" => a substring, 'bccc', has deviation 2. (3 'c's, 1 'b')
- "aaa" => maximum answer is 0. e.g., "aa" has 2 'a's for maximum frequency, 2 'a's for minimum frequency. answer = 2 - 2 = 0

## How to solve
1. replaced string with numbers(1, -1) for every pair of c1, c2 ranging from 'a' to 'z'<br>
2. used `Kadane's algorithm`, one of dynamic programming techniques<br>
3. return maximum value

```cpp
for (c1 = 'a' to 'z')
    for (c2 = 'a' to 'z')
        num_arr = string2num(s);    // replace s with 1(c1) and -1(c2)
        res = Kadane(num_arr);      // apply kadane's algorithm
        if (max < res) max = res;   // get maximum value
return max;
```

## References
- https://en.wikipedia.org/wiki/Maximum_subarray_problem
- https://cs.stackexchange.com/a/151153

## Compiler
C++98
