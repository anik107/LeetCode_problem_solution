class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long numOdd = 0, numEven = 1;
        int curr = 0;
        long M=1e9+7;
        for (auto& a : arr) {
          if (a % 2) curr++;
          if (curr % 2) {
            numOdd++;
          } else
            numEven++;
        }
        return numOdd * numEven % M;
      }
};
