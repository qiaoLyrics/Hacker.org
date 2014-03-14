#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string,int> M;
vector<string> v;
int best;
string s, ans;
char str[10000];

bool is_alpha(char c) {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
void to_lower(char &c) {
	if('A' <= c && c <= 'Z') c = c - 'A' + 'a';
}
int main()
{
	while(scanf("%s", str) != EOF) {
		s = (string) str;
		for(string :: iterator it = s.begin(); it != s.end() ;it++) to_lower(*it);
		while(s.size() > 0 && !is_alpha( s[s.length()-1] )) s = s.substr(0, s.length() - 1);
		while(s.size() > 0 && !is_alpha( s[0] ))			s = s.substr(1, s.length() - 1);
		if(s.length() == 9) {
			if('A' <= s[0] && s[0] <= 'Z') s[0] = s[0] - 'A' + 'a';
			if(++M[s] > best) best = M[s], ans = s;

			if(M[s] == 1) v.push_back(s);
		}
	}
	for(vector<string> :: iterator it = v.begin(); it != v.end(); it ++) 
		cout << *it << " : " << M[*it] << endl;
	cout << ans << endl;	
	return 0;
}
