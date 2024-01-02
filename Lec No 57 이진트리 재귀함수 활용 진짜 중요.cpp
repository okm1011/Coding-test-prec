#include<iostream>
#define null 0
using namespace std;


/*
      1
  2      3
4  5    6 7


*/

template<typename T>
class Tree;

template<typename T>
class TreeNode{
	friend class Tree<T>;
private:
	T data;
	TreeNode*left;
	TreeNode*right;
public:
	TreeNode(T data = 0,TreeNode*left = null,TreeNode*right = null){
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

template<typename T>
class Tree{
	
private:
	TreeNode<T>*root;
public:
	Tree(T data = 0){
		root = new TreeNode<T>(data);
		
	}
	buildTree(){
		root->left = new TreeNode<T>(2,new TreeNode<T>(4),new TreeNode<T>(5));
		root->right = new TreeNode<T>(3,new TreeNode<T>(6),new TreeNode<T>(7)); 
	}
	TreeNode<T>*getRoot(){
		return root;
	}
	void visit(TreeNode<T>*current){
		cout << current->data << " ";
	}
	void preorder(TreeNode<T>*current){
		if(current != null){
			visit(current);
			preorder(current->left);
			preorder(current->right);
		}
	}
	void inorder(TreeNode<T>*current){
		if(current != null){
			inorder(current->left);
			visit(current);
			inorder(current->right);
		}
	}
	void postorder(TreeNode<T>*current){
		if(current != null){
			postorder(current->left);
			postorder(current->right);
			visit(current);
		}
	}
};





int main(){
	Tree<int> tree(1);
	tree.buildTree();
	
	cout << "Preorder >> ";
    tree.preorder(tree.getRoot());
    cout << endl;
 
    cout << "Inorder >> ";
    tree.inorder(tree.getRoot());
    cout << endl;
 
    cout << "Postorder >> ";
    tree.postorder(tree.getRoot());
    cout << endl;
	return 0;
}
