#include<bits/stdc++.h>

using namespace std;

int getNum(string s, map<char, int>mp)
{
    int n=0;
    
    for(int i=0; i<s.size(); i++)
    {
        n = n*10+mp[s[i]];
    }
    
    return n;
}

void helper(map<char, int>&mp, string unique, string s1, string s2, string s3, bool usedNum[], int ind)
{
    
    if(ind == unique.size())
    {
        int n1 = getNum(s1, mp);
        int n2 = getNum(s2, mp);
        int n3 = getNum(s3, mp);
        
        if(n1+n2 == n3)
        {
            for(int i=0; i<26; i++)
            {
                char ch = 'a'+i;
                if(mp.find(ch) != mp.end())
                    cout<<ch<<"-"<<mp[ch]<<" ";
            }
            cout<<endl;
        }
    }
    
    for(int i=0; i<10; i++)
    {
        if(usedNum[i] == false)
        {
            usedNum[i] = true;
            mp[unique[ind]] = i;
            helper(mp, unique, s1, s2, s3, usedNum, ind+1);
            //backtrack
            usedNum[i] = false;
            mp[unique[ind]] = -1;
        }
    }
}

int main()
{
    string s1, s2, s3, unique;
    map<char, int> mp;
    bool usedNum[10];
    memset(usedNum, false, sizeof(usedNum));
    
    cin>>s1>>s2>>s3;
    
    for(int i=0; i<s1.size(); i++)
    {
        if(mp.find(s1[i])==mp.end())
        {
            unique.push_back(s1[i]);
            mp[s1[i]] = -1;
        }
    }
    for(int i=0; i<s2.size(); i++)
    {
        if(mp.find(s2[i])==mp.end())
        {
            unique.push_back(s2[i]);
            mp[s2[i]] = -1;
        }
    }
    for(int i=0; i<s3.size(); i++)
    {
        if(mp.find(s3[i])==mp.end())
        {
            unique.push_back(s3[i]);
            mp[s3[i]] = -1;
        }
    }
    
    helper(mp, unique, s1, s2, s3, usedNum, 0);
    
}
