#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {

        // update minimum buying price
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // calculate profit
        int profit = prices[i] - minPrice;

        // update maximum profit
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};

    cout << "Maximum Profit = " << maxProfit(prices);

    return 0;
}