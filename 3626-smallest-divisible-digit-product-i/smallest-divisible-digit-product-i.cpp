class Solution {
public:
    int product(int a){
        int prod = 1;
          while(a>0){
            int dig = a%10;
            prod*=dig;
            a/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        if(product(n)%t == 0) return n;
        
        return smallestNumber(n+1, t);
    }
};