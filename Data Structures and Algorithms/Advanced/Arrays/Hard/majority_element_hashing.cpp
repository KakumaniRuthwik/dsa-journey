#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElementHashing(vector<int>& nums) {
    unordered_map<int, int> frequency;
    int size = nums.size();

    for (int num : nums) {
        frequency[num]++;
        if (frequency[num] > size / 2) {
            return num;
        }
    }
    return -1; // Should never happen as per problem guarantee
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element (Hashing): " 
         << majorityElementHashing(nums) << endl;
    return 0;
}