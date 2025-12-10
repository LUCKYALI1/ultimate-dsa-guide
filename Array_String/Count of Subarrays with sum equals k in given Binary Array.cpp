class Solution {
public:
    int numberOfSubarrays(vector<int>& arr, int target) {
        unordered_map<long long, int> mp;
        mp[0] = 1;  // prefix sum zero occurs once

        long long prefix = 0;
        int count = 0;

        for(int num : arr) {
            prefix += num;

            long long need = prefix - target;

            if(mp.find(need) != mp.end()) {
                count += mp[need];
            }

            mp[prefix]++;  
        }

        return count;
    }
};
