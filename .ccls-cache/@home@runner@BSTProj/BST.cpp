/*
 * BST.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: 13027
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

}



void BST::setHeight(TNode *tmp) {
/*  tmp->height = 1;
  int height = 2; // height was intially 1
  while(tmp != root) {
    tmp = tmp->parent; //goes up the free
    if(tmp->height >= height) { //max height
      return;
    }
    tmp->height = height; //sets height
    height++;
  }
 */ 
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
    printTreeIO(tmp->left);
    printTreeIO(tmp->right);
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
    printTreeIO(tmp->left);
    printTreeIO(tmp->right);
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

}
TNode *BST::removeOneKid(TNode *tmp,bool leftFlag) {

}
TNode *BST::remove(string s) {

}

