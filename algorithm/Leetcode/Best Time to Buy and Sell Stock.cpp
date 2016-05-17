
//Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       if(n <= 1)
            return 0;
       vector<int> buy(n,0);
       vector<int> sell(n,0);
       buy[0]= prices[0];
       for(int i=1; i<n; i++)
       {
           if(prices[i] < buy[i-1])
               buy[i] = prices[i];
           else  buy[i] = buy[i-1];
       }
       sell[n-1]= prices[n-1];
       for(int j=n-2; j>=0; j--)
       {
           if(prices[j] >sell[j+1])
                 sell[j] = prices[j];
           else sell[j] = sell[j+1];
       }
       int max = 0;
       for(int k=0; k<n; ++k)
       {
           if(max < sell[k]-buy[k])
                max = sell[k]-buy[k];
       }
       return max;
    }
};

//Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
           if(prices.size() < 1)   //prices.size is unsigned int
                return 0;
           int pro = 0;
           for(int i=0; i<prices.size()-1; i++)
           {
               if(prices[i+1] >prices[i])
                      pro += prices[i+1]-prices[i];
           }
           return pro;
    }
};

//Best Time to Buy and Sell Stock with Cooldown
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        if(n < 2) 
            return 0;
        vector<int> sells(n, 0);
        vector<int> buys(n, 0);
        int delay = 0;
        sells[0] = 0;
        buys[0] = -prices[0];
        sells[1] =  prices[1]-prices[0];
        buys[1] =  -prices[1];
        int res = max(0, prices[1]-prices[0]);
        for(int i=2; i<n; ++i)
        {
            delay = prices[i]-prices[i-1];
            buys[i] = max(sells[i-2]-prices[i], buys[i-1]-delay);
            sells[i] = max(buys[i-1]+prices[i], sells[i-1]+delay);
            if(res <sells[i])
                  res = sells[i];
        }
        return res;
    }
};

//Best Time to Buy and Sell Stock III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
             return 0;
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);
        int minb = prices[0];
        lmax[0] = 0;
        for(int i=1; i<n; i++)
        {
            minb = min(minb, prices[i]);
            lmax[i] = max(lmax[i-1], prices[i]-minb);
        }
        rmax[n-1] = 0;
        int maxs = prices[n-1];
        for(int j=n-2; j>=0; --j)
        {
            maxs = max(maxs, prices[j]);
            rmax[j] = max(rmax[j+1], maxs-prices[j]);
        }
        maxs = 0;
        for(int k=0; k<n; ++k)
        {
            maxs = max(maxs, lmax[k]+rmax[k]);
        }
        return maxs;
    }
};

//Best Time to Buy and Sell Stock IV
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<1 || k<1)
            return 0;
        if(k > n)
            return maxPro(prices);
        vector<int> global(k+1, 0);
        vector<int> local(k+1, 0);
        for(int i=0; i<n-1; i++)
        {
            int dif = prices[i+1] -prices[i];
            for(int j=k; j>=1; --j)
            {
               local[j] = max(global[j-1]+max(dif, 0), local[j]+dif);
               global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
           
    }
private:
   int maxPro(vector<int>&prices)
   {
       int max = 0;
       for(int i=1; i<prices.size(); i++)
       {
           if(prices[i]-prices[i-1] > 0)
               max += prices[i] - prices[i-1]; 
       }
       return max;
   }
    
};
