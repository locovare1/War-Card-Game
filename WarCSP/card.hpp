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

// declare the shuffleCards function
vector<int> shuffleCards(int size, int min, int max);
vector<Card> createCards();

#endif
