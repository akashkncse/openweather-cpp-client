#include <iostream>
#include <limits>

#include "WeatherAPI.hpp"

int main() {
  std::cout << R"(
======================================
|       openweather-cpp-client       |
======================================
)" << std::endl;

  std::cout << "Please enter your OpenWeather API key: ";
  std::string apiKey;
  std::cin >> apiKey;

  while (true) {
    std::cout << R"(
==========================================
| 1. Get weather report for a city       |
| 2. Exit                                |
==========================================
)" << std::endl;

    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    if (std::cin.fail()) {
      std::cin.clear();                                                    // clear error flags
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard invalid input
      std::cout << "Invalid input. Please enter a number.\n";
      continue;
    }
    if (choice == 1) {
      std::cout << "Enter city name: ";
      std::cin.ignore();
      std::string city;
      std::getline(std::cin, city);

      WeatherAPI oapi(city, apiKey);
      Weather c = oapi.getWeather();

      std::cout << "\n======= Weather Report =======\n";
      std::cout << "City: " << city << std::endl;
      std::cout << "Description: " << c.getDesc() << std::endl;
      std::cout << "Temperature: " << c.getTemp() << " K // " << c.getTemp() - 273.15 << " C // "
                << (c.getTemp() - 273.15) * (9 / 5) + 32 << " F" << std::endl;
      std::cout << "Feels Like: " << c.getFeelsLike() << " K" << std::endl;
      std::cout << "Humidity: " << c.getHumidity() << " %" << std::endl;
      std::cout << "Wind Speed: " << c.getWindSpeed() << " m/s" << std::endl;
      std::cout << "Visibility: " << c.getVisibility() << " m" << std::endl;
      std::cout << "===============================\n";
      std::cin.get();
    } else if (choice == 2) {
      std::cout << "Exiting program. Goodbye!" << std::endl;
      break;
    } else {
      std::cout << "Invalid choice. Please try again.\n";
    }
  }

  return 0;
}
