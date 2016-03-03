#include <bits/stdc++.h>

using namespace std;

// every coin can use unlimit times
int coin1(vector<int> coins, int n) {
	long dp[n + 1];
	for (int i = 0; i < n + 1; i++) {
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for (int c : coins) {
		for (int i = c; i <= n; i++) {
			cout << c << "|";
			for (int i = 0; i <= n; i++) {
				cout << dp[i] << " ";
			}
			cout << endl;
			dp[i] = min(dp[i], dp[i - c] + 1);
		}
	}

	
	for (int i = 0; i <= n; i++) {
		cout << dp[i] << " ";
	}
	return dp[n];
}

// every coin can only use once
int coin2(vector<int> coins, int n) {
	long dp[n + 1];
	for (int i = 0; i < n + 1; i++) {
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for (int c : coins) {
		for (int i = n; i >= c; i--) {
			dp[i] = min(dp[i], dp[i - c] + 1);
		}
	}
	
	for (int i = 0; i <= n; i++) {
		cout << dp[i] << " ";
	}
	return dp[n];
}

// different coins use different times
int coin3(vector<pair<int, int>> coins, int n) {
	long dp[n + 1];
	for (int i = 0; i < n + 1; i++) {
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for (auto c : coins) {
		for (int j = n; j >= c.first * c.second; j--) {
			for (int i = 0; i < c.first; i++) {
				dp[j] = min(dp[j], dp[j - c.second * c.first] + i);
			}
		}
	}
	
	for (int i = 0; i <= n; i++) {
		cout << dp[i] << " ";
	}
	return dp[n];}

int main(int argc, char *argv[]) {
	coin1({5,1,3,2}, 12);
}