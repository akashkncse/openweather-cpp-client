#include "WeatherAPI.hpp"

#include <curl/curl.h>

#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>

#include "utils.hpp"

using json = nlohmann::json;

WeatherAPI::WeatherAPI(const std::string &city, const std::string &API_key) : city(city), API_key(API_key) {}

std::string WeatherAPI::urlEncode(const std::string &value) const {
  std::ostringstream escaped;
  escaped.fill('0');
  escaped << std::hex;

  for (char c : value) {
    if (isalnum(static_cast<unsigned char>(c)) || c == '-' || c == '_' || c == '.' || c == '~') {
      escaped << c;
    } else {
      escaped << '%' << std::setw(2) << std::uppercase << int(static_cast<unsigned char>(c));
    }
  }

  return escaped.str();
}

Weather WeatherAPI::getWeather() {
  CURL *curl = curl_easy_init();
  if (!curl) {
    std::cerr << "CURL initialization failed" << std::endl;
  }

  std::string encodedCity = urlEncode(this->city);
  std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + encodedCity + "&appid=" + this->API_key;

  std::string response;

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    std::cerr << "CURL error: " << curl_easy_strerror(res) << std::endl;
  } else {
    json jr = json::parse(response);
    return Weather(jr["main"]["temp"].get<float>(), jr["main"]["feels_like"].get<float>(),
                   jr["wind"]["speed"].get<float>(), jr["main"]["humidity"].get<int>(), jr["visibility"].get<int>(),
                   jr["weather"][0]["description"].get<std::string>());
  }

  curl_easy_cleanup(curl);
  curl_global_cleanup();
  return Weather();
}
