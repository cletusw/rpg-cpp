#include <iostream>

enum Race { Human = 0, Elf, Dwarf };
std::string raceNames[] = { "Human", "Elf", "Dwarf" };
const int numberOfRaces = 3;

std::ostream& operator<<(std::ostream &strm, const Race &race) {
  return strm << raceNames[race];
}

Race promptForRace() {
  auto raceNumber = prompt<numberOfRaces>("Choose a race:", raceNames);
  return static_cast<Race>(raceNumber);
}

class Player {
  private:
  std::string name;
  Race race;
  int currentHealth;
  int maxHealth;
  
  public:
  Player(
    std::string name,
    Race race,
    int maxHealth
  ): name(name), race(race), maxHealth(maxHealth) {
    currentHealth = maxHealth;
    std::cout << "Created: " << *this << std::endl;
  }
  
  friend std::ostream& operator<<(std::ostream&, const Player&);
};

std::ostream& operator<<(std::ostream &strm, const Player &a) {
  return strm << "Player(" << a.name << ", " << a.race << ", " << getHpString(a.currentHealth, a.maxHealth) << ")";
}
