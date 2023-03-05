// 1. You are given a 10*10 2-D array(arr) containing only '+' and '-' characters, which represents a 
//     crossword puzzle. 
// 2. You are also given n number of words which need to be filled into the crossword.
// 3. Cells containing '-' are to be filled with the given words.
  
#include<bits/stdc++.h>

using namespace std;

bool canPlaceVertically(vector<vector<char>>&puzz, string word, int i, int j)
{
    if(i-1 >= 0 && puzz[i-1][j] != '+')
        return false;
    if(i+word.size() <= puzz.size()-1 && puzz[i+word.size()][j] != '+')
        return false;
    
    for(int ii=0; ii<word.size(); ii++)
    {
        if(puzz[i+ii][j] == '-' || puzz[i+ii][j] == word[ii])
            continue;
        else
            return false;
    }
    
    return true;
}

bool canPlaceHorizontally(vector<vector<char>>&puzz, string word, int i, int j)
{
    if(j-1 >= 0 && puzz[i][j-1] != '+')
        return false;
    if(j+word.size() <= puzz[i].size()-1 && puzz[i][j+word.size()] != '+')
        return false;
        
    for(int jj=0; jj<word.size(); jj++)
    {
        if(puzz[i][j+jj] == '-' || puzz[i][j+jj] == word[jj])
            continue;
        else
            return false;
    }
    
    return true;
}



void fillPuzzleVertical(vector<vector<char>>&puzz, string word, int i, int j)
{
    
    for(int ii=0; ii<word.size(); ii++)
    {
        if(puzz[i+ii][j] == word[ii])
            continue;
        puzz[i+ii][j] = word[ii];
    }
}

void fillPuzzleHorizontal(vector<vector<char>>&puzz, string word, int i, int j)
{
    
    for(int jj=0; jj<word.size(); jj++)
    {
        if(puzz[i][j+jj] == word[jj])
            continue;
        puzz[i][j+jj] = word[jj];
    }
    
}

void unFillPuzzleVertical(vector<vector<char>>&puzz, string word, int i, int j)
{
    for(int ii=0; ii<word.size(); ii++)
    {
        if(j==0 || j == puzz[i].size()-1 || (puzz[i+ii][j-1] == '+' && puzz[i+ii][j+1] == '+'))
            puzz[i+ii][j] = '-';
    }
}

void unFillPuzzleHorizontal(vector<vector<char>>&puzz, string word, int i, int j)
{
    for(int jj=0; jj<word.size(); jj++)
    {
        if(i==0 || i == puzz.size()-1 || (puzz[i-1][j+jj] == '+' && puzz[i+1][j+jj] == '+'))
            puzz[i][j+jj] = '-';
    }
}

void display(vector<vector<char>>puzz)
{
    cout<<"displayFunc:"<<endl;
    for(int i=0; i<puzz.size(); i++)
    {
        for(int j=0; j<puzz[i].size(); j++)
        {
            cout<<puzz[i][j];
        }
        cout<<endl;
    }
}

void Solution(vector<vector<char>>&puzz, vector<string>words, int ind)
{
    if(ind == words.size())
    {
        display(puzz);
        return;
    }
    for(int i=0; i<puzz.size(); i++)
    {
        for(int j=0; j<puzz[i].size(); j++)
        {
            if(puzz[i][j] != '+')
            {
                if(canPlaceVertically(puzz, words[ind], i, j))
                {
                    fillPuzzleVertical(puzz, words[ind], i, j);
                    Solution(puzz, words, ind+1);
                    unFillPuzzleVertical(puzz, words[ind], i, j);
                }
                
                else if(canPlaceHorizontally(puzz, words[ind], i, j))
                {
                    fillPuzzleHorizontal(puzz, words[ind], i, j);
                    Solution(puzz, words, ind+1);
                    unFillPuzzleHorizontal(puzz, words[ind], i, j);
                }
            }
        }
    }
}

int main()
{
    char ele;
    int count;
    cin>>count;
    vector<vector<char>>puzz(count, vector<char>(count));
    
    for(int i=0; i<count; i++)
    {
        for(int j=0; j<count; j++)
        {
            cin>>ele;
            puzz[i][j] = ele;
        }
    }
    
    int n;
    cin>>n;
    vector<string>words;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        words.push_back(s);
    }
    
    Solution(puzz, words, 0);
}
