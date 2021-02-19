#include <iostream>
#include <random>
#include "util.h"
#include "player.h"
#include "monster.h"

int main() {
  std::cout << "Welcome to this way cool RPG" << std::endl;
  
  std::string name;
  std::cout << "Enter your name" << std::endl;
  std::cin >> name;
  
  Race playerRace = promptForRace();

  Player player(name, playerRace, 10);
  
//   Player player("Bob", Elf, 10);
  
  std::random_device randomDevice;
  std::mt19937 generator(randomDevice());
  std::uniform_int_distribution<> dist(0, numberOfMonsterRaces - 1);
  MonsterRace race = static_cast<MonsterRace>(dist(generator));
  Monster monster1(race, 20);
  
  std::cout << "You found a " << monster1.getRace() << std::endl;

  return 0;
}
