#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    int left = m - 1; 
    int right = 0;
    
    // Swap larger elements from nums1 with smaller elements from nums2
    while (left >= 0 && right < n) {
        if (nums1[left] > nums2[right]) {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        } else {
            break;
        }
    }

    // Sort both parts
    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.end());

    // Merge back nums2 into nums1
    for (int i = m; i < m + n; i++) {
        nums1[i] = nums2[i - m];
    }
}

int main() {
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    for (int num : nums1) {
        cout << num << " ";
    }
    return 0;
}