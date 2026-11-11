class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;

        if(costBoth < cost1 + cost2) {
            int mini = min(need1, need2);
            ans += 1LL * costBoth * mini;

            need1 -= mini;
            need2 -= mini;
            
            if(need1 > 0) {
                ans += 1LL * need1 * min(cost1, costBoth);
            }
            else if(need2 > 0) {
                ans += 1LL * need2 * min(cost2, costBoth);
            }
        }
        else {
            ans += (1LL * cost1 * need1) + (1LL * cost2 * need2);
        }

        return ans;
    }
};
