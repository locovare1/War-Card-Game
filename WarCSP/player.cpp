#include <iostream>
#include "card.hpp"

vector<Player> splitCards()
{
  vector<Card> original_vector = shuffleCards();
  size_t half_size = original_vector.size() / 2;

  vector<Card> first_half(original_vector.begin(), original_vector.begin() + half_size);
  vector<Card> second_half(original_vector.begin() + half_size, original_vector.end());

  Player player1;
  player1.name = "Player1";
  player1.amountOfCards = half_size;
  player1.cards = first_half;

  Player player2;
  player2.name = "Player2";
  player2.amountOfCards = half_size;
  player2.cards = second_half;

  vector<Player> allPlayers;
  allPlayers.push_back(player1);
  allPlayers.push_back(player2);

  return allPlayers;
}