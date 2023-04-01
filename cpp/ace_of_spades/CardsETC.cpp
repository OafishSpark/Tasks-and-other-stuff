#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include <vector>
#include <string>
#include "Names.h"
#include "BlackJack.h"

void printCard(Card card)
{
	char r, s;
	switch (card.rank)
	{
		case RANK2:
		{
			r = '2';
			break;
		}
		case RANK3:
		{
			r = '3';
			break;
		}
		case RANK4:
		{
			r = '4';
			break;
		}
		case RANK5:
		{
			r = '5';
			break;
		}
		case RANK6:
		{
			r = '6';
			break;
		}
		case RANK7:
		{
			r = '7';
			break;
		}
		case RANK8:
		{
			r = '8';
			break;
		}
		case RANK9:
		{
			r = '9';
			break;
		}
		case RANK10:
		{
			r = 'T';
			break;
		}
		case VALET:
		{
			r = 'V';
			break;
		}
		case DAME:
		{
			r = 'D';
			break;
		}
		case KING:
		{
			r = 'K';
			break;
		}
		case ACE:
		{
			r = 'A';
			break;
		}
		default:
		{
			std::cout << "Fuck you\n";
			return;
		}
	}
	switch (card.suit)
	{
		case HEARTS :
		{
			s = 'H';
			break;
		}
		case TILES:
		{
			s = 'T';
			break;
		}
		case CLUBS:
		{
			s = 'C';
			break;
		}
		case SPADES:
		{
			s = 'S';
			break;
		}
		default:
		{
			std::cout << "Fuck you\n";
			return;
		}
	}
	std::cout << r << s;
}

void printDeck(std::array<Card, 52> deck)
{
	for (Card card : deck)
	{
		printCard(card);
		std::cout << " ";
	}
	std::cout << std::endl;
}

void swapCard(Card &a, Card &b)
{
	Card t = a;
	t = a;
	a = b;
	b = t;
}

void suffleDeck(std::array<Card, 52>& deck)
{
	srand(time(0));
	rand();
	for (auto& card : deck)
	{
		swapCard(card, deck[rand() % 52]);
	}
}

int getCardValue(Card card)
{
	switch (card.rank)
	{
	case RANK2:
	{
		return 2;
	}
	case RANK3:
	{
		return 3;
	}
	case RANK4:
	{
		return 4;
	}
	case RANK5:
	{
		return 5;
	}
	case RANK6:
	{
		return 6;
	}
	case RANK7:
	{
		return 7;
	}
	case RANK8:
	{
		return 8;
	}
	case RANK9:
	{
		return 9;
	}
	case RANK10:
	case VALET:
	case DAME:
	case KING:
	{
		return 10;
	}
	case ACE:
	{
		return 11;
	}
	default:
	{
		std::cout << "Fuck you\n";
		return 0;
	}
	}
}

void getCommand(std::string& command)
{
	std::cout << "Enter the command you want to do or help:\n";
	do
	{
		std::cin >> command;
		std::cin.ignore(255, '\n');
		if ((command != "hit") && (command != "stand") && (command != "help"))
		{
			std::cout << "Wronng input! Try again.";
		}
	} 
	while ((command != "hit") && (command != "stand") && (command != "help"));
}

void printHand(std::vector<Card> playersHand, int playersScore)
{
	std::cout << "Hand is: ";
	for (int i = 0; i < playersHand.size(); ++i)
	{
		printCard(playersHand[i]);
		std::cout << " ";
	}
	std::cout << "\nScore is: " << playersScore << std::endl;
}

bool playBlackJack(const std::array<Card, 52>& deck)
{
	const Card* topCardPtr = &deck[1];

	int playerScore{ 0 }, dealerScore{ 0 };

	std::vector<Card> dealersHand = { *(topCardPtr++) };
	dealerScore += getCardValue(dealersHand[0]);

	std::vector<Card> playersHand = { *(topCardPtr++), *(topCardPtr++)};
	playerScore += getCardValue(playersHand[0]) + getCardValue(playersHand[1]);

	std::cout << "\nWelcome to Black Jack Game\n\nYou:\n";
	printHand(playersHand, playerScore);
	std::string command;
	bool ifEnd{ false };
	while (!ifEnd)
	{
		getCommand(command);
		if (command == "hit")
		{
			playersHand.resize(playersHand.size() + 1);
			playersHand[playersHand.size() - 1] = *topCardPtr;
			playerScore += getCardValue(*(topCardPtr++));
			std::cout << "You:\n";
			printHand(playersHand, playerScore);
			if (playerScore > 21)
			{
				std::cout << "Ooops. You gained over 21 points.\n";
				return false;
			}
		}
		else if (command == "stand")
		{
			ifEnd = true;
		}
		else if (command == "help")
		{
			std::cout << " hit -- pick another card and continue the round\n stand -- finish the round\n";
		}
		else
		{
			std::cout << "Something went wrong!\n";
		}
	}
	while (dealerScore < 17)
	{
		dealersHand.resize(dealersHand.size() + 1);
		dealersHand[dealersHand.size() - 1] = *topCardPtr;
		dealerScore += getCardValue(*(topCardPtr++));
		if (dealerScore > 21)
		{
			std::cout << "Dealer:\n";
			printHand(dealersHand, dealerScore);
			std::cout << "Dealer gained over 21 points!\n";
			return true;
		}
	}
	std::cout << "End of the Round!\n";
	std::cout << "Dealer:\n";
	printHand(dealersHand, dealerScore);
	std::cout << "You:\n";
	printHand(playersHand, playerScore);
	if (playerScore > dealerScore)
	{
		return true;
	}
	return false;
}