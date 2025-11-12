/*
 src/card.cpp
 --------------
 Layne Locovare
 --------------
 11/11/2025
*/

#include <iostream>
#include <algorithm>
#include <random>

#include "card.hpp"

using std::vector, std::random_device, std::default_random_engine, std::uniform_int_distribution;

int getCardValue(Card card, string name, int v);

/*
 ace of hearts = 1
 2 of hearts = 2
 ... up to king of hearts which is 13

 ace of hearts = 14
 2 of hearts = 155
 ... up to king of spades which is 26

 ace of hearts = 27
 2 of hearts = 28
 ... up to king of diamonds which is 39

 ace of hearts = 40
 2 of hearts = 41
 ... up to king of clubs which is 52
*/

vector<Card> createCards()
{
  vector<Card> deck; // make a vector for all the cards in the deck

  const int minId = 1;
  const int maxId = 52;

  vector<string> nameList = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
  vector<string> shapeList = { "Hearts", "Clubs", "Spades", "Diamonds" };
  int valueList[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
  vector<int> idList;
  int cardId = 0;

  for (int i = minId; i <= maxId; i++)
  {
    idList.push_back(i); // put whatever value i is at the time and push it to the end of the vector
  }

  // create all 52 cards
  
  for (int s = 0; s < shapeList.size(); ++s)
  {
    for (int v = 0; v < nameList.size(); ++v)
    {
      Card newCard;
      newCard.name = nameList[v] + " of " + shapeList[s];
      newCard.shape = shapeList[s];
      newCard.value = getCardValue(newCard, nameList[v], v);
      newCard.id = ++cardId;

      std::cout << newCard.name << " Value: " << newCard.value << " ID: " << newCard.id << std::endl;
    }
  }

  return deck;
}

vector<Card> shuffleCards()
{
  vector<Card> deck = createCards();  // makes all 52 cards

  std::random_device rd;
  std::mt19937 engine(rd());

  shuffle(deck.begin(), deck.end(), engine); // shuffles them

  return deck;
}

vector<Card> splitCards()
{
  vector<Card> original_vector = shuffleCards();
  size_t half_size = original_vector.size() / 2;

  vector<Card> first_half(original_vector.begin(), original_vector.begin() + half_size);
  vector<Card> second_half(original_vector.begin() + half_size, original_vector.begin());

  Player player1;
  player1.name = "Player1";
  player1.amountOfCards = half_size;
  player1.cards = first_half;

  Player player2;
  player2.name = "Player2";
  player2.amountOfCards = half_size;
  player2.cards = second_half;
}

int getCardValue(Card card, string name, int v)
{
  if (name == "Ace")
  {
    return card.value = 13;
  }
  else if (name == "King")
  {
    return card.value = 12;
  }
  else if (name == "Queen")
  {
    return card.value = 11;
  }
  else if (name == "Jack")
  {
    return card.value = 10;
  }
  else if (name == "Ten")
  {
    return card.value = 9;
  }
  else if (name == "Nine")
  {
    return card.value = 8;
  }
  else if (name == "Eight")
  {
    return card.value = 7;
  }
  else if (name == "Seven")
  {
    return card.value = 6;
  }
  else if (name == "Six")
  {
    return card.value = 5;
  }
  else if (name == "Five")
  {
    return card.value = 4;
  }
  else if (name == "Four")
  {
    return card.value = 3;
  }
  else if (name == "Three")
  {
    return card.value = 2;
  }
  else if (name == "Two")
  {
    return card.value = 1;
  }

}