#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	map<string,string> M;
	M["A"] = "is"; M["B"] = "mm"; M["C"] = "oo"; M["D"] = "rgr"; M["E"] = "ryg"; M["F"] = "dth"; M["G"] = "you"; M["H"] = "esol"; 
	M["I"] = "ionA"; M["J"] = "GDaBarA"; M["K"] = "veECFHutI"; M["L"] = "PQ"; M["M"] = "n"; M["N"] = "m"; M["O"] = "oaNcho"; 
	M["P"] = "MO"; M["Q"] = "NR"; M["R"] = "sky"; M["S"] = "JKL";
	string s="S";
	int i = 0;
	while( i < s.length() ) { 
		string ch = ""; ch = ch + s[i];
		if ( M[ch] != "" ) {
			s = s.replace(i, 1, M[ch]);
			i = 0;
		} else i++;
	}
	cout << s << endl;
	return 0;
}
