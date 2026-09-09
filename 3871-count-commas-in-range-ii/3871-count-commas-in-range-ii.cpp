class Solution {
public:
    long long countCommas(long long n) {
       long long cur = 1000;
       long long res = 0;
       while(cur <= n){
        res+= n -cur + 1;
        cur *=1000;
       } 
       return res;
    }
};