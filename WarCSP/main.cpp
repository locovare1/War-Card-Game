/*
 src/main.cpp
 --------------
 Layne Locovare
 --------------
 11/11/2025
*/

#include <iostream>
#include "card.hpp"

using std::vector, std::string;

int main()
{
  Card exampleCard;
  exampleCard.name = "Ace";
  exampleCard.shape = "Hearts";
  exampleCard.value = 1;
  exampleCard.id = 1;

  std::cout << "Created card: " << exampleCard.name << " of " << exampleCard.shape << std::endl;

  // We can call the function declared in card.h and defined in card.cpp
  std::vector<int> shuffled_deck_ids = shuffleCards(52, 1, 52);

  std::cout << "First 5 shuffled card IDs:" << std::endl;
  for (int i = 0; i < 5; ++i) {
    std::cout << shuffled_deck_ids[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}