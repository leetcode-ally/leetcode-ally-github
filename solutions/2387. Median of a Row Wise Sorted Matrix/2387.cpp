class Solution {
 public:
  int matrixMedian(vector<vector<int>>& grid) {
    const int noGreaterThanMedianCount = grid.size() * grid[0].size() / 2 + 1;
    int l = 1;
    int r = 1e6;

    while (l < r) {
      const int m = (l + r) / 2;
      if (numsNoGreaterThan(grid, m) >= noGreaterThanMedianCount)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int numsNoGreaterThan(const vector<vector<int>>& grid, int m) {
    int count = 0;
    for (const vector<int>& row : grid)
      count += upper_bound(row.begin(), row.end(), m) - row.begin();
    return count;
  }
};
