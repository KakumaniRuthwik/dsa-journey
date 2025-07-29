#include <iostream>
#include <vector>
#include <set>
using namespace std;

int remove_duplicates(vector<int>& nums) {
    set<int> unique_elements;

    for (int val : nums) {
        unique_elements.insert(val);
    }

    int index = 0;
    for (int val : unique_elements) {
        nums[index++] = val;
    }

    return unique_elements.size();
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};

    int new_length = remove_duplicates(nums);

    cout << "Length after removing duplicates: " << new_length << endl;
    cout << "Modified array: ";
    for (int i = 0; i < new_length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}