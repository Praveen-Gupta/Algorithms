#include <queue>
#include <iostream>

using namespace std;

class Node
{
private:
	int nData;
	int nWidth;
	Node* pFirst;
	Node* pRight;
	Node* pVertical;

	Node(int nInData) : nData(nInData), nWidth(0), pFirst(nullptr), pRight(nullptr), pVertical(nullptr)
	{};
	friend class BinaryTree;
};
class BinaryTree
{
public:
	Node* m_pRoot;
	int m_nWidth = 100;
	mutable Node* m_pNodePosAddress[50]; // Initialize it to nullptr / 0
	mutable Node* m_pNodeNegAddress[50]; // Initialize it to nullptr / 0

	int m_nMaxWidth;
	int m_nMinWidth;

public:

	BinaryTree() : m_pRoot(nullptr), m_nMaxWidth(0), m_nMinWidth(0)
	{
		for (int i = 0; i < 50; i++)
		{
			m_pNodePosAddress[i] = m_pNodeNegAddress[i] = 0;
		}
	}

	virtual ~BinaryTree()
	{
		//Deelte Tree here
	}

	int AddVerticalNode(Node* currNode)
	{
		if (currNode->nWidth >= 0)
		{
			if (m_pNodePosAddress[currNode->nWidth])
			{
				(reinterpret_cast <Node *> (m_pNodePosAddress[currNode->nWidth]))->pVertical = currNode;
				m_pNodePosAddress[currNode->nWidth] = currNode;
			}
			else
			{
				m_pNodePosAddress[currNode->nWidth] = currNode;
			}
		}

		else
		{
			if (m_pNodeNegAddress[abs(currNode->nWidth)])
			{
				(reinterpret_cast <Node *> ((m_pNodeNegAddress[abs(currNode->nWidth)])))->pVertical = currNode;
				m_pNodeNegAddress[abs(currNode->nWidth)] = currNode;
			}
			else
			{
				m_pNodeNegAddress[abs(currNode->nWidth)] = currNode;
			}
		}

		return 0;
	}

	int LevelOrder(Node* currNode)
	{
		std::cout << "Doing Level Order" << endl;
		queue <Node*> traversalQueue;
		traversalQueue.push(currNode);
		while (!traversalQueue.empty())
		{
			currNode = traversalQueue.front();

			AddVerticalNode(currNode);
			if (currNode->pFirst)
			{
				(currNode->pFirst)->nWidth = currNode->nWidth - 1;

				if (m_nMinWidth > (currNode->pFirst)->nWidth)
				{
					m_nMinWidth = (currNode->pFirst)->nWidth;
				}
				traversalQueue.push(currNode->pFirst);
			}

			if (currNode->pRight)
			{
				(currNode->pRight)->nWidth = currNode->nWidth + 1;

				if (m_nMaxWidth < (currNode->pRight)->nWidth)
				{
					m_nMaxWidth = (currNode->pRight)->nWidth;
				}

				traversalQueue.push(currNode->pRight);
			}

			traversalQueue.pop();

		}
		return 0;
	}

	void PrintVerticalOrder(const Node* node) const
	{
		for (int i = 0; i < 50; i++)
		{
			m_pNodePosAddress[i] = m_pNodeNegAddress[i] = 0;
		}
		VerticalOrder(node);

		for (int i = 0; i <= m_nMaxWidth; i++)
		{
			cout << "printing Vertical" << endl;
			PrintVertical(m_pNodePosAddress[i]);
		}

		for (int i = 1; i <= abs(m_nMinWidth); i++)
		{
			cout << "printing Vertical" << endl;
			PrintVertical(m_pNodeNegAddress[i]);
		}

	}

	void Visit(const Node * CurNode) const
	{
		std::cout << CurNode->nData << std::endl;
	}

	void InOrder(const Node* node) const
	{
		if (node)
		{
			InOrder(node->pFirst);
			Visit(node);
			InOrder(node->pRight);
		}
	}

	void PreOrder()
	{
	}

	void Postorder()
	{
	}

	void AddNode(int nData)
	{
		if (!m_pRoot)
		{
			AddRoot(nData);
			return;
		}

		Node* CurNode = m_pRoot;
		Node* NewNode = new Node(nData);
		bool bAdded = false;
		while (!bAdded)
		{
			if (CurNode->nData > nData)
			{
				if ((CurNode->pFirst))
				{
					CurNode = CurNode->pFirst;
				}
				else
				{
					CurNode->pFirst = NewNode;
					bAdded = true;
				}
			}
			else
			{
				if (CurNode->pRight)
				{
					CurNode = CurNode->pRight;
				}
				else
				{
					CurNode->pRight = NewNode;
					bAdded = true;
				}
			}

		}
	}


private:
	void CreateVertical(const Node* node) const
	{
		if (node->nWidth >= 0)
		{
			if (!m_pNodePosAddress[node->nWidth])
			{
				m_pNodePosAddress[node->nWidth] = const_cast <Node*> (node);
			}
		}
		else
		{
			if (!m_pNodeNegAddress[abs(node->nWidth)])
			{
				m_pNodeNegAddress[abs(node->nWidth)] = const_cast <Node*> (node);
			}
		}
	}

	void VerticalOrder(const Node* node) const
	{
		if (node)
		{
			CreateVertical(node);
			VerticalOrder(node->pFirst);
			VerticalOrder(node->pRight);
		}
	}

	void PrintVertical(const Node* node) const
	{
		if (node)
		{
			Visit(node);
			PrintVertical(node->pVertical);
		}
	}

	void AddRoot(int nData)
	{
		m_pRoot = new Node(nData);

		m_pRoot->nData = nData;
		m_pRoot->pFirst = nullptr;
		m_pRoot->pRight = nullptr;
	}
};
