//Elizabeth Fanton
//Lab 2 COSCI  2436 COSCI-III 9/21/26

#include "CeasarCipher.h"

//setter
void CeasarCipher::setplainText()
{
	//ifstream indata;
	//ofstream outdata;
	//indata.open("C:\\Users\\Elizabeth\\Documents\\COSC - III\\CeasarCipher COSCI - III LAB2");

	//if (indata.fail())
	//{
	//	cout << "file failed to open.";
	//	return -1;//figure out what's wrong with this
	//}
	// char inputString[1000];
	cout << "Enter the message you want encoded (with no spaces): ";//change so that use just call and encrypt a docu.
	cin >> plainText;
}

void CeasarCipher::setshiftNum()
{
	cout << "Enter the key shift: ";
	cin >> shiftNum;
}

//getter
string CeasarCipher::getplainText()
{
	
	return  plainText;

}

int CeasarCipher::getshiftNum()
{
	return shiftNum;
}

//function
void CeasarCipher::ceasarCipher()
{
	//get string
	string stringToConvert = getplainText();
	//converting char to upper case
	for (int upperChar = 0; upperChar < stringToConvert.size(); upperChar++)
		stringToConvert[upperChar] = static_cast<char>(toupper(stringToConvert[upperChar]));//think there might be something wrong here.
	//cout << "testing uppercase conversion: ";
	//for (int i = 0; i < stringToConvert[i]; i++)
		//cout << stringToConvert[i];

	//use a while loop to push_back each character into a vector
	int loopControl = 0;
	vector<char> plainTextVec;
	//cout << endl << "vector size: " << stringToConvert.size() << endl;
	while (loopControl != stringToConvert.size())
	{
		/*vector<char> plainTextVec;*/
		plainTextVec.push_back(stringToConvert[loopControl++]);//pushes string into the vector
	}
	//cout << endl << "Vector output: ";
	//create test ouput
	//for (int printNum = 0; printNum < plainTextVec.size(); printNum++)
	//cout << plainTextVec[printNum] << " ";
	//return plainTextVec

	/*----------------------------------------------------------------------*/
	//Ceasar Cipher encryption
	//get shift number
	setshiftNum();
	int keyShift = getshiftNum();
	cout << "keyshift: " << keyShift;
	for (int i = 0; i < stringToConvert.size(); i++)
		//convert vec to cipherText
		stringToConvert[i] = char(((int(stringToConvert[i]) - 65 + keyShift) % 26) + 65);

	cout << " encrypted message: ";

	cout << stringToConvert << endl;//encrypted message output

	//Now use count function to count how many times a letter apppers in the encrypted message
	//output the letter that appears most in frequency analysis

	//convert char to ascii value
	for (int i = 0; i < 26; i++)
	{
		//char(i + 65);
		int alphaArray[26];
		alphaArray[i] = count(stringToConvert.begin(), stringToConvert.end(), char(i + 65));
		cout << "The letter " << char(i + 65) << " appears " << alphaArray[i] << " times in the encrypted message." << endl;
	}

	//now use replace to put new char values into the places
	char myLetter;
	for (int i = 0; i < 26; i++)
	{
		//prompt user for substitution
		cout << "Enter your substitution for the letters: ";
		cin >> myLetter;//std::replace(myVec.begin(),myVec.end(),myVec.begin()+1, myLetter);

		int alphaArray[26];
		alphaArray[i] = count(stringToConvert.begin(), stringToConvert.end(), char(i + 65));
		vector<int> myVec;
		myVec.push_back(alphaArray[i]);
		std::replace(myVec.begin(), myVec.end(), alphaArray[i], static_cast<int>(myLetter));//convert int myletter to char
		cout << "The letter " << char(i + 65) << " is replaced with '" << myLetter << "' in the encrypted message." << endl;
	}
	//uses adjacent to see if there are adjacent letters
	for (int i = 0; i < 26; i++)
	{
		adjacent_find(stringToConvert.begin(), stringToConvert.end(), char(i + 65));
		cout << "The letter " << char(i + 65) << " is a double letter combo in the encrypted message." << endl;
	}
}

//now have vector, encrypt vector using CeasarCipher function
//first encrypt plaintext
//function
//void CeasarCipher::ceasarCipher()//encrypts plaintext usin
//{
//	//get shift number 
//	int keyShift = getshiftNum();
//	//get vector of plaintext
//	stringToVec();
//	//convert char in vec to integers?
//	for (int i = 0; i < stringToVec().size(); i++)
//
//	//cipherText[i] = char(((int(stringToVec) - 65 + myCipher) % 26) + 65)
//}
//
////now use count function and push_back cipherText to a new? vector.
