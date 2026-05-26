#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Step 1: Build the frequency map
        std::unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Step 2: Use a min-heap to keep the top k elements
        auto compare = [](std::pair<int, int>& a, std::pair<int, int>& b) {
            return a.second > b.second; // Min-heap based on frequency
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> minHeap(compare);

        for (const auto& entry : frequencyMap) {
            minHeap.push(entry);
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the element with the lowest frequency
            }
        }

        // Step 3: Extract the top k elements from the heap
        std::vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        return result;
    }
};
