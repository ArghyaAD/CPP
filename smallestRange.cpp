/*--------------------------------------------------LEETOCDE 632 --------------------------------------------------*/
/*
    You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.
    --------------------------------------------------------------------------------------*/


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<int>ans(2);
        #define int long long int
        ans[0] = INT_MIN;
        ans[1] = INT_MAX;
        vector<pair<int,int>>arr;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(auto &it:nums[i]){
                arr.push_back({it,i});
            }
        }
        sort(arr.begin(),arr.end());
        int total = 0;
        int nn = arr.size();
        vector<int>mp(n+1,0);
        int j=0;
        for(int i=0;i<nn;i++){
            mp[arr[i].second]++;
            if(mp[arr[i].second]==1){
                total++;
            }
            if(total==n){
                while(mp[arr[j].second]>1){
                    mp[arr[j].second]--;
                    j++;
                }
                int mn = ans[0];
                int mx = ans[1];
                int cur_mn = arr[j].first;
                int cur_mx = arr[i].first;
                if(cur_mx-cur_mn<(int)mx-mn or (cur_mx-cur_mn==mx-mn && cur_mn<mn)){
                    ans[0]=arr[j].first;
                    ans[1]=arr[i].first;
                }
            }
        }
        #undef int;
        return ans;
    }
};
