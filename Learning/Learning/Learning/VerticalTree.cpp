#include <set>
#include <functional>
#include <iostream>
#include <ctime>
#include <queue>
#include "BinaryTree.h"
using namespace std;

int main()
{
	
	BinaryTree MyTree;

	MyTree.AddNode(100);
	MyTree.AddNode(50);
	MyTree.AddNode(200);
	MyTree.AddNode(1);
	MyTree.AddNode(-1);
	MyTree.AddNode(400);
	MyTree.AddNode(180);
	MyTree.AddNode(40);
	MyTree.AddNode(60);
	MyTree.AddNode(150);
	MyTree.AddNode(250);

	cout << MyTree.height(MyTree.m_pRoot) << endl;
	//MyTree.InOrder(MyTree.m_pRoot);

	//MyTree.LevelOrder(MyTree.m_pRoot);
	
	
	//MyTree.PrintVerticalOrder(MyTree.m_pRoot);

	return 0;

}