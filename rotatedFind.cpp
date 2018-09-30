#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1, mid, mid1, mid2;
    if(nums.size() == 0)
        return -1;
    while(l <= r){
        mid = (l+r)/2;
        mid1 = (mid+nums.size()-1) % nums.size();
        mid2 = (mid+1) % nums.size();
        
        if(nums[mid1] >= nums[mid] && nums[mid] <= nums[mid2])
            break;
        else if(nums[mid] > nums[r])
            l = mid2;
        else 
            r = mid1;
    }
    
    if(nums[mid] == target)
        return mid;
    else if(nums[mid] < target && nums[nums.size()-1] >= target){
        l = mid+1, r = nums.size()-1;
        while(l <= r && l <= nums.size()-1){
            int m = (l+r)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
                l = m+1;
            else
                r = m-1;
        }
    }
    else{
        l = 0, r = mid-1;
        while(l <= r){
            int m = (l+r)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
                l = m+1;
            else
                r = m-1;
        }
    }
    return -1;
}

int main() {
	int t,n,x,ele;
    cin >> t;
    while(--t >= 0){
        cin >> n;
        vector<int> v;
        while(--n >= 0){
            cin >> x;
            v.push_back(x);
        }
        cin >> ele;
        cout << search(v, ele) << endl;
    }
	return 0;
}