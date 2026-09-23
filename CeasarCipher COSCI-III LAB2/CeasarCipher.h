//Elizabeth Fanton
//Lab 2 COSCI  2436 COSCI-III 9/21/26
// 
//using count, replace, adjacent_find
#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include <vector>
#include <algorithm>

using namespace std;

class CeasarCipher
{
private:
	string plainText;
	int shiftNum;

public:
	//setters
	void setplainText();
	void setshiftNum();

	//getters
	string getplainText();
	int getshiftNum();

	//fucntion
	void ceasarCipher();

};

