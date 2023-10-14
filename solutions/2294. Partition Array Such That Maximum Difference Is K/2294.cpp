class Solution {
 public:
  int partitionArray(vector<int>& nums, int k) {
    std::ranges::sort(nums);

    int ans = 1;
    int min = nums[0];

    for (int i = 1; i < nums.size(); ++i)
      if (min + k < nums[i]) {
        ++ans;
        min = nums[i];
      }

    return ans;
  }
};
