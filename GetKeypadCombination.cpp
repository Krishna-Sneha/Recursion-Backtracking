// 1. You are given a string str. The string str will contains numbers only, where each number stands for a key pressed on a mobile phone.
// 2. The following list is the key to characters map :
//     0 -> .;
//     1 -> abc
//     2 -> def
//     3 -> ghi
//     4 -> jkl
//     5 -> mno
//     6 -> pqrs
//     7 -> tu
//     8 -> vwx
//     9 -> yz

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKPC(string s) {
  //Write your code here
  
    if(s.size() == 0)
    {
        vector<string>base;
        base.push_back("");
        return base;
    }
    
    char ind = s[0];
    s.erase(s.begin() + 0);
    vector<string> rres = getKPC(s);
    
    vector<string> mres;
    string code = codes[ind-'0'];
    
    for(int i=0; i<code.size(); i++)
    {
        for(string st: rres)
        {
            mres.push_back(code[i]+st);
        }
    }
    
    return mres;
}


int main() {
  string s;
  cin >> s;
  vector<string> ans = getKPC(s);
  int cnt = 0;

  cout << '[';
  for (string str : ans) {
    if (cnt != ans.size() - 1)
      cout << str << ", ";
    else
      cout << str;
    cnt++;
  }
  cout << ']';
}
