/* 
Number Converter
Converts a numerical numbers to a text numbers up to 999,999,999.
Megan Elisan
*/


#include <iostream>
#include <string>

using namespace std;

string numConvert(int targetNum);
int digitCount(int numToCount);
string oneDigit(int x);
string twoDigit(int x);
string twoDigitTeen(int x);
string digitSplit(int x);
string hundred(int x);
string thousand(int x);
string million(int x);


int main()
{
	int oNum;
	string textNum;
	bool exit;

	exit = false;

	while (!exit)
	{
		cout << "Please enter a number to convert\n\n";
		cin >> oNum;

		textNum = numConvert(oNum);


		cout << "\n\n" << textNum << "\n\n";

	}



	cin.get();
	cin.ignore();
	return 0;
}


int digitCount(int x) // Counts the number of digits to determine number size
{
	int numCount;
	numCount = 0;

	for (; x != 0; x /= 10, numCount++);

	return numCount;
	
}

string numConvert(int x) // Sends number to correct path depending on how large it is
{
	int digits = digitCount(x);

	int numberIdentify = x / 10;
	string secondDigitWord;
	string firstDigitWord;

	if (digits == 1)
	{
		secondDigitWord = oneDigit(x);
	}
	else if (digits == 2)
	{
		if (numberIdentify == 1)
		{
			secondDigitWord = twoDigitTeen(x);			
		}
		else
		{
			secondDigitWord = twoDigit(x);			
		}
	}
	else if (digits == 3)
	{
		secondDigitWord = hundred(x);		
	}
	else if (digits > 3 && digits < 7)
	{
		secondDigitWord = thousand(x);
	}
	else
	{
		secondDigitWord = million(x);
	}

	return secondDigitWord;

}

string oneDigit(int x)
{
	if (x == 0)
	{
		return "zero";
	}
	
	else if (x == 1)
	{
		return "one";
	}
	else if (x == 2)
	{
		return "two";
	}
	else if (x == 3)
	{
		return "three";
	}
	else if (x == 4)
	{
		return "four";
	}
	else if (x == 5)
	{
		return "five";
	}
	else if (x == 6)
	{
		return "six";
	}
	else if (x == 7)
	{
		return "seven";
	}
	else if (x == 8)
	{
		return "eight";
	}
	else //if (x == 9)
	{
		return "nine";
	}
	
}

string twoDigitTeen(int x)
{
	if (x == 10)
	{
		return "ten";
	}
	else if (x == 11)
	{
		return "eleven";
	}
	else if (x == 12)
	{
		return "twelve";
	}
	else if (x == 13)
	{
		return "thirteen";
	}
	else if (x == 14)
	{
		return "fourteen";
	}
	else if (x == 15)
	{
		return "fifteen";
	}
	else if (x == 16)
	{
		return "sixteen";
	}
	else if (x == 17)
	{
		return "seventeen";
	}
	else if (x == 18)
	{
		return "eighteen";
	}
	else //if (x == 19)
	{
		return "nineteen";
	}

	
}

string twoDigit(int x)
{

	int numberIdentify = x / 10;
	string secondDigitWord;
	string firstDigitWord;


	if (numberIdentify == 2)
	{
		secondDigitWord = "twenty";
	}
	else if (numberIdentify == 3)
	{
		secondDigitWord = "thirty";
	}
	else if (numberIdentify == 4)
	{
		secondDigitWord = "fourty";
	}
	else if (numberIdentify == 5)
	{
		secondDigitWord = "fifty";
	}
	else if (numberIdentify == 6)
	{
		secondDigitWord = "sixty";
	}
	else if (numberIdentify == 7)
	{
		secondDigitWord = "seventy";
	}
	else if (numberIdentify == 8)
	{
		secondDigitWord = "eighty";
	}
	else if (numberIdentify == 9)
	{
		secondDigitWord = "ninety";
	}

	if (x == numberIdentify * 10)
	{
		return secondDigitWord;
	}
	else
	{
		firstDigitWord = oneDigit(x - (numberIdentify * 10));

		string fullWord = secondDigitWord.append(" ");
		fullWord = fullWord.append(firstDigitWord);
		return fullWord;
	}

}
	

string hundred(int x)
{
	int hundredValue;
	string whichHundred;
	string hundredWord;
	hundredValue = x / 100;
	whichHundred = oneDigit(hundredValue);

	hundredWord = whichHundred.append(" hundred");

	if (x % 100 != 0) 
	{
		int removeHundo = x - (hundredValue * 100);
		hundredWord.append(" ");
		hundredWord.append(numConvert(removeHundo));
	}

	return hundredWord;
}


string thousand(int x)
{
	int whichThousand;
	int thousandValue;
	int getHundred;
	string hundredWord;
	string thousandWord;
	string addThousand;

	getHundred = 0;

	addThousand = " thousand ";

	thousandValue = x / 1000;
	
	whichThousand = digitCount(thousandValue);

	if (whichThousand == 1)
	{
		
		
		thousandWord = numConvert(x / 1000);
		thousandWord.append(addThousand);


		if (x % 1000 != 0)
		{
			getHundred = thousandValue * 1000;
			hundredWord = numConvert(x - getHundred);

			thousandWord.append(hundredWord);			
		}

		return thousandWord;
		
	}
	else if (whichThousand == 2)
	{

		thousandWord = numConvert(x / 1000);
		thousandWord.append(addThousand);

		if (x % 10000 != 0)
		{
			getHundred = thousandValue * 1000;
			hundredWord = numConvert(x - getHundred);

			thousandWord.append(hundredWord);
		}

		return thousandWord;
	}
	else
	{
		thousandWord = numConvert(x / 1000);
		thousandWord.append(addThousand);

		if (x % 100000 != 0)
		{
			getHundred = thousandValue * 1000;
			hundredWord = numConvert(x - getHundred);

			thousandWord.append(hundredWord);
		}

		return thousandWord;
	}


	return thousandWord;
}
string million(int x)
{
	int whichMillion;
	int thousandValue;
	int millionValue;
	int getThousand;
	string hundredWord;
	string thousandWord;
	string millionWord;
	string addThousand;
	string addMillion;

	getThousand = 0;

	addMillion = " million ";

	millionValue = x / 1000000;

	whichMillion = digitCount(millionValue);

	if (whichMillion == 1)
	{


		millionWord = numConvert(x / 1000000);
		millionWord.append(addMillion);


		if (x % 1000000 != 0)
		{
			getThousand = millionValue * 1000000;
			thousandWord = numConvert(x - getThousand);

			millionWord.append(thousandWord);
		}

		return millionWord;

	}
	else if (whichMillion == 2)
	{

		millionWord = numConvert(x / 1000000);
		millionWord.append(addThousand);

		if (x % 10000000 != 0)
		{
			getThousand = millionValue * 10000000;
			thousandWord = numConvert(x - getThousand);

			millionWord.append(thousandWord);
		}

		return millionWord;
	}
	else
	{
		millionWord = numConvert(x / 1000000);
		millionWord.append(addThousand);

	if (x % 100000000 != 0)
	{
		getThousand = millionValue * 100000000;
		thousandWord = numConvert(x - getThousand);

		millionWord.append(thousandWord);
	}

	return millionWord;
	}


	return millionWord;
}
