/*
 src/main.cpp
 --------------
 Layne Locovare
 --------------
 11/11/2025
*/

#include <iostream>
#include <algorithm>
#include <random>
#include "card.hpp"

using std::vector, std::string;

int main()
{
  // MAIN GAME LOOP
  vector<Card> deck = createCards();  // makes all 52 cards

  std::random_device rd;
  std::mt19937 engine(rd());

  shuffle(deck.begin(), deck.end(), engine); // shuffles them

  while (true)
  {

  }
}