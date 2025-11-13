#include <iostream>
#include <vector>
#include "card.hpp"

using namespace std;

Player* player1 = nullptr;
Player* player2 = nullptr;

vector<Player*> splitCards()
{
  vector<Card> original_vector = shuffleCards();
  size_t half_size = original_vector.size() / 2;

  vector<Card> first_half(original_vector.begin(), original_vector.begin() + half_size);
  vector<Card> second_half(original_vector.begin() + half_size, original_vector.end());

  player1 = new Player();
  player1->name = "Player1";
  player1->amountOfCards = half_size;
  player1->cards = first_half;

  player2 = new Player();
  player2->name = "Player2";
  player2->amountOfCards = half_size;
  player2->cards = second_half;

  vector<Player*> allPlayers;
  allPlayers.push_back(player1);
  allPlayers.push_back(player2);

  return allPlayers;
}

vector<Card> Player1Wins(Card topCard1, Card topCard2, vector<Card>& player1Cards, vector<Card>& player2Cards)
{
  std::cout << "Player1 Wins!" << std::endl;

  player1Cards.push_back(stack.back());
  stack.pop_back();

  player1Cards.push_back(stack.back());
  stack.pop_back();

  cin.get();

  return player1->cards;
}

vector<Card> Player2Wins(Card topCard1, Card topCard2, vector<Card>& player1Cards, vector<Card>& player2Cards)
{
  std::cout << "Player2 Wins!" << std::endl;

  player2Cards.push_back(stack.back());
  stack.pop_back();

  player2Cards.push_back(stack.back());
  stack.pop_back();

  cin.get();

  return player2->cards;
}

vector<Card> War()
{
  return player2->cards;
}