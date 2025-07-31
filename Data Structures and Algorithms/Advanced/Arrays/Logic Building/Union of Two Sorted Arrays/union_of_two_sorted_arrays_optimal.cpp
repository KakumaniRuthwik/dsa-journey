#include <iostream>
#include <vector>

using namespace std;

vector<int> unionArrayOptimal(const vector<int>& nums1, const vector<int>& nums2) {
    vector<int> result;
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();

    while (i < n && j < m) {
        if (nums1[i] <= nums2[j]) {
            if (result.empty() || result.back() != nums1[i]) result.push_back(nums1[i]);
            i++;
        } else {
            if (result.empty() || result.back() != nums2[j]) result.push_back(nums2[j]);
            j++;
        }
    }

    while (i < n) {
        if (result.empty() || result.back() != nums1[i]) result.push_back(nums1[i]);
        i++;
    }

    while (j < m) {
        if (result.empty() || result.back() != nums2[j]) result.push_back(nums2[j]);
        j++;
    }

    return result;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 3, 4};
    vector<int> nums2 = {2, 4, 4, 5, 6};

    vector<int> result = unionArrayOptimal(nums1, nums2);

    cout << "Union: ";
    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}