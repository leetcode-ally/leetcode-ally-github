class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses);
    queue<int> q;

    // Build graph.
    for (const vector<int>& prerequisite : prerequisites) {
      const int u = prerequisite[1];
      const int v = prerequisite[0];
      graph[u].push_back(v);
      ++inDegree[v];
    }

    // Topology
    for (int i = 0; i < numCourses; ++i)
      if (inDegree[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      ans.push_back(u);
      for (const int v : graph[u])
        if (--inDegree[v] == 0)
          q.push(v);
    }

    return ans.size() == numCourses ? ans : vector<int>();
  }
};
