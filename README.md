# OpenWeather C++ Client
A C++ client for fetching weather data from OpenWeatherMap API

---

## Features 
- Fetches weather data for a given city/country.
- Displays temperature, humidity, wind speed, visibility, and weather description.

---

## Requirements
- **C++17 or later**
- **Libraries**:
  - `libcurl` (for HTTP requests)
  - `nlohmann/json` (for JSON parsing)
- OpenWeatherMap API key (simple to get!)

---

## Build Instructions 

Install libcurl and nlohmann/json and run this command using g++

```g++ main.cpp src/WeatherAPI.cpp src/Weather.cpp src/utils.cpp -o openweather-client -Iinclude -lcurl```

---

## Sample Output

```
======================================
|       openweather-cpp-client       |
======================================

Please enter your OpenWeather API key: YOUR_API_KEY

==========================================
| 1. Get weather report for a city       |
| 2. Exit                                |
==========================================
Enter your choice: 1
Enter city name: London

======= Weather Report =======
City: London
Description: clear sky
Temperature: 293.15 K // 20.0 C // 68.0 F
Feels Like: 291.15 K
Humidity: 60 %
Wind Speed: 5.5 m/s
Visibility: 10000 m
===============================
```

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## Acknowledgements 

- OpenWeatherMap API
- libcurl
- nlohmann/json
