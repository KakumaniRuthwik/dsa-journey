#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int highestOccurringElement(vector<int>& nums){
    
    int numsSize = nums.size();

    unordered_map<int, int> frequencyMap;

    for(auto it : nums){
        frequencyMap[it]++;
    }

    int maxElement = 0;
    int frequency = 0;

    for(auto& [key, value] : frequencyMap){
        if(value > frequency){
            frequency = value;
            maxElement = key;
        }else if(frequency == value && key < maxElement){
            maxElement = key;
        }
    }

    return maxElement;
}

int main() {
    
    vector<int> nums = {1, 2, 2, 3, 3, 3, 3, 2};

    int result = highestOccurringElement(nums);
    cout << "Most frequent element: " << result << endl;

    return 0;
}