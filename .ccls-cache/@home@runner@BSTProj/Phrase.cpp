/*
 * Phrase.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: Shivam Chauhan and Estevan Bedolla
 */
#include <iostream>
#include <string>
#include "Phrase.hpp"
using namespace std;

Phrase::Phrase(string s, string l) {
	abbr = s;
	meaning = l;
}

Phrase::Phrase() {
	abbr = "";
	meaning = "";
}


