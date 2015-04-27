
#include <Wire.h>
#include <BMP180.h>

BMP180 barometer;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  barometer = BMP180();
  if(barometer.EnsureConnected())
  {
    barometer.SoftReset();
    barometer.Initialize();
  }
  else
  { 
    Serial.println("E");
  }
}

void loop()
{
  if(barometer.IsConnected)
  {
    // Retrive the current pressure in Pascals.
    long pres = barometer.GetPressure();
    float temp = barometer.GetTemperature();
    Serial.print("P"); Serial.println(pres);
    Serial.print("T"); Serial.println(temp);
    delay(1000); // Show new results every second.
  }
}
