// 1. You are given a string str.
// 2. Complete the body of printSS function - without changing signature - to calculate and print all subsequences of str.

// In this question we can only print substring not store them since the size generated for higher length string would be a lot
// For eg: i/p: abc  o/p: abc, ab, ac, a, bc, b, c, _ => 2^(sizeof(inp)) - op1

// pairs => (abc, _), (ab, c), (ac, b), (a, bc) => 2^(sizeof(inp))/2 == 2^sizeof(inp-1) * sizeof(inp);

// space for "abc" = 2^2 * 3
// for any string of 31 chars => 2^30 * 31 ~= 31GB whichis greater than the normal RAM(i.e 8GB, 16GB).

#include<bits/stdc++.h>
using namespace std;

void printSS(string ques, string ans){
    // write your code here
    
    if(ques.size() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    
    string op1 = ans;
    string op2 = ans;
    op1.push_back(ques[0]);
    ques.erase(ques.begin() + 0);
    printSS(ques, op1);
    printSS(ques, op2);
    
      
}

int main(){
    string str;
    cin >> str;
    cout<<endl;
    printSS(str, "");
}
