#include "FindPeakElement.hpp"

int FindPeakElement::findPeakElement(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (nums[m - 1] > nums[m])
            r = m;
        else
            l = m;
    }

    return nums[l] < nums[r] ? r : l;
}
