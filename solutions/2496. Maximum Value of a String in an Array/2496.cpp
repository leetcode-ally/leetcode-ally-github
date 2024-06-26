class Solution {
 public:
  int maximumValue(vector<string>& strs) {
    int ans = 0;
    for (const string& s : strs)
      ans =
          max(ans, any_of(s.begin(), s.end(), [](char c) { return isalpha(c); })
                       ? static_cast<int>(s.length())
                       : stoi(s));
    return ans;
  }
};
