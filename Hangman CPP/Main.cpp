#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "CLS.h"

void CheckGuess(std::string SelectedWord, std::string &GuessedWord, std::string Guess, int &Attempts);

int main()
{
	srand((int)time(NULL));

	std::vector<std::string> WordList = 
	{   "burger", 
		"pizza", 
		"ball", 
		"skyscraper", 
		"nightingale", 
		"heart", 
		"warrior", 
		"bandage", 
		"football",
		"laptop",
		"apple",
		"memory",
		"calendar",
		"paper",
		"notebook",
		"cardboard",
		"rainbow",
		"book",
		"cookie",
		"internet",
		"tissue",
		"box",
		"map",
		"microphone",
		"pen",
		"pencil",
		"telephone",
		"painting",
		"highway",
		"diary",
	};

	int WordGen = rand() % WordList.size();
	std::string SelectedWord = WordList[WordGen];
	std::string GuessedLetters;

	int SpacesToFillGuessed = SelectedWord.length();

	while (SpacesToFillGuessed != 0)
	{
		GuessedLetters += "_";
		SpacesToFillGuessed--;
	}

	int AttemptsLeft = 8;

	std::cout << "Multi-word support not yet implemented." << std::endl;

	while (true)
	{
		std::string Input = "";
		for (int i = 0; i < (int)GuessedLetters.length(); i++)
		{
			std::cout << GuessedLetters[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Enter a letter to guess. Type exit to exit the game." << std::endl;
		std::cout << "Attempts left: " << AttemptsLeft << std::endl;
		std::cout << std::endl;
		std::cout << "© Meraj Ahmed" << std::endl;
		std::getline(std::cin, Input);
		for (char &c : Input)
			c = tolower(c);
		if (Input.compare("exit") == 0)
			return 0;

		CheckGuess(SelectedWord, GuessedLetters, Input, AttemptsLeft);
		cls();
		if (AttemptsLeft <= 0)
		{
			std::cout << "Sorry, you have run out of attempts." << std::endl;
			getchar();
			return 0;
		}
		if (!(GuessedLetters.find("_") != std::string::npos))
		{
			std::cout << "Congratulations! You have won!" << std::endl;
			getchar();
			return 0;
		}
	}

	return 0;
}

void CheckGuess(std::string SelectedWord, std::string &GuessedWord, std::string Guess, int &Attempts)
{
	if (SelectedWord == Guess)
	{
		GuessedWord = SelectedWord;
	}
	if (SelectedWord.find(Guess) != std::string::npos)
	{
		int i = 0;
		for (i = 0; i < (int)GuessedWord.length(); i++)
		{
			if (SelectedWord[i] == Guess[0])
			{
				GuessedWord[i] = Guess[0];
			}
		}
	}
	else
	{
		Attempts--;
	}
}