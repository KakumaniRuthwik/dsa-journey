#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int secondMostFrequentElement(vector<int>& nums){

    // Creating an unordered_map called frequecnyMap.
    unordered_map<int, int> frequencyMap;


    // Assig count values to their nums.
    for(auto num : nums){
        frequencyMap[num]++;
    }

    // Assigning variables to store maxium occuring element and frequency.
    int maximumOccurringElement = 0, maximumFrequency = 0;
    int secondMaximumOccurringElement = -1, secondMaximumFrequency = -1;


    // Finding maximum frequency element.
    for(auto [num, count] : frequencyMap){
        if(count > maximumFrequency){
            maximumOccurringElement = num;
            maximumFrequency = count;
        }
    }

    for(auto [num, count] : frequencyMap){
        if(count < maximumFrequency && count > secondMaximumFrequency && num != maximumOccurringElement){
            secondMaximumOccurringElement = num;
            secondMaximumFrequency = count;
        }else if(count == secondMaximumFrequency && num < secondMaximumOccurringElement){
            secondMaximumOccurringElement = num;
        }
    }

    return (secondMaximumOccurringElement == -1) ? -1 : secondMaximumOccurringElement;
}

int main() {
    vector<int> nums;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    int result = secondMostFrequentElement(nums);
    if (result == -1) {
        cout << "No second most frequent element exists.\n";
    } else {
        cout << "Second most frequent element is: " << result << "\n";
    }

    return 0;
}