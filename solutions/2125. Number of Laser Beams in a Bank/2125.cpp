class Solution {
 public:
  int numberOfBeams(vector<string>& bank) {
    int ans = 0;
    int prevOnes = 0;

    for (const string& row : bank) {
      const int ones = count(row.begin(), row.end(), '1');
      if (ones > 0) {
        ans += prevOnes * ones;
        prevOnes = ones;
      }
    }

    return ans;
  }
};
