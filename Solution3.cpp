
// Author : Dhruv Pachauri,13117022
// B-Tech , Mechanical Engineering 4 Year

#include<bits/stdc++.h>
using namespace std;
 
void DoIt() {
	// For taking input arguments.
	int n; 
	scanf("%d",&n);
	
	//For taking inputs of all the numbers.
	vector <int> A(n);
	for (int i = 0; i < n; ++i) 
	scanf("%d", &A[i]);
	
	//Mapping each number with the position of man sitting
	set < pair<int, int> > st;
	set < pair<int,int> >::iterator it;
	st.clear();
	for (int i = 0; i < n; ++i) {
		st.insert(make_pair(A[i], i));
		it = st.find(make_pair(A[i], i));
		it++; 
		if(it != st.end()) st.erase(it);
	}
	
	int m = 0;
	bool equal[n];
	for (int i = 0; i < n; ++i)
		equal[i] = false;

	for (it = st.begin(); it != st.end(); ++it) {
		pair <int ,int> temp = *it;
		int UP[n];
		int DW[n];
		memset(UP, 0, sizeof(UP));
		memset(DW, 0, sizeof(DW));
		set <int> up;
		set <int> dw;
		for (int i = 0; i < n - 1; ++i) {
			int k = (temp.second + 1 + i) % n;
			if(A[k] > temp.first) {
				up.insert(A[k]);
				set<int>:: iterator ip = up.find(A[k]);
				ip++;
				if(ip != up.end()) up.erase(ip);
				UP[i] = up.size();
			} else {
				UP[i]=i-1>=0?UP[i-1]:0;
			}
		}
		for(int i = 1; i < n; ++i) {
			int k = (temp.second-i+n)%n;
			if (A[k] < temp.first) {
				dw.insert(A[k]);
				set <int>:: iterator ip = dw.find(A[k]);
				if (ip != dw.begin()) { 
					--ip;
					dw.erase(ip);
				}
				DW[n-i-1] = dw.size();
			} else {
				DW[n - i - 1] = n - i < n ? DW[n - i] : 0;
			}
		}
		for (int i = 0; i < n - 1; ++i) {
			if (DW[i + 1] + UP[i] >= m) {
				m = DW[i + 1] + UP[i];
			}
		}
	}
	cout << m + 1 << endl;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		DoIt();
	}
	return 0;
} 
