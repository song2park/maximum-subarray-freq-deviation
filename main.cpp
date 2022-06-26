#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <limits>

using namespace std;

void printDS(vector<int> a, char c1, char c2) {
    cout << c1 << " " << c2 << " : ";
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// string array -> decimal array
void string2num(string in, vector<int>* out, int c1, int c2) {
    for (auto c : in) {
        if (c == c1) {
            out->push_back(1);
        }
        if (c == c2) {
            out->push_back(-1);
        }
    }
}

// kadane's algorithm
int Kadane(vector<int> input) {
    if (input.size() == 1) return 0;

    bool negativeIncludedInInput = false;   // does input include negative element in it.
    bool negativeIncludedInAns = false;     // does answer include negative value.

    int global_max = INT_MIN;
    int local_max = 0;

    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] < 0) negativeIncludedInInput = true;

        int sub_sum = local_max + input[i];
        
        if (input[i] < 0) negativeIncludedInAns = true;
        else if (sub_sum < input[i]) negativeIncludedInAns = false;

        local_max = max(sub_sum, input[i]);
        if (negativeIncludedInAns) {
            global_max = max(global_max, local_max);
        }
    }

    if (negativeIncludedInAns) return global_max;
    else if (negativeIncludedInInput) return local_max - 1;
    return 0;
}

int getMaxFreqDeviation(string s) {
    int mfd = 0;

    for (int c1 = 'a'; c1 <= 'z'; c1++) {
        for (int c2 = 'a'; c2 <= 'z'; c2++) {
            if (c1 == c2) continue;

            vector<int> dec_arr;
            string2num(s, &dec_arr, c1, c2);

            //printDS(v_s2d, c1, c2);

            int res = Kadane(dec_arr);
            if (res > mfd) {
                mfd = res;
            }
        }
    }
    return mfd;
}

int main() {
    ifstream ifs("input.txt");

    if (ifs.fail()) {
        cout << "Failed to read inupt.txt" << endl;
        return -1;
    }

    int lines;
    ifs >> lines;

    while (lines > 0) {
        lines--;
        string s;
        ifs >> s;
        cout << getMaxFreqDeviation(s) << endl;
    }

    return 0;
}
