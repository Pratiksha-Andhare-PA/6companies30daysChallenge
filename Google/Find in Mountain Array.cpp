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
        int st = 0, en = n-1;
        int peak;

        while(st <= en){
            int mid = st + (en - st)/2;
            if(mid == 0) mid = mid + 1;
            else if(mid == n-1) mid = mid - 1;

            int val = mountainArr.get(mid);
            int left = mountainArr.get(mid - 1);
            int right = mountainArr.get(mid + 1);

            if(val > left && val > right){
                peak = mid;
                break;
            }
            else if(val > left && val < right) st = mid + 1;
            else en = mid - 1;
        }
        if(target == mountainArr.get(peak)) return peak;

        st = 0, en = peak - 1;
        while(st <= en){
            int mid = st + (en - st)/2;
            int val = mountainArr.get(mid);

            if(val == target) return mid;
            else if(val > target) en = mid - 1;
            else st = mid + 1;
        }

        st = peak + 1, en = n-1;
        while(st <= en){
            int mid = st + (en - st)/2;
            int val = mountainArr.get(mid);
            if(val == target) return mid;
            else if(val > target) st = mid + 1;
            else en = mid - 1;
        }
        return -1;
    }
};
