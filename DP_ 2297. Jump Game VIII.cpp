class Solution {
    public:
        long long minCost(vector<int>& costs, vector<int>& nums) {
            int n = nums.size();
            stack<int> st;
            vector<int> nge(n, -1);
            vector<int> nle(n, -1);
            
            for(int i = 0; i < n; i++) {
                while(!st.empty() && nums[st.top()] <= nums[i]) {
                    int x = st.top();
                    st.pop();
                    nge[x] = i;
                }
                st.push(i);
            }
            
            while(!st.empty()) st.pop();
            
            for(int i = 0; i < n; i++) {
                while(!st.empty() && nums[st.top()] > nums[i]) {
                    int x = st.top();
                    st.pop();
                    nle[x] = i;
                }
                st.push(i);
            }
            
            vector<long long> dp(n, LLONG_MAX);
            dp[0] = 0;
            
            for(int i = 0; i < n; i++) {
                if(nge[i] != -1) {
                    dp[nge[i]] = min(costs[nge[i]] + dp[i], dp[nge[i]]);
                }
                if(nle[i] != -1) {
                    dp[nle[i]] = min(costs[nle[i]] + dp[i], dp[nle[i]]);
                }
            }
            
            return dp[n-1];
        }
};

int main() {
    Solution obj;
    int n;
    cin >> n;
    vector<int> costs(n), nums(n);
    for(int i = 0; i < n; i++) {
        cin >> costs[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    long long ans = obj.minCost(costs, nums);
    cout << ans << endl;
    
}
