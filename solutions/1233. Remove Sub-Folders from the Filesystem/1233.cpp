class Solution {
 public:
  vector<string> removeSubfolders(vector<string>& folder) {
    vector<string> ans;
    string prev;

    std::ranges::sort(folder);

    for (const string& f : folder) {
      if (!prev.empty() && f.find(prev) == 0 && f[prev.length()] == '/')
        continue;
      ans.push_back(f);
      prev = f;
    }

    return ans;
  }
};
