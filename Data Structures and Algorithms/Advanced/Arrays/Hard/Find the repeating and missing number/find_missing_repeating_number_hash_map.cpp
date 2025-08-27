#include <bits/stdc++.h>
using namespace std;

pair<int,int> find_missing_repeating_hashmap(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> freq;
    int missing=-1, repeating=-1;

    for(int num: nums){
        freq[num]++;
        if(freq[num]==2){
            repeating=num;
        }
    }

    for(int i=1;i<=n;i++){
        if(freq[i]==0){
            missing=i; 
            break; 
        }
    }

    return {repeating, missing};
}

int main() {
    vector<int> nums = {3,5,4,1,1};
    pair<int,int> result = find_missing_repeating_hashmap(nums);
    cout << "Repeating: " << result.first << ", Missing: " << result.second << endl;
    return 0;
}