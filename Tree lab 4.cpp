// Ivanov Igor 10-2-IIT

#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;
const int n = 15;//amount of elements
int kol, m, i;
int main()
{
	//creating a class object Tree<int>
	Tree<int> intTree;
	int intVal;
	cout << "enter m" << endl;
	cin >> m;
	cout << "Input 15 integer number: " << endl;
	for (int i = 0; i<n; i++) //filling trees
	{
		cin >> intVal;
		{
			intTree.insertNode(intVal);
			if (intVal <= m) intTree.insertNode1(intVal);
			else       intTree.insertNode2(intVal);
		}
	}
	//Outputting the values of the nodes of the binary search tree by direct
	cout << endl << "tree";
	intTree.preOrderTraversal();
	cout << endl << "tree 1" << endl;
	intTree.preOrderTraversal1();
	cout << endl;
	cout << "tree 2" << endl;
	intTree.preOrderTraversal2();
	kol = 0;
	intTree.KolUzl();
	cout << endl << "number of nodes " << kol;
	cout << endl << " number of leaves " << n - kol << endl;
	system("pause");
	return 0;
}
/*enter m
4
Input 10 integer number:
9
8
7
5
4
6
1
2
3
33

tree9 8 7 5 4 1 2 3 6 33
tree 1
4 1 2 3
tree 2
9 8 7 5 6 33
number of nodes 7
number of leaves 3
Для продолжения нажмите любую клавишу . . .*/