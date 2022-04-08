// https://hack.codingblocks.com/app/contests/2675/932/problem

#include <iostream>
#include <vector>
using namespace std;

class node{
public:
    node *left; // indicates if node has a child that represents bit 0
    node *right; // indicates if node has a child that represents bit 1
    vector<int> indexes; // stores the indexes of given array whose element is on that node
    node(){
        this->left = NULL;
        this->right = NULL;
    }
};

class trie{
    node* root;
public:
    trie(){
       root = new node();
    }

    void insert(int n, int index){
        node* temp = root;
        for(int i=31; i>=0; i--){
            int bit = (1<<i)&n; //Get ith bit
            if(!bit){
                // ith bit of n is 0, check if temp node has a left child or not
                if(!temp->left){
                    node* n = new node();
					temp->left = n;
                }
                temp->indexes.push_back(index); // update the indexes array
                temp = temp->left;
            }
            else{
                // ith bit of n is 1, check if temp node has a right child or not
                if(!temp->right){
                    node* n = new node();
					temp->right = n;
                }
                temp->indexes.push_back(index);
                temp = temp->right;
            }
        }
        temp->indexes.push_back(index);
    }

    bool binarySearch(vector<int> v, int l, int r){
        //Vector v has indices stored of the numbers of which this bit is a part of 
        //Since the insertion took place in increasing order , vector is already sorted
        int s = 0; 
        int e = v.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2; //or (s+e)>>1;
            int val = v[mid];

            if(val>=l and val<=r)
                return true;
            else if(val<l)
                s = mid+1;
            else
                e = mid-1;
        }
        return false;
    }

    int maxXor(int value, int l, int r){
        int currentXor = 0; // stores the ans
        node* temp = root;
        for(int i=31; i>=0; i--){
            int bit = (value>>i)&1;
            // ith bit is not set
            if(!bit){
                // temp node contains a complementary bit
                if(temp->right and binarySearch(temp->right->indexes,l,r)){
                    temp = temp->right;
                    currentXor += (1<<i); //Add the number with jth bit set to the currentXor
                }
                else{
                    // temp node contains the same bit
					temp = temp->left;
                }
            }
            else{
                // ith bit is set
                if(temp->left and binarySearch(temp->left->indexes,l,r)){
                    // 0 is already present at that place , just go 
                    temp = temp->left;
                }else{
                    // else we have to set 1 
                    temp = temp->right;
                    currentXor += (1<<i);
                }
            }
        }
        return currentXor;
    }
};
int main() {
    int q,j=0;
    cin>>q;
    trie t;
    while(q--){
        int n;
        cin>>n;

        if(n==0){
            cin>>n;
            t.insert(n,j++);
        }
        else{
            int l,r,x;
            cin>>l>>r>>x;
            cout<<t.maxXor(x,l-1,r-1)<<endl;
        }
    }
    return 0;
}
