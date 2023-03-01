// 1. You are given a word.
// 2. You have to generate all abbrevations of that word.

#include<bits/stdc++.h>

using namespace std;

void Abbrevation(string s, string asf, int count, int ind)
{
    if(ind == s.size())
    {
        if(count == 0)
            cout<<asf<<endl;
            
        else
        {
            string c = to_string(count);
            cout<<asf+c<<endl;
        }
        
        return;
    }
    
    string c = to_string(count);
    
    if(count>0)
    {
        Abbrevation(s, asf+c+s[ind], 0, ind+1);
    }
    else
        Abbrevation(s, asf+s[ind], 0, ind+1);
    
    Abbrevation(s, asf, count+1, ind+1);
    
    

}

int main(){
    string s;
    cin>>s;
    
    Abbrevation(s, "", 0, 0);
}
