#include<iostream>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;

class Rule{
public:
    string name;
    bool sorted, unique;
    int n;
    int k;
    long total;
    void Initialize(string str){
	int len = str.size();
	unique = str[len-1]=='T';
	sorted = str[len-3]=='T';
	int colon = str.find(':');
	name = str.substr(0,colon);
	istringstream(str.substr(colon+1)) >> n >> k;
	Calculate();
    }
    
    long Cnk(int n, int k){
	long ret =1;
	for(int i=0; i<k; i++)
	    ret*=(n-i);
	for(int i=0; i<k; i++)
	    ret/=(i+1);
	return ret;
    }
    
    void Calculate(){
	int choice = 10*(int)sorted + (int)unique;
	switch(choice){
	case 11:
	    total = Cnk(n,k);
	    break;
	case 10:
	    total= Cnk(n+k-1,k);
	    break;
	case 1:
	    total = 1;
	    for(int i=0; i<k; i++)
		total*=(n-i);
	    break;
	case 0:
	    total = pow(n,k);
	    break;
	}
    }
};


class Lottery{
public:
    vector<string> sortByOdds(vector<string> rules){
	int N = rules.size();
	if(N==0) return vector<string>();
	vector<Rule> data(N);
	for(int i=0; i<N; i++)
	    data[i].Initialize(rules[i]);
	sort(data.begin(), data.end(),[](const Rule &a, const Rule&b) -> bool {return a.total== b.total ? a.name < b.name : a.total < b.total;});
	vector<string> ret(N);
	for(int i=0; i<N; i++){
	    ret[i] = data[i].name;
	    cout << data[i].name << " " << data[i].total <<endl;
	}
	return ret;
    }
};

int main(int argc, char ** argv){
    vector<string> rules

    {"INDIGO: 93 8 T F",
	    "ORANGE: 29 8 F T",
	    "VIOLET: 76 6 F F",
	    "BLUE: 100 8 T T",
	    "RED: 99 8 T T",
	    "GREEN: 78 6 F T",
	    "YELLOW: 75 6 F F"};
    // {"PICK ANY TWO: 10 3 F F"
    // 	    ,"PICK TWO IN ORDER: 10 3 T F"
    // 	    ,"PICK TWO DIFFERENT: 10 3 F T"
    // 	    ,"PICK TWO LIMITED: 10 2 T T"};
    
    Lottery lot;
    lot.sortByOdds(rules);
    return 0;
}
