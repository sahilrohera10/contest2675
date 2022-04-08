// https://hack.codingblocks.com/app/contests/2675/2504/problem



#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class trie{
  public:
  trie* leaf[26];
  int val=0;
};

vector<string> prefix(vector<string> &A) {
    trie* start=new trie;
    for(int i=0;i<26;i++)
        start->leaf[i]=NULL;
    for(string i:A)
    {
        trie* path=start;
        for(char j:i){
            if(path->leaf[j-'a']==NULL){
                trie* temp=new trie;
                for(int k=0;k<26;k++)
                    temp->leaf[k]=NULL;
                temp->val=1;
                path->leaf[j-'a']=temp;
                path=temp;
            }
            else{
                path=path->leaf[j-'a'];
                path->val++;
            }
        }
    }
    vector<string> ans;
    for(string i:A){
        string prefix="";
        trie* path=start;
        for(char j:i){
            if(path->val==1)
                break;
            else{
                prefix+=j;
                path=path->leaf[j-'a'];
            }
        }
        ans.push_back(prefix);
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    trie t;
    vector<string> v(n);
    for(string &s : v)
        cin>>s;
    vector<string> x = prefix(v);
    for(string s : x)
        cout<<s<<" ";
}
