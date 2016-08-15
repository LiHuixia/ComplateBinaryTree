#include<iostream>
#include<queue>
using namespace std;

template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
	BinaryTreeNode(const T& d)
		:_data(d)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(const T *a, size_t size, const T& invalid)
	{
		size_t index = 0;
		_root = _CreateNode(a, size, index, invalid);
	}
	void CheckCompleteTree()
	{
		bool ret;
		ret = _CheckCompleteTree(_root);
		cout << "Is a complate BinaryTree?:" << ret << endl;
	}

protected:
	bool _CheckCompleteTree(Node *root)
	{
		queue<Node*> q;
		if (root == NULL)      //空树是完全二叉树
			return true;
		q.push(root);
		bool flag = false;
		while (!q.empty())
		{
			Node* front = q.front();
			if (front != NULL)
			{
				if (flag)
					return false;
				q.push(front->_left);
				q.push(front->_right);
			}
			else
				flag = true;
			q.pop();
		}
		return true;
	}
	Node * _CreateNode(const T* a, size_t size, size_t& index, const T& invalid)
	{
		Node* root = NULL;
		while ((index < size) && (a[index] != invalid))
		{
			root = new Node(a[index]);
			root->_left = _CreateNode(a, size, ++index, invalid);
			root->_right = _CreateNode(a, size, ++index, invalid);
		}
		return root;
	}
protected:
	Node* _root;
};
int main()
{
	int a[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6, };
	BinaryTree<int> b1(a,10,'#');
	b1.CheckCompleteTree();
	int a2[9] = { 1, 2, '#', 3,'#', 4, '#', '#', 5 };
	BinaryTree<int> b2(a2, 9, '#');
	b2.CheckCompleteTree();

	system("pause");
	return 0;
}

