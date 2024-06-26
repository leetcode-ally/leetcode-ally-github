class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    std::ranges::sort(houses);
    std::ranges::sort(heaters);

    int ans = 0;
    int i = 0;  // Point to the heater that currently used

    for (const int house : houses) {
      while (i + 1 < heaters.size() &&
             house - heaters[i] > heaters[i + 1] - house)
        ++i;  // Next heater is better
      ans = max(ans, abs(heaters[i] - house));
    }

    return ans;
  }
};
