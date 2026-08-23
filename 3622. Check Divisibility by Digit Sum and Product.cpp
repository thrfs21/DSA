class Solution {
public:
    bool checkDivisibility(int n) {
        int t = n;
        int sum = 0;
        int prod = 1;
        
        while(t > 0){
            sum += t % 10;
            prod *= t % 10;
            t /= 10;
        }
        sum += prod;
        
        return (n % sum == 0);
    }
};
