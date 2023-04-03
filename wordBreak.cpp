// 1. You are given n space separated strings, which represents a dictionary of words.
// 2. You are given another string which represents a sentence.
// 3. You have to print all possible sentences from the string, such that words of the sentence are 
//      present in dictionary.

// i/p:
// 11
// i like pep coding pepper eating mango man go in pepcoding
// ilikepeppereatingmangoinpepcoding

// o/p:
// i like pepper eating man go in pep coding 
// i like pepper eating man go in pepcoding 
// i like pepper eating mango in pep coding 
// i like pepper eating mango in pepcoding 


#include<bits/stdc++.h>

using namespace std;

void helper(int n, unordered_set<string>&words, string str, vector<string>&ans)
{
    
    if(str.size() == 0)
    {
        cout<<endl;
        for(string res : ans)
        {
            cout<<res<<" ";
        }
        return;
    }
    
    for(int i=0; i<str.size(); i++)
    {
        string temp = str.substr(0, i+1);
        if(words.find(temp) != words.end())
        {
            ans.push_back(temp);
            string ros = str.substr(temp.size());
            helper(n, words, ros, ans);
            ans.pop_back();
        }
    }
}


int main()
{
    int n;
    cin>>n;
    unordered_set<string>words;
    string str;
    
    for(int i=0; i<n; i++)
    {
        string a;
        cin>>a;
        words.insert(a);
    }
    cin>>str;
    vector<string>ans;
    
    helper(n, words, str, ans);
}
