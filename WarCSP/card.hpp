/*
 card.h
 --------------
 Layne Locovare
 --------------
 11/11/2025
*/

#pragma once

#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

using std::string, std::vector;

// definition of the Card class
class Card
{
public:
  string name;
  string shape;
  int value;
  int id;
};

class Player
{
public:
  string name;
  int amountOfCards;
  vector<Card> cards;
};

// creating thge players
extern Player* player1;
extern Player* player2;

vector<Card> stack;

// declare the shuffleCards function
vector<Card> createCards();
vector<Card> shuffleCards();
vector<Player*> splitCards();

vector<Card> putDownCard(vector<Card> player1Cards, vector<Card> player2Cards);
vector<Card> Player1Wins(Card topCard1, Card topCard2, vector<Card>& player1Cards, vector<Card>& player2Cards);

std::ostream& operator<<(std::ostream& os, const Card& card);

#endif
