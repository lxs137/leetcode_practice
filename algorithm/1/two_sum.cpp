#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> minus_map;
            std::vector<int> result;
            for(int i = 0, n = nums.size(); i < n; i++) {
                auto search = minus_map.find(nums[i]);
                if(search != minus_map.end()) {
                    result.push_back(search->second);
                    result.push_back(i);
                    return result;
                }
                minus_map[target - nums[i]] = i;
            }
        }
};

int main() {
    int n, m;
    Solution test;
    vector<int> nums;
    while(cin>>n) {
        nums.clear();
        for(int i = 0 ; i < n; i++) {
            int t;
            cin>>t;
            nums.push_back(t);
        }
        cin>>m;
        vector<int> ans = test.twoSum(nums, m);
        for(int i = 0; i < ans.size(); i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
