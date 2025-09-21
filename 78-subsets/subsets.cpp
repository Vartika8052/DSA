class Solution {
private:
    void generate(vector<int>& nums, int index, vector<vector<int>>& ans, vector<int>& output) {
        if (index >= nums.size()) {
            ans.push_back(output); 
            return;
        }

        output.push_back(nums[index]);
        generate(nums, index + 1, ans, output);       
        output.pop_back();

        generate(nums, index + 1, ans, output);
    }        
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        generate(nums, index, ans, output);
        return ans;
    }    
};