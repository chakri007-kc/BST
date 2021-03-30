#include <bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* left=NULL;
		Node* right=NULL;
};
Node* BstNode(int d)
{
	Node* newnode= new Node();
	newnode->data=d;
	newnode->left=newnode->right=NULL;
	return newnode;
}
Node* insert(Node* root,int d)
{
	if(root==NULL)
	{
		root=BstNode(d);
		return root;
	}
	else if(d<=root->data)
	{
		root->left=insert(root->left,d);
	}
	else
	{
		root->right=insert(root->right,d);
	}
}
bool search(Node* root,int d)
{
	if(root==NULL)
	{
		return 0;
	}
	else if(root->data==d)
	{
		return 1;
	}
	else if(d<=root->data)
	{
		search(root->left,d);
	}
	else
	{
		search(root->right,d);
	}
}
void max(Node* root)
{
	if(root==NULL)
	{
		cout<<root->data<<" ";
		return;
	}
	else if(root->right==NULL)
	{
		cout<<root->data<<" ";
		return;
	}
	max(root->right);
}
Node* FindMin(Node* root)
{
	if(root==NULL)
	{
//		cout<<root->data<<" ";
//		return;
		return root;
	}
	else if(root->left==NULL)
	{
//		cout<<root->data<<" ";
		return root;
	}
	FindMin(root->left);
}
int height(Node* root)
{
	if(root==NULL)
	{
		return -1;
	}
	return max(height(root->left),height(root->right))+1;
}
void inorder(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void levelorder(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	queue <Node*> q;
	q.push(root);

	while(!q.empty())
	{
		Node* current=q.front();
		cout<<current->data<<" ";
		if(current->left != NULL)
		{
			q.push(current->left);
		}
		if(current->right != NULL)
		{
			q.push(current->right);
		}
		q.pop();
		
	}
}
//
//	
//	bool rst(Node* root,int value)
//	{
//		if(root==NULL)
//		{
//			return true;			
//		}
//		else if(root->data > value && rst(root->left,value) && rst(root->right,value))
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//		
//	}
//	bool lst(Node* root,int value)
//	{
//		if(root==NULL)
//		{
//			return true;
//		}
//		else if(root->data <=value && lst(root->left,value) && lst(root->right,value))
//		{
//			return true ;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	bool bs(Node* root)
//	{
//		if(root==NULL)
//		{
//			return true;
//		}
//		if(lst(root->left,root->data) && rst(root->right,root->data) && bs(root->left) && bs(root->right))
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	
//	}	
bool util(Node* root,int min,int max)
{
	if(root==NULL)
	{
		return true;
	}
	else if(root->data >min && root->data<max && util(root->left,min,root->data) && util(root->right,root->data,max))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool bs(Node* root)
{
	return util(root,INT_MIN,INT_MAX);
}
Node *delete1(Node* root,int d)
{
	if(root==NULL)
	{
		return root;
	}
	else if(root->data > d)
	{
		root->left=delete1(root->left,d);
		
	}
	else if(root->data < d)
	{
		root->right=delete1(root->right,d);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root =NULL;
		}
		else if(root->left == NULL)
		{
			Node* temp=root;
			root=root->right;
			delete temp;
		}
		else if(root->right ==NULL)
		{
			Node* temp=root;
			root=root->left;
			delete temp;
		}
		else
		{
			Node* temp=FindMin(root->right)	;
			root->data=temp->data;
			root->right=delete1(root->right,temp->data);
		
		}
		return root;
	}
}
int main()
{
	Node* root=BstNode(5);
	insert(root,7);
	insert(root,2);
	insert(root,9);
	bool z=search(root,5);
	if(z==true)
	{
		cout<<"found";
	}
	else
	{
		cout<<"not found";
	}
	max(root);
	cout<<height(root)<<" ";
	cout<<"\n";
	levelorder(root);
	cout<<"\n";
	bool k=bs(root);
//bool k=util(root,INT_MIN,INT_MAX);
	if(k==1)
	{
		cout<<"yes";
	}
	else
	{
		cout<<"no";
	}
	root=delete1(root,5);
	
	inorder(root);
}
