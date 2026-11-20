class Solution {

    int solution(vector<int>& prices, int index, bool brought, vector<vector<int>> &dp){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][brought] != -1){
            return dp[index][brought];
        }
        int profit = 0;

        if(brought){
            dp[index][brought] = profit = max(solution(prices, index + 1, true, dp), prices[index] + solution(prices, index + 1, false, dp));
        }
        else{
            dp[index][brought] = profit = max(solution(prices, index + 1, false, dp), -prices[index] + solution(prices, index + 1, true, dp));
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solution(prices, 0, false, dp);
    }
};