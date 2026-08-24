class Solution {

    static bool comp(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans;
        unordered_map<int, int> mp;
        vector<pair<int, int>> freq;

        for(int num : nums){
            mp[num]++;
        }

        for(auto it : mp){
            freq.push_back({it.first, it.second});
        }

        sort(freq.begin(), freq.end(), comp);

        for(int i = 0; i < k; i++){
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};
