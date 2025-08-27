#include <bits/stdc++.h>
using namespace std;

pair<int,int> find_missing_repeating_math(vector<int>& nums) {
    long long n = nums.size();
    long long sum_n = n*(n+1)/2;
    long long sum_sq_n = n*(n+1)*(2*n+1)/6;

    long long sum_arr=0, sum_sq_arr=0;
    for(int num: nums){
        sum_arr += num;
        sum_sq_arr += (long long)num*num;
    }

    long long val1 = sum_arr - sum_n;          // x - y
    long long val2 = (sum_sq_arr - sum_sq_n)/val1; // x + y

    long long x = (val1 + val2)/2; // repeating
    long long y = x - val1;        // missing

    return {(int)x, (int)y};
}

int main() {
    vector<int> nums = {3,5,4,1,1};
    pair<int,int> result = find_missing_repeating_math(nums);
    cout << "Repeating: " << result.first << ", Missing: " << result.second << endl;
    return 0;
}