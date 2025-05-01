#ifndef WEATHER_HPP
#define WEATHER_HPP

#include <string>

class Weather {
 private:
  float m_Temp, m_FeelsLike, m_WindSpeed;
  int m_Humidity, m_Visibility;
  std::string m_Desc;

 public:
  Weather();
  Weather(float, float, float, int, int, std::string);

  float getTemp();
  float getFeelsLike();
  float getWindSpeed();
  int getHumidity();
  int getVisibility();
  std::string getDesc();
};

#endif