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
