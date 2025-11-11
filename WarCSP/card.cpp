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

vector<int> shuffleCards(int size, int min, int max)
{
  random_device rd; // create a random device to get a random seed for the generator
  default_random_engine engine(rd()); // init the dre with the generated seed
  uniform_int_distribution<int> dist(min, max); // define a uid to generate numbers within the range (1, 52)

  auto generateNumber = [&]() { return dist(engine); }; // make a lambda function that calls the uid using the engine to produce a random number

  vector<int> random_numbers(size); // make a vector of integers with the predefined size

  generate(random_numbers.begin(), random_numbers.end(), generateNumber);

  return random_numbers;
}

vector<Card> createCards()
{
  vector<Card> deck; // make a vector for all the cards in the deck

  const int minId = 1;
  const int maxId = 52;

  string nameList[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
  string shapeList[] = { "Hearts", "Clubs", "Spades", "Diamonds" };
  int valueList[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
  vector<int> idList;

  for (int i = minId; i <= maxId; i++)
  {
    idList.push_back(i); // put whatever value i is at the time and push it to the end of the vector
  }
}