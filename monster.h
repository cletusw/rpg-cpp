#include <iostream>
#include <random>

enum MonsterRace { Goblin = 0, Troll, Dragon };
std::string monsterRaceNames[] = { "Goblin", "Troll", "Dragon" };
const int numberOfMonsterRaces = 3;

std::ostream& operator<<(std::ostream &strm, const MonsterRace &race) {
  return strm << monsterRaceNames[race];
}

class Monster {
  private:
  MonsterRace race;
  int currentHealth;
  int maxHealth;
  
  public:
  Monster(
    MonsterRace race,
    int maxHealth
  ): race(race), maxHealth(maxHealth) {
    currentHealth = maxHealth;
    std::cout << "Created: " << *this << std::endl;
  }
  
  MonsterRace getRace() {
    return race;
  }
  
  friend std::ostream& operator<<(std::ostream&, const Monster&);
};

std::ostream& operator<<(std::ostream &strm, const Monster &a) {
  return strm << "Monster(" << a.race << ", " << getHpString(a.currentHealth, a.maxHealth) << ")";
}
