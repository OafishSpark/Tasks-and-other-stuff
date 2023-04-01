// AceOfSpades.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <array>
#include "Names.h"
#include "BlackJack.h"

int main()
{
	//deck initialization
	std::array<Card, 52> deck;
	int index{ 0 };
	for (int suit = 0; suit < static_cast<int>(SUIT_LENGTH); ++suit)
	{
		for (int rank = 0; rank < static_cast<int>(RANK_LENGTH); ++rank)
		{
			deck[index].suit = static_cast<CardSuit>(suit);
			deck[index].rank = static_cast<CardRank>(rank);
			++index;
		}
	}
	printDeck(deck);
	//suffling it
	suffleDeck(deck);
	//printDeck(deck);
	while (true)
	{
		if (playBlackJack(deck))
		{
			std::cout << "Congrats! You Win!\n\n";
		}
		else
		{
			std::cout << "You lost.\n\n";
		}
		std::cout << "Another round?(print y/n)\n";
		char com = '?';
		while ((com != 'y') && (com != 'n'))
		{
			std::cin >> com;
			std::cin.ignore(255, '\n');
		}
		if (com == 'n')
		{
			break;
		}
	}
	std::cout << "This is the End, FoLkS!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

