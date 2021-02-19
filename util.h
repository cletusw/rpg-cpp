#include <limits>
#include <sstream>

template <size_t numberOfOptions>
int prompt(std::string promptText, const std::string (&options)[numberOfOptions]) {
  int chosenOption;

  std::ostringstream optionsStream;
  for (int i = 0; i < numberOfOptions; i++) {
    optionsStream << " " << i + 1 << " " << options[i] << std::endl;
  }
  std::string optionsText = optionsStream.str();
  
  while ((std::cout << promptText << std::endl << optionsText)
      && (!(std::cin >> chosenOption)
        || chosenOption < 1
        || chosenOption > numberOfOptions)) {
    std::cout << "Please enter a number between 1 and " << std::to_string(numberOfOptions) << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  
  return chosenOption - 1;
}

std::string getHpString(int currentHealth, int maxHealth) {
  return std::to_string(currentHealth) + "/" + std::to_string(maxHealth) + " HP";
}
