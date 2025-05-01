#ifndef WEATHERAPI_HPP
#define WEATHERAPI_HPP

#include <string>

#include "Weather.hpp"

class WeatherAPI {
 private:
  std::string city;
  std::string API_key;
  std::string requestURL;
  std::string urlEncode(const std::string &value) const;

 public:
  WeatherAPI(const std::string &, const std::string &);
  Weather getWeather();
};

#endif