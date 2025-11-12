/*
 card.h
 --------------
 Layne Locovare
 --------------
 11/11/2025
*/

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

// declare the shuffleCards function
vector<Card> createCards();
vector<Card> shuffleCards();
vector<Player> splitCards();

std::ostream& operator<<(std::ostream& os, const Card& card);

#endif
