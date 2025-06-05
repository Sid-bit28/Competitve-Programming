/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 1;
        int high = n - 2;
        int ans = 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int val = mountainArr.get(mid);
            int val_left = mountainArr.get(mid - 1);
            int val_right = mountainArr.get(mid + 1);
            if (val > val_left && val > val_right) {
                ans = mid;
                break;
            } else if (val > val_left && val < val_right) {
                low = mid + 1;
            } else high = mid - 1;
        }
        low = 0;
        high = ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val < target) {
                low = mid + 1;
            } else high = mid - 1;
        }
        low = ans;
        high = n - 1;
        // cout<<low<<" "<<high<<endl;
        while (low <= high) {
            int mid = (low + high) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val < target) {
                high = mid - 1;
            } else low = mid + 1;
        }
        return -1;
    }
};