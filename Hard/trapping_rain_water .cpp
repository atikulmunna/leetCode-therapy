#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int totalWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    totalWater += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    totalWater += rightMax - height[right];
                }
                right--;
            }
        }

        return totalWater;
    }
};

/*
 * Approach: Two Pointers (Space Optimized)
 * * Logic:
 * 1. The amount of water stored at any specific index is determined by the
 * shorter of the two maximum heights surrounding it (Min(MaxLeft, MaxRight)).
 * 2. We use two pointers, 'left' starting at the beginning and 'right' at the end.
 * 3. We maintain two variables, 'leftMax' and 'rightMax', to track the highest
 * bars seen so far from the respective directions.
 * 4. In every iteration of the while loop:
 * - We compare height[left] and height[right].
 * - If the left bar is shorter (or equal), we focus on the left side. We know
 * that the water level here is bottlenecked by 'leftMax' because there is a
 * bar on the right that is at least this tall (or taller).
 * - If the current left bar is taller than 'leftMax', it cannot hold water
 * (it IS the new wall). We update 'leftMax'.
 * - Otherwise, it holds water equal to 'leftMax - current_height'.
 * - We increment the 'left' pointer.
 * - If the right bar is shorter, we apply the symmetric logic to the right side
 * and decrement the 'right' pointer.
 * 5. This process continues until the pointers meet, accumulating the total water.
 * * Time Complexity: O(n)
 * We traverse the array exactly once (left and right meet in the middle).
 * * Space Complexity: O(1)
 * We only use a few integer variables for state tracking.
 */