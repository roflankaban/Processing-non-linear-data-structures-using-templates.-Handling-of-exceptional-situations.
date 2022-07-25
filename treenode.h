#ifndef TREENODE_H

#define TREENODE_H



//Prototype class Tree

template<class NODETYPE>

class Tree;



/*Declaring an object for a binary tree node using

a binary tree template*/

template<class NODETYPE>

class TreeNode

{

	/*Declaring a Tree class as friendly to a given class,

    which will give the Tree class access to private class data*/

	//TreeNode (*leftPtr,*rightPtr,	data)

	friend class Tree<NODETYPE>;



public:

	TreeNode(const NODETYPE&);//constructor

	NODETYPE getData() const; //Returning data

private:

	TreeNode * leftPtr;		  // Pointer to the left child node

	NODETYPE data;				  //Value in the node of the tree

	TreeNode *rightPtr;		  //Pointer to the right child node



};



/*The constructor sets the initial value of the node (first

there will be a root) and null pointers to the left and right

subtrees*/



template<class NODETYPE>

TreeNode<NODETYPE>::TreeNode(const NODETYPE& d)

{

	data = d;

	leftPtr = rightPtr = NULL;



}



//Returning a copy of the data values

template<class NODETYPE>

NODETYPE TreeNode<NODETYPE>::getData() const

{

	return data;

}



#endif

