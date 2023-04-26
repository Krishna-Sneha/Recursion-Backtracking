// i/p: 
// 5
// 3
  
// o/p:
// 12300
// 12030
// 12003
// 13200
// 13020
// 13002
// 10230
// 10203
// 10320
// 10302
// 10023
// 10032
// 21300
// 21030
// 21003
// 23100
// 23010
// 23001
// 20130
// 20103
// 20310
// 20301
// 20013
// 20031
// 31200
// 31020
// 31002
// 32100
// 32010
// 32001
// 30120
// 30102
// 30210
// 30201
// 30012
// 30021
// 01230
// 01203
// 01320
// 01302
// 01023
// 01032
// 02130
// 02103
// 02310
// 02301
// 02013
// 02031
// 03120
// 03102
// 03210
// 03201
// 03012
// 03021
// 00123
// 00132
// 00213
// 00231
// 00312
// 00321


#include<bits/stdc++.h>

using namespace std;

void helper(int currBox1, int totalBoxes1, vector<bool>&items1, int ssf1, int ts1, string asf1)
{
    int currBox = currBox1;
    int totalBoxes = totalBoxes1;
    vector<bool>items = items1;
    int ssf = ssf1;
    int ts = ts1;
    string asf = asf1;
    
    if(currBox > totalBoxes)
    {
        if(ssf == ts)
        {
            cout<<asf<<endl;
        }
        
        return;
    }
    
    for(int i=0; i<ts; i++)
    {
        if(items[i] == false)
        {
            items[i] = true;
            char ch = (i+1) + '0';
            helper(currBox+1, totalBoxes, items, ssf+1, ts, asf+ch);
            items[i] = false;
        }
    }
    
    helper(currBox+1, totalBoxes, items, ssf, ts, asf+'0');
}

int main()
{
    int n,k;
    
    cin>>n>>k;
    
    vector<bool>items(k);
    
    helper(1, n, items, 0, k, "");
}
