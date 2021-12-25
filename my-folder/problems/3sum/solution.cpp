class Solution {
public:    
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        unordered_map<int, vector<int>> myDict;
        map<string, bool> keycheck;
        // for(auto k : nums) cout << k << endl;
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > 0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<nums.size(); j++){
                int tmp = nums[i] + nums[j];
                if(tmp > 0) break;
                if(myDict.find(tmp) == myDict.end()){
                    myDict[tmp] = {i, j};
                } else{
                    myDict[tmp].push_back(i);
                    myDict[tmp].push_back(j);
                }
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                if(i<nums.size() - 1 && nums[i+1] == 0) continue;
            } else if (i>0 && nums[i] == nums[i-1]) continue;

            if(myDict.find(-nums[i]) != myDict.end()){
                vector<int> entry = myDict[-nums[i]];
                int pairCount = entry.size() / 2;
                for(int t=0; t<pairCount; t++){
                    int a = entry[2*t];
                    int b = entry[2*t + 1];
                    if(a != i && b != i){
                        vector<int> candidate = {nums[i], nums[a], nums[b]};
                        sort(candidate.begin(), candidate.end());
                        string keystr = to_string(candidate[0]) + to_string(candidate[1]) + to_string(candidate[2]);
                        if(keycheck.find(keystr) == keycheck.end()){
                            res.push_back(candidate);
                            keycheck[keystr] = true;
                        }
                    }
                    
                }
            }
        }
        return res;
    }
};