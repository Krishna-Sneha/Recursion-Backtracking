// 1. You are given a string, which represents an expression having only opening and closing parenthesis.
// 2. You have to remove minimum number of parenthesis to make the given expression valid.
// 3. If there are multiple answers, you have to print all of them.

// i/p:
// ()())()
  
// o/p:
// (())()
// ()()()

#include<bits/stdc++.h>

using namespace std;

bool IsValidOrder(string pars)
{
    string pars1 = pars;
    stack<char>st;
    
    for(int i=0; i<pars1.size(); i++)
    {
        if(pars1[i] == '(')
        {
            st.push(pars1[i]);
        }
        
        else if(pars1[i] == ')' && st.size() && st.top() == '(')
        {
            st.pop();
        }
        
        else{
            return false;
        }
    }
    
    if(st.size() == 0)
        return true;
    return false;
}

void helper(string pars, int n, string extra, unordered_set<string>&st)
{
    if(extra.size() == 0)
    {
        if(st.find(pars) == st.end())
        {
            if(IsValidOrder(pars))
            {
                cout<<endl<<pars;
                st.insert(pars);
            }
        }
        return;
    }
    
    char e1 = extra[0];
    string roe = extra.substr(1);
    
    for(int i=0; i<pars.size(); i++)
    {
        if(pars[i] == e1)
        {
            char rem = pars[i];
            pars.erase(pars.begin()+i);
            helper(pars, n, roe,st);
            pars.insert(pars.begin()+i, rem);
        }
    }
    
}

int main()
{
    string pars;
    cin>>pars;
    int o=0, c=0;
    
    
    while(pars[0] == ')')
        pars.erase(pars.begin()+0);
    
    for(int i=0; i<pars.size(); i++)
    {
        if(pars[i] == '(')
            o++;
        else if(pars[i] == ')')
            c++;
    }
    
    string extra = "";
    unordered_set<string>st;
    
    
    if(o > c)
    {
        for(int i=0; i<(o-c); i++)
        {
            extra = extra+"(";
        }
    }
    else if(c > o)
    {
        for(int i=0; i<(c-o); i++)
        {
            extra = extra+")";
        }   
    }
    
    helper(pars, pars.size(), extra, st);
}
