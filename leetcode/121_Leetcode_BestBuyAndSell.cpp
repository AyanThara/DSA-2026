/*problem Statement

You are given an array prices where prices[i] is the price of a stock on the i-th day.

You want to maximize your profit by choosing:

one day to buy

a later day to sell

Return the maximum profit you can achieve.
If no profit is possible, return 0.

💡 Intuition

To make maximum profit:

Buy at the lowest price seen so far

Sell later at a higher price

While scanning the array once, we track:

bestbuy → minimum price so far

maxprofit → best profit achievable

For each day:

profit = current_price − bestbuy

Update the answer if this profit is larger.

🛠 Approach

Initialize bestbuy with first price.

Initialize maxprofit = 0.

Traverse from index 1 to n-1:

If current price is higher than bestbuy, compute profit.

Update maxprofit if needed.

Update bestbuy as minimum of current price and previous bestbuy.

Return maxprofit.

This guarantees buying happens before selling.

🔎 Dry Run
Input
prices = [7,1,5,3,6,4]
Day	Price	bestbuy	profit today	maxprofit
0	7	7	-	0
1	1	1	0	0
2	5	1	4	4
3	3	1	2	4
4	6	1	5	5
5	4	1	3	5

✅ Final Answer = 5

(Buy at 1, sell at 6)

⏱ Complexity

Time complexity: O(n) (single traversal)

Space complexity: O(1) (constant variables only)*/
lass Solution { 
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy=prices[0];//intilize best buy as 0 th index i.e 7 in this case 
        int maxprofit=0;//start maxprofit with 0
        int n=prices.size();
        for(int i=1;i<n;i++){ //start loop from 1 because 0 th index is best buy and there will be no negative index in array so we are considering 0 th index as best buy in staring 
        if(prices[i]>bestbuy){//check if the index value is greater than best buy if yes so we are calculating the  maximum of  maxprofit and price[i]-best buy 
            maxprofit=max(maxprofit,prices[i]-bestbuy);
        }
            bestbuy=min(bestbuy,prices[i]);//check among best buy and price of i which is minimum and make it best buy i.e 7,1 min is 1 so we are considering 1 as best buy 
        }
        return maxprofit;//return the max profit 
    }
};

//o(n)complexity 

