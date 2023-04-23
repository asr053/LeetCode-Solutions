#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each element using a hash table
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Create buckets of elements based on their frequency
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (const auto& kv : freq) {
            buckets[kv.second].push_back(kv.first);
        }
        
        // Step 3: Traverse the buckets in reverse order to get the top k frequent elements
        std::vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return result;
    }
};
