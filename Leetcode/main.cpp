#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <set>

using namespace std;

#define For(i,m,n) for(int i=m; i < n; i++)
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int cnt = 0;
        int prev, prev_prev;
        for(int i = 0 ; i < n ;i++){
            cout << i << " " << cnt << " " << prev << endl;
            if(i>=2){
                if(cnt==i-2){
                    if(A[i]==A[i-1] && A[i-1]==prev){
                        cout << "FIRST" <<endl;
                        continue;
                    }
                }
                if(cnt==i-1){
                    
                }
                else if(A[i]==A[i-1] && A[i-1]==A[i-2]){
                    cout << "SECOND" <<endl;
                    continue;
                }
            }
            prev_prev = prev;
            prev = A[cnt];
            A[cnt++]=A[i];
        }
        return cnt;
    }
};


int main(int argc, char** argv){
    Solution sol;
    vector<int> x = {-50,-49,-49,-44,-43,-42,-41,-41,-40,-40,-36,-35,-35,-35,-34,-33,-31,-31,-30,-30,-29,-29,-28,-27,-27,-27,-27,-25,-25,-25,-25,-24,-20,-20,-20,-20,-19,-18,-18,-18,-18,-17,-17,-16,-16,-12,-12,-11,-10,-9,-8,-7,-7,-7,-7,-5,-4,-2,-2,1,1,1,5,6,8,9,12,13,13,14,14,16,18,18,19,20,21,21,22,22,23,23,24,25,27,27,27,28,28,28,30,31,31,31,34,35,35,36,38,39,40,41,41,42,42,43,43,44,44,44,47,48};
// g
   vector<int> x{1,1,1,2,2,3};
    int *arr = new int[x.size()];
    copy(x.begin(), x.end(), arr);
    int m = sol.removeDuplicates(arr,x.size());

    for(int i =0; i < m; i++)
	cout << arr[i] << " ";
    cout<<endl;
    delete arr;
    return 0;
}
