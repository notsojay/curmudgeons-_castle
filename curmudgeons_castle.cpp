#include <iostream>
#include <stdexcept>
#include <ctime>
#include <climits>

#include "castle.h"

#define WINDOWS false

void printGreetingMessage();
Status startGame(Castle &);
Status getStatus(Castle &);
void seedRandRange(unsigned int seed = time(NULL));
template <typename T>
T getUserInput(const std::string &prompt);
char toUper(const char &symbol);
void clearScreen();
void clearInstream();

int main(int argc, char *argv[])
{
	seedRandRange();
	Castle *player = new Castle();
	Status playerStatus = SURVIVE;
	printGreetingMessage();
	do
	{
		try
		{
			playerStatus = startGame(*player);
		}
		catch (std::out_of_range &oor)
		{
			clearInstream();
			clearScreen();
			std::cout << oor.what() << std::endl;
			continue;
		}
		catch (std::invalid_argument &ia)
		{
			clearInstream();
			clearScreen();
			std::cout << ia.what() << std::endl;
			continue;
		}
	} while (playerStatus == SURVIVE || playerStatus == CARRYING);

	delete player;
	player = nullptr;
	return 0;
}

void printGreetingMessage()
{
	std::cout << "Welcome to the Curmudgeon's Castle" << std::endl;
}

Status startGame(Castle &player)
{
	char userInput = '\0';
	static Status playerStatus;

	std::cout << player << std::endl;
	if (playerStatus == CARRYING)
		std::cout << "You are carrying your wife!" << std::endl;
	userInput = toUper(getUserInput<char>("Your move [N,S,W,E,P,C]: "));
	switch (userInput)
	{
	case 'N':
		player.move('N');
		break;
	case 'S':
		player.move('S');
		break;
	case 'W':
		player.move('W');
		break;
	case 'E':
		player.move('E');
		break;
	case 'P':
		player.move('P');
		break;
	case 'C':
		player.move('C');
		break;
	default:
		throw std::invalid_argument("The value you entered is invalid!");
	}
	playerStatus = getStatus(player);
	if (playerStatus == DEATH)
	{
		clearInstream();
		clearScreen();
		std::cout << player << std::endl;
		std::cout << "Unfortunately, the guard killed you!" << std::endl;
		return DEATH;
	}
	else if (playerStatus == CARRYING)
	{
		clearInstream();
		clearScreen();
		return CARRYING;
	}
	else if (playerStatus == VICTORY)
	{
		clearInstream();
		clearScreen();
		std::cout << player << std::endl;
		std::cout << "You successfully escaped the castle with your wife!" << std::endl;
		return VICTORY;
	}
	clearInstream();
	clearScreen();
	return SURVIVE;
}

Status getStatus(Castle &player)
{
	switch (player.judgeHeroStatus())
	{
	case DEATH:
		return DEATH;
	case VICTORY:
		return VICTORY;
	case CARRYING:
		return CARRYING;
	case SURVIVE:
		return SURVIVE;
	}
}

void seedRandRange(unsigned int seed)
{
	srand(seed);
}

template <typename T>
T getUserInput(const std::string &prompt)
{
	T input;
	std::cout << prompt;
	std::cin >> input;
	return input;
}

char toUper(const char &symbol)
{
	return (symbol >= 'a' && symbol <= 'z') ? symbol - 'a' + 'A' : symbol;
}

void clearScreen()
{
	if (WINDOWS)
	{
		system("CLS");
	}
	else
	{
		system("clear");
	}
}

void clearInstream()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}