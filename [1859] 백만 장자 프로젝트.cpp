#include <iostream>
using namespace std;

int salePrices[1000001];

long long getMaxProfit(int days)
{
    long long profit = 0;
    int maxSalePrice = 0;
	maxSalePrice = salePrices[days-1];
    
    for(int i = days-2; i >= 0; i--) {
    	if(salePrices[i] > maxSalePrice) {
        	maxSalePrice = salePrices[i];
        }
        else {
        	profit += (maxSalePrice - salePrices[i]);
        }
    }
    
    return profit;
}
int main(void)
{
	int t, n;
    cin >> t;
    for(int i = 1; i <= t; i++) {
    	cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> salePrices[j];
        }
        cout << "#" << i << " " << getMaxProfit(n) << '\n';
    }
    
    return 0;
}