#pragma once

enum CardSuit
{
	HEARTS = 0,
	TILES,
	CLUBS,
	SPADES,
	SUIT_LENGTH
};

enum CardRank
{
	RANK2 = 0,
	RANK3,
	RANK4,
	RANK5,
	RANK6,
	RANK7,
	RANK8,
	RANK9,
	RANK10,
	VALET,
	DAME,
	KING,
	ACE,
	RANK_LENGTH
};

struct Card
{
	CardRank rank;
	CardSuit suit;
	/*Card(CardRank cr, CardSuit cs)
	{
		rank = cr;
		suit = cs;
	}*/
};