class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    std::ranges::sort(g);
    std::ranges::sort(s);

    int i = 0;
    for (int j = 0; j < s.size() && i < g.size(); ++j)
      if (g[i] <= s[j])
        ++i;

    return i;
  }
};
