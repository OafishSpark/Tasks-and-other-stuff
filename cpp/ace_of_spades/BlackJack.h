#pragma once

void printCard(Card);

void printDeck(std::array<Card, 52>);

void suffleDeck(std::array<Card, 52>& deck);

int getCardValue(Card);

bool playBlackJack(const std::array<Card, 52>& deck);