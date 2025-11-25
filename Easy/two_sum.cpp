#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }

            numMap[nums[i]] = i;
        }

        return {};
    }
};


/*
 * Approach: One-Pass Hash Table (Complement Strategy)
 * * Logic:
 * We iterate through the array once. For every number 'nums[i]', we calculate 
 * the 'complement' needed to reach the target (complement = target - nums[i]).
 * * We use an unordered_map (hash map) to store numbers we have already seen 
 * along with their indices. This allows us to look up if the 'complement' 
 * exists in O(1) time.
 * * 1. If the complement exists in the map, we have found the pair. We return 
 * the current index and the index stored in the map.
 * 2. If the complement does not exist, we store the current number and 
 * its index in the map for future lookups.
 * * Time Complexity: O(n) - We traverse the list containing n elements only once.
 * Space Complexity: O(n) - The extra space required depends on the number of items stored in the hash map.
 */