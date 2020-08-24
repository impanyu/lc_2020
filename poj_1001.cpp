#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string MUL(string s1, string s2){
	int i,j;
	int m = s1.size(), n = s2.size();
	string ans;
	//small endian
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	vector<int> v(m+n, 0);
	for(i = 0; i < m ; i++){
		for(j = 0; j < n; j++){
			v[i+j] += (s1[i] - '0') * (s2[j] - '0');
			v[i+j+1] += v[i+j] / 10;
			v[i+j] = v[i+j] % 10; 
		}
	}
	//for(i = m+n-1; i > 0 && v[i] == 0; i--);
	for(i=m+n-1;i>=0;i--)
		ans += (char)(v[i] + '0');
   
	return ans;

}

int main(){
	string s1;
	int s2;
	while(cin>>s1>>s2){
		int t;
		string ans = "1";
		t = s1.find(".");
		s1 = s1.substr(0,t) + s1.substr(t+1);
		t = s1.length() - t;
		for(int i = 0; i < s2; i++)
			ans = MUL(ans,s1);

		int L = ans.size();
		t = t*s2;
		ans = ans.substr(0,L-t)+"."+ans.substr(L-t);
		int i = 0;
		//delete front 0s before '.'
		for(;i< ans.size() && ans[i] == '0' ; i++);
		ans = ans.substr(i);

		//delete trailing 0s
		for(i = ans.size()-1;i>=0 && ans[i] == '0';i--);
		if(ans[i] == '.')
			ans = ans.substr(0,i);
		else
			ans = ans.substr(0,i+1);

		cout<<ans<<endl;
	}
	return 0;
}

