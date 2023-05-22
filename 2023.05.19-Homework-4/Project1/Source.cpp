#include<iostream>
#include<ostream>

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int data, Node* left = nullptr, Node* right = nullptr) :
		data(data), left(left), right(right) {}
};

class BTree
{
private:
	Node* root;

	void Insert(Node*& root, Node* node)
	{
		if (root == nullptr)
		{
			root = node;
			return;
		}
		if (root->data > node->data)
		{
			return Insert(root->left, node);
		}
		if (root->data < node->data)
		{
			return Insert(root->right, node);
		}
		if (root->data == node->data)
		{
			return;
		}
	}

	void Print(std::ostream& stream, Node*& root, int depth = 0)
	{
		if (root == nullptr)
		{
			return;
		}
		Print(stream, root->left, depth + 1);
		for (int i = 0; i < depth; ++i)
		{
			std::cout << "\t";
		}
		stream << root->data << std::endl;
		Print(stream, root->right, depth + 1);
	}

	Node*& GetNode(Node*& node, int element)
	{
		if (node == nullptr || node->data == element)
		{
			return node;
		}
		if (node->data > element)
		{
			return GetNode(node->left, element);
		}
		if (node->data < element)
		{
			return GetNode(node->right, element);
		}
	}

	Node* Extract(Node*& node)
	{
		Node* tnode = node;

		if (node->left == nullptr && node->right == nullptr)
		{
			node = nullptr;
		}
		else if (node->left == nullptr)
		{
			node = node->right;
		}
		else if (node->right == nullptr)
		{
			node = node->left;
		}
		else if (node->left->right == nullptr)
		{
			node->left->right = node->right;
			node = node->left;
		}
		else if (node->right->left == nullptr)
		{
			node->right->left = node->left;
			node = node->right;
		}
		else
		{
			Node* t = node->right;
			while (t->left->left != nullptr)
			{
				t = t->left;
			}
			Node* nnode = Extract(t->left);
			nnode->left = node->left;
			nnode->right = node->right;
			node = nnode;
		}

		tnode->right = nullptr;
		tnode->left = nullptr;
		return tnode;
	}

	void RotateLeft(Node*& node) //4(2(1,3),6(5,7)) -> ...
	{
		if (node == nullptr || node->right == nullptr)
		{
			return;
		}
		Node* t = node->right;
		node->right = t->left;
		t->left = node;
		node = t;
	}

	void RotateRight(Node*& node) //4(2(1,3),6(5,7)) -> 2(1,4(3,6(5,7)))
	{
		if (node == nullptr || node->left == nullptr)
		{
			return;
		}
		Node* t = node->left;
		node->left = t->right;
		t->right = node;
		node = t;
	}

	int Depth(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int left = Depth(node->left);
		int right = Depth(node->right);
		int mx = (left > right ? left : right);
		return mx + 1;
	}

	int CountElems(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		return 1 + CountElems(node->left) + CountElems(node->right);
	}

	void Balancing(Node*& node)
	{
		if ((Depth(node->left) - Depth(node->right) == -1) || ((Depth(node->left) - Depth(node->right) == 0)) || ((Depth(node->left) - Depth(node->right) == 1)))
		{
			return;
		}
		else if (Depth(node->left) > Depth(node->right))
		{
			return RotateRight(node);
		}
		else if (Depth(node->left) < Depth(node->right))
		{
			return RotateLeft(node);
		}
		Balancing(node->left);
		Balancing(node->right);
	}

public:
	BTree() : root(nullptr) {}

	void Add(int data)
	{
		Insert(root, new Node(data));
	}

	void Remove(int data)
	{
		Node*& node = GetNode(root, data);
		if (node != nullptr)
		{
			Node* extracted = Extract(node);
			delete extracted;
		}
	}

	bool Contains(int data)
	{
		return (GetNode(root, data) != nullptr);
	}

	void Rotate(int data, bool left)
	{
		Node*& node = GetNode(root, data);
		if (node == nullptr)
		{
			return;
		}
		if (left)
		{
			RotateLeft(node);																				
		}
		else
		{
			RotateRight(node);
		}
	}

	int Depth()
	{
		return Depth(root);
	}

	int Hight(int data)
	{
		Node* node = GetNode(root, data);
		return Depth(node);
	}
	void Ballancing()
	{
		return Balancing(root);
	}

	friend std::ostream& operator<<(std::ostream& stream, BTree& tree)
	{
		stream << "__________________" << std::endl;
		if (tree.root == nullptr)
		{
			stream << "EMPTY" << std::endl;
		}
		else
		{
			tree.Print(stream, tree.root);
		}
		stream << "__________________" << std::endl;
		return stream;
	}
};

int main(int argc, char* argv[])
{
	BTree tree;
	tree.Add(5);
	tree.Add(6);
	tree.Add(3);
	tree.Add(2);
	tree.Add(1);


	
	std::cout << tree << std::endl;
	tree.Ballancing();
	std::cout << tree << std::endl;
	
	return EXIT_SUCCESS;
}