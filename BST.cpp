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

}

TNode *BST::find(string s) {

}



void BST::setHeight(TNode *tmp) {

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
		//tmp->printNode();  // for testing, comment back in
		delete(tmp);
	}
}

TNode *BST::removeNoKids(TNode *tmp) {

}
TNode *BST::removeOneKid(TNode *tmp,bool leftFlag) {

}
TNode *BST::remove(string s) {

}

