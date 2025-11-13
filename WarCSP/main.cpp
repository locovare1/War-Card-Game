/*
 main.cpp
 --------------
 Layne Locovare
 --------------
 11/11/2025
*/

#include <iostream>

#include "card.hpp"

using std::vector, std::string, std::cout, std::cin;

int main()
{
  cout << "Laynes War Card Game" << std::endl;

  // Create and shuffle cards
  createCards();
  shuffleCards();

  // Get both players
  vector<Player*> players = splitCards();

  Player& player1 = *players[0];
  Player& player2 = *players[1];

  vector<Card>& player1Cards = player1.cards;
  vector<Card>& player2Cards = player2.cards;

  // Main game loop
  while (!player1Cards.empty() && !player2Cards.empty())
  {
    vector<Card> player1Stack = putDownCard(player1Cards, player2Cards);

    int half_size = player1Stack.size() / 2;

    vector<Card> topCards1(player1Stack.begin(), player1Stack.begin() + half_size);
    vector<Card> topCards2(player1Stack.begin() + half_size, player1Stack.end());

    cout << "Player1's card: " << player1Cards.front() << std::endl;
    cout << "Player2's card: " << player2Cards.front() << std::endl;

    if (topCards1.back().value > topCards2.back().value)
    {
      Player1Wins(topCards1.back(), topCards2.back(), player1Cards, player2Cards);
    }

    else if (topCards1.back().value < topCards2.back().value)
    {
      Player1Wins(topCards1.back(), topCards2.back(), player1Cards, player2Cards);
    }
    else
    {
      std::cout << "War!" << std::endl;

      Card player1Card1 = player1Cards[1];
      Card player1Card2 = player1Cards[2];
      Card player1Card3 = player1Cards[3];

      Card player2Card1 = player2Cards[1];
      Card player2Card2 = player2Cards[2];
      Card player2Card3 = player2Cards[3];

      cout << "Player1's next 4 cards: " << "***, ***, ***, " << player1Cards[4] << std::endl;
      cout << "Player2's next 4 cards: " << "***, ***, ***, " << player2Cards[4] << std::endl;

      if (player1Cards[4].value > player2Cards[4].value)
      {
        cout << "Player 1 Wins!" << std::endl;

        player1Cards.push_back(player1Card1);
        player1Cards.push_back(player1Card2);
        player1Cards.push_back(player1Card3);
        player1Cards.push_back(player1Cards[4]);

        player1Cards.push_back(player2Card1);
        player1Cards.push_back(player2Card2);
        player1Cards.push_back(player2Card3);
        player1Cards.push_back(player2Cards[4]);

        player1Cards.erase(player1Cards.begin() + 1, player1Cards.begin() + 5);
        player2Cards.erase(player2Cards.begin() + 1, player2Cards.begin() + 5);
      }
      else if (player1Cards[4].value < player2Cards[4].value)
      {
        cout << "Player 2 Wins!" << std::endl;

        player2Cards.push_back(player1Card1);
        player2Cards.push_back(player1Card2);
        player2Cards.push_back(player1Card3);
        player2Cards.push_back(player1Cards[4]);

        player2Cards.push_back(player2Card1);
        player2Cards.push_back(player2Card2);
        player2Cards.push_back(player2Card3);
        player2Cards.push_back(player2Cards[4]);

        player1Cards.erase(player1Cards.begin() + 1, player1Cards.begin() + 5);
        player2Cards.erase(player2Cards.begin() + 1, player2Cards.begin() + 5);

      }
      else
      {
        cout << "they are the same and ion feel like coding allat" << std::endl;
      }

      cin.get();
    }

    if (player1Cards.size() == 0)
    {
      cout << "Player 2 wins!" << std::endl;
      break;
    }
    else if (player2Cards.size() == 0)
    {
      cout << "Player 1 wins!" << std::endl;
      break;
    }
    else
    {

    }

  }

  return 0;
}