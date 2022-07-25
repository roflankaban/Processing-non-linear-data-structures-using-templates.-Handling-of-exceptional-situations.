#pragma once

#ifndef TREE_H

#define TREE_H



#include <iostream>

#include "assert.h"

#include "treenode.h"



/*An object declaration for a binary search tree node

using the binary search tree template*/



template<class NODETYPE>

class Tree

{

public:



	Tree();			//Constructor

					//Putting a value in a tree node

	void insertNode(const NODETYPE&);

	void insertNode1(const NODETYPE&);

	void insertNode2(const NODETYPE&);

	//Bypassing the tree in a specified way and printing values in nodes

	void preOrderTraversal() const;

	void preOrderTraversal1() const;

	void preOrderTraversal2() const;

	void KolUzl(void);

private:

	//Declaring a pointer to the root node of a tree

	TreeNode<NODETYPE> *rootPtr1;

	TreeNode<NODETYPE> *rootPtr2;

	TreeNode<NODETYPE> *rootPtr;

	//Placing a node in a tree as the end node

	void insertNodeHelper(TreeNode<NODETYPE> **, const NODETYPE&);

	void preOrderHelper(TreeNode<NODETYPE> *) const;

	void preOrderHelper1(TreeNode<NODETYPE> *) const;

	void preOrderHelper2(TreeNode<NODETYPE> *) const;

	int  KolUzlHelper(TreeNode<NODETYPE> *);

};



//The constructor, initially the tree is declared empty

template<class NODETYPE>

Tree<NODETYPE>::Tree() { rootPtr1 = NULL; rootPtr2 = NULL; rootPtr = NULL; }

//--------------------------

template<class NODETYPE>

void Tree<NODETYPE>::KolUzl(void)

{

	int kol = 0;

	kol = KolUzlHelper(rootPtr);

}



template<class NODETYPE>

int Tree<NODETYPE>::KolUzlHelper(TreeNode<NODETYPE> *ptr)

{

	if (ptr != NULL)

	{

		if ((ptr->leftPtr != NULL) || (ptr->rightPtr != NULL)) kol++;

		KolUzlHelper(ptr->leftPtr);

		KolUzlHelper(ptr->rightPtr);

	};

	return(kol);



}

//----------------------

template<class NODETYPE>

void Tree<NODETYPE>::insertNode1(const NODETYPE& value)

{

	insertNodeHelper(&rootPtr1, value);

}

/*Implementation of the mechanism for inserting a new value into

binary search tree*/

//----------------------

template<class NODETYPE>

void Tree<NODETYPE>::insertNode2(const NODETYPE& value)

{

	insertNodeHelper(&rootPtr2, value);

}

//---------------------

template<class NODETYPE>

void Tree<NODETYPE>::insertNode(const NODETYPE& value)

{

	insertNodeHelper(&rootPtr, value);

}

//---------------------

template<class NODETYPE>

void Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE> ** ptr,

	const NODETYPE& value)

{

	if (*ptr == NULL)

	{

		*ptr = new TreeNode<NODETYPE>(value);

		assert(*ptr != NULL);

	}

	else

		if (value<(*ptr)->data)

			insertNodeHelper(&((*ptr)->leftPtr), value);

		else

			if (value>(*ptr)->data)

				insertNodeHelper(&((*ptr)->rightPtr), value);

			else

				cout << value << " Dub" << endl;

}



//-------------------------

template<class NODETYPE>

void Tree<NODETYPE>::preOrderTraversal1() const

{

	preOrderHelper1(rootPtr1);

}





template<class NODETYPE>

void Tree<NODETYPE>::preOrderHelper1(TreeNode<NODETYPE> *ptr) const

{

	if (ptr != NULL)

	{

		cout << ptr->data << ' ';

		preOrderHelper1(ptr->leftPtr);

		preOrderHelper1(ptr->rightPtr);

	}

}

//----------------------

template<class NODETYPE>

void Tree<NODETYPE>::preOrderTraversal2() const

{

	preOrderHelper2(rootPtr2);

}





template<class NODETYPE>

void Tree<NODETYPE>::preOrderHelper2(TreeNode<NODETYPE> *ptr) const

{

	if (ptr != NULL)

	{

		cout << ptr->data << ' ';

		preOrderHelper2(ptr->leftPtr);

		preOrderHelper2(ptr->rightPtr);

	}

}

//----------------------

template<class NODETYPE>

void Tree<NODETYPE>::preOrderTraversal() const

{

	preOrderHelper(rootPtr);

}





template<class NODETYPE>

void Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE> *ptr) const

{

	if (ptr != NULL)

	{

		cout << ptr->data << ' ';

		preOrderHelper(ptr->leftPtr);

		preOrderHelper(ptr->rightPtr);

	}

}





#endif
