/*
 * BST.cpp
 * 
 *  Created on: Apr 10, 2020
 *      Author: Shivam Chauhan and Estevan Bedolla
 */


#include "BST.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

BST::BST() {
	root = NULL;
}
BST::BST(string s, string l) {
	root = new TNode(s,l);
}

bool BST::insert(string s,string l) {
  TNode *add = new TNode(s,l);
  TNode *tmp = root;
  if(tmp == NULL) {
    root = add;
    root->height = 1;
    add->printNode();
    return true;
  }
  else{ 
    while(tmp != NULL) {
      // left side
      if(s < tmp->data->abbr) { 
        if(tmp->left == NULL) {
          tmp->left = add;
          tmp->left->parent = tmp;
          setHeight(add);
          return true;
        }
        else {
          tmp = tmp->left;
        }
      }
        //add right side
      else if(s > tmp->data->abbr) { 
        if(tmp->right == NULL) {
          tmp->right = add;
          tmp->right->parent = tmp;
          setHeight(add);
          return true;
        }
        else {
          tmp = tmp->right;
        }
      }
      else{
        if(tmp->data->abbr == s) {
        return false;
      }
      }
      }
    }
  
}


TNode *BST::find(string s) {
  if(root == NULL) {
    return NULL;
  }
  else {
    TNode *tmp = root;
    while(true) {
      if(tmp->data->abbr == s) {
        return tmp;
      }
      else{
        if(s > tmp->data->abbr ) { // checks right
          if(tmp->right == NULL) {
            return NULL;
          }
          tmp = tmp->right;
        }
        if(s < tmp->data->abbr) { // checks left
          if(tmp->left == NULL) {
            return NULL;
          }
          tmp = tmp->left;
        }
      }
    }
  }

}



void BST::setHeight(TNode *tmp) {
 tmp->height = 1;
  int height = 2; // height was intially 1
  while(tmp != root) {
    tmp = tmp->parent; //goes up the free
    if(tmp->height >= height) { //max height
      return;
    }
    tmp->height = height; //sets height
    height++;
  }
 
}
void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}
void BST::printTreeIO(TNode *tmp) {
  if(tmp == NULL) {
    return;
  }
  else {
    printTreeIO(tmp->left);
    tmp->printNode();
    printTreeIO(tmp->right);
  }
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}
void BST::printTreePre(TNode *tmp) {
 if(tmp == NULL) {
    return;
  }
  else {
    tmp->printNode();
    printTreePre(tmp->left);
    printTreePre(tmp->right);
  }
}

void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void BST::printTreePost(TNode *tmp) {
if(tmp == NULL) {
    return;
  }
  else {
    printTreePost(tmp->left);
    printTreePost(tmp->right);
    tmp->printNode();
  }
}
void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();  
		delete(tmp);
	}
}

TNode *BST::removeNoKids(TNode *tmp) {
  if(tmp != root) {
    if(tmp->parent->left == tmp) {
      tmp->parent->left = NULL;
    }
    else {
      tmp->parent->right = NULL;
    }
  }
  else {
    root = NULL;
  }
  return tmp;
}
TNode *BST::removeOneKid(TNode *tmp,bool leftFlag) {
  TNode *kid;
  if(leftFlag) {
    kid = tmp->left;
  }
  else {
    kid = tmp->right;
  }
  if(tmp != root) {
    if(tmp->parent->left == tmp) {
      tmp->parent->left = kid;
    }
    else {
      tmp->parent->right = kid;
    }
  }
  else {
    root = kid;
  }
  return tmp;
  }
  
TNode *BST::remove(string s) {
  TNode *removednode = find(s);
  if(removednode->left != NULL & removednode->right != NULL) {
    TNode *tmp = removednode->left;
    while(tmp->right != NULL) {
      tmp = tmp->right;
      }
    removednode->data = tmp->data; // copy's data
    if(tmp->left == NULL) {
      removeNoKids(tmp);
    }
    else if(tmp->right == NULL) {
      removeOneKid(tmp,true);
    }
    else {
      removeOneKid(tmp, false);
    }
    }
  else if( removednode->right == NULL && removednode->left != NULL) { // checks left
    removeOneKid(removednode, true);
  }
  else if( removednode->left == NULL && removednode->right != NULL) { // checks right
    removeOneKid(removednode, false);
  }
  else {
    removeNoKids(removednode);
  }
  return removednode;
  }