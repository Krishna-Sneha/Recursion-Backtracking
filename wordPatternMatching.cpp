#include<bits/stdc++.h>

using namespace std;

void helper(string str, string ptr, unordered_map<char, string>&mp)
{
    string str1 = str;
    string ptr1 = ptr;
    unordered_map<char, string>mp1 = mp;
    
    
    if(ptr1.size() == 0)
    {
        if(str1.size() == 0)
        {
            for(auto it=mp1.begin(); it!=mp1.end(); it++)
            {
                cout<<it->first<<"->"<<it->second<<" ";
            }
            
            cout<<endl;
        }
        
        return;
    }
                                
    char pattern = ptr[0];     
    string rop = ptr.substr(1);
    if(mp1[pattern] == "")      
    {
        for(int b=0; b<str1.size(); b++)
        {
            mp1[pattern] = mp1[pattern]+str1.substr(0, b+1);      
            string restOfStr = str1.substr(b+1);
            helper(restOfStr, rop, mp1);
            mp1[pattern].clear();
        }               
    string rop = ptr1.substr(1);                                
    
    }
    else
    {
        string re = mp1[pattern];   
        if(re.size() <= str1.size())
        {
            string left = str1.substr(0, re.size());
            string right = str1.substr(re.size());
            if(left == re)
                helper(right, rop, mp1);
        }
    }
}

int main()
{
    string str, ptr;
    
    cin>>str>>ptr;
    
    unordered_map<char, string>mp;
    
    for(int i=0; i<ptr.size(); i++)
    {
        mp[ptr[i]] = "";
    }
        
    helper(str, ptr, mp);
}


