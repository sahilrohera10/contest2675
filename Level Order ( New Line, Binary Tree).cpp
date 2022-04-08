// https://hack.codingblocks.com/app/contests/2675/430/problem

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node * left;
    node * right;
    node(int d): data(d), left(NULL), right(NULL){}
};

node *create(){
    int d;
    cin>>d;
    node * root=new node (d);
    string s;

    cin>>s;
    if(s=="true"){
        root->left=create();
    }

	cin>>s;
	if(s=="true"){
		root->right=create();
	}
return root;

return NULL;
}

void LevelOrder(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		auto x = q.front();
		q.pop();

		if(x){
			cout<<x->data<<" ";
			if(x->left)
				q.push(x->left);
			if(x->right)
				q.push(x->right);
		}else{
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}
	}
}

int main(){
    node * root;
    root=create();

    LevelOrder(root);
    return 0;
}