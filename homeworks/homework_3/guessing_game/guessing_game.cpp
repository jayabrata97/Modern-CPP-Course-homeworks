#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::random_device random_device;
  std::mt19937 random_engine{random_device()};
  int smallest_number = 0;
  int largest_number = 1000000;
  int guessed_number = 0;
  int count = 1;
  cout << "Welcome to the GUESSING GAME!" << endl;
  cout << "I will generate a number and you will guess it!" << endl;
  cout << "Please provide the smallest number: " << endl;
  cin >> smallest_number;
  cout << "Please provide the largest number: " << endl;
  cin >> largest_number;
  std::uniform_int_distribution<int> distribution{smallest_number,
                                                  largest_number};
  int random_number = distribution(random_engine);
  // cout << random_number << endl;
  cout << "I've generated a number. Try to guess it!" << endl;
  cout << "Please provide the next guess: ";
  cin >> guessed_number;
  if (guessed_number != random_number) {
    while (guessed_number != random_number) {
      count++;
      if (guessed_number < random_number) {
        cout << "Your number is too small. Try again!" << endl;
      } else {
        cout << "Your number is too big. Try again!" << endl;
      }
      cout << "Please provide the next guess: ";
      cin >> guessed_number;
    }
  }
  cout << "You've done it! You guessed the number " << guessed_number << " in "
       << count << " guesses!" << endl;

  return 0;
}