// https://hack.codingblocks.com/app/contests/2675/336/problem

#include <bits/stdc++.h>
using namespace std;

int sol(int N, int arr[]){
  int max_now = 0; // intitialise the 2 values
  int max_e = 1;
  for(int i = 0; i < N; i++){
    max_e = max(arr[i], max_e ^ arr[i]);
 
    // check whether current element/Xor is bigger
    // then previous Xor value
    max_now = max(max_e, max_now);  // update the maximum value
  }

  return max_now; // return the max value when loop is finished
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<sol(n,arr);
	return 0;
}