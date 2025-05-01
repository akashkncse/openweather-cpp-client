#include "Weather.hpp"

Weather::Weather() {}

Weather::Weather(float t, float f, float w, int h, int v, std::string d)
    : m_Temp(t), m_FeelsLike(f), m_WindSpeed(w), m_Humidity(h), m_Visibility(v), m_Desc(d) {}

float Weather::getTemp() { return m_Temp; }
float Weather::getFeelsLike() { return m_FeelsLike; }
float Weather::getWindSpeed() { return m_WindSpeed; }
int Weather::getHumidity() { return m_Humidity; }
int Weather::getVisibility() { return m_Visibility; }
std::string Weather::getDesc() { return m_Desc; }