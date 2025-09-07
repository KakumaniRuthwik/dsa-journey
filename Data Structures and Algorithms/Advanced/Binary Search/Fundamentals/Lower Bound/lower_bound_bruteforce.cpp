#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int x){
    int size = nums.size();

    for(int index = 0; index < size; index++){
        if(nums[index] >= x){
            return index;
        }
    }
    return size;
}