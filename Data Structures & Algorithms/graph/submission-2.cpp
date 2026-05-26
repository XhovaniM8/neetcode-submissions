class Graph {
private:
  std::unordered_map<int, std::unordered_set<int>> adj;

  bool dfs(int current, int target, std::unordered_set<int> &visited) {
    if (current == target)
      return true;

    visited.insert(current);

    for (int neighbor : adj[current]) {
      if (visited.find(neighbor) == visited.end()) {
        if (dfs(neighbor, target, visited))
          return true;
      }
    }
    return false;
  }

public:
  Graph() {}

  void addEdge(int src, int dst) {
    if (adj.find(src) == adj.end())
      adj[src] = {};
    if (adj.find(dst) == adj.end())
      adj[dst] = {};

    adj[src].insert(dst);
  }

  bool removeEdge(int src, int dst) {
    if (adj.find(src) != adj.end() && adj[src].count(dst)) {
      adj[src].erase(dst);
      return true;
    }
    return false;
  }

  bool hasPath(int src, int dst) {
    std::unordered_set<int> visited;
    return dfs(src, dst, visited);
  }
};