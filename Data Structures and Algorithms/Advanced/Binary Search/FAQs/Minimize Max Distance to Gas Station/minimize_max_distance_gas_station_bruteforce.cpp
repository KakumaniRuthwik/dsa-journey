#include<iostream>
#include<vector>
using namespace std;

long double minimiseMaxDistance(vector<int>& arr, int k){

    int size = arr.size();

    vector<int> howMany(size - 1, 0);

    for(int gasStations = 1; gasStations <= k; gasStations++){
        double maxSection = -1;
        int maxInd = -1;

        for(int i = 0; i < size - 1; i++){
            double diff = arr[i + 1] - arr[i];
            double sectionLength = diff / (howMany[i] + 1);

            if(sectionLength > maxSection){
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    double maxAns = -1;

    for(int i = 0; i < size - 1; i++){
        double diff = arr[i + 1] - arr[i];
        double sectionLength = diff / (howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }

    return maxAns;
}

int main(){
    
    vector<int> arr = {1, 13, 17, 23};
    int k = 5;

    cout << "The answer is : " << minimiseMaxDistance(arr, k);

    return 0;
}