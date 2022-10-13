#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::string name{};
  std::string time{};
  std::string adjective{};
  std::string another_adjective{};
  const int number_of_adjectives = 2;
  std::vector<std::string> adjectives;
  adjectives.reserve(number_of_adjectives);
  cout << "Welcome to the fortune teller program!" << endl;
  cout << "Please enter your name:" << endl;
  cin >> name;
  cout << "Please enter the time of year when you were born:" << endl;
  cout << "(pick from 'spring', 'summer', 'autumn', 'winter')" << endl;
  cin >> time;
  cout << "Please enter an adjective: " << endl;
  cin >> adjective;
  adjectives.push_back(adjective);
  cout << "Please enter another adjective: " << endl;
  cin >> another_adjective;
  adjectives.emplace_back(another_adjective);
  const int name_length = name.size();
  const int index = name_length % number_of_adjectives;
  const std::map<std::string, std::string> const_map = {
      {"spring", "STL guru"},
      {"summer", "C++ expert"},
      {"autumn", "coding beast"},
      {"winter", "software design hero"}};
  const std::vector<std::string> ending = {
      "eats UB for breakfast", "finds errors quicker than the compiler",
      "is not afraid of C++ error messages"};
  const int ending_index = name_length % ending.size();
  cout << "Here is your description:" << endl;
  cout << name << ", the " << adjectives.at(index) << " " << const_map.at(time)
       << " that " << ending.at(ending_index) << endl;

  return 0;
}