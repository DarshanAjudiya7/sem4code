#include <iostream>
#include <vector>
using namespace std;

int maxProductSubarray(vector<int> nums) {
    int maxP = nums[0], minP = nums[0], result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) swap(maxP, minP);
        maxP = max(nums[i], maxP * nums[i]);
        minP = min(nums[i], minP * nums[i]);
        result = max(result, maxP);
    }
    return result;
}