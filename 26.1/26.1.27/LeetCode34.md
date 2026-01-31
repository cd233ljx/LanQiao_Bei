### 二分查找模板

#### 1.查起始位置
```cpp
    while(left < right){
        int mid = left + ((right - left) >> 1);
        // int mid = (left + right) / 2;

        if(check(mid))  right = mid;
        else   left = mid + 1;
        
    }
```
#### 2.查终止位置
```cpp
    while(left < right){
        int mid = left + ((right - left + 1) >> 1);
        // int mid = (left + right + 1) / 2;

        if(check(mid))  left = mid;
        else    right = mid - 1;
        
    }
```
---
### LeetCode34-在排序数组中查找元素的第一个和最后一个位置

#### 1. 手搓版
```cpp
    vector<int> searchRange(vector<int>& nums, int t){
        int n = nums.size();

        if(!n) return {-1, -1};
        //1.求起始位置
        int l = 0,r = n - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(nums[mid] >= t){
                r = mid;
            }else
            {
                l = mid + 1;
            }
        }

        //没找到
        if(nums[l] != t) return {-1, -1};
        
        int ret_left = l;

        //2.求终止位置
        l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(nums[mid] <= t){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        int ret_right = l;

        return {ret_left, ret_right};
    }
```

#### 2. STL
```cpp
    vector<int> searchRange(vector<int>& nums, int target) {

        auto left = lower_bound(nums.begin(),nums.end(),target); 
        auto right = upper_bound(nums.begin(),nums.end(),target);

        if(left==right)return {-1, -1};

        return {int(left-nums.begin()),int(right-nums.begin()-1)};
    }
```
