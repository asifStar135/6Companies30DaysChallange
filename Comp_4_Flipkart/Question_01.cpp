//  Question #1 of challenge #4(Flipkart)
//  Name - Partition to K Equal Sum Subsets
//  LeetCode #698

class Solution {
public:
    vector<bool> vis;
    bool solve(vector<int>& nums, int i, int n, int k, int curr_sum, int target){
        if(k == 1)
            return true;
        if(i == n)
            return false;
        
        if(curr_sum == target)
            return solve(nums, 0, n, k - 1, 0, target);
        
        for(int j = i; j < n; j++){            
            if(vis[j] == false && curr_sum + nums[j] <= target){
                vis[j] = true;
                curr_sum += nums[j];

                if(solve(nums, j + 1, n, k, curr_sum, target))
                    return true;                
                vis[j] = false;
                
                curr_sum -= nums[j];
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
    
        for(auto x : nums)
            sum += x;
        
        if(sum % k)
            return false;
        sum /= k;
        vis.assign(n, false);
        return solve(nums, 0, n, k, 0, sum);
    }
};