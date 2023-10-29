#include <QMC5883LCompass.h>

QMC5883LCompass compass;

void setup() {
  Serial.begin(9600);
  compass.init();
  
}

void loop() {
  int x, y, z;
  
  // Read compass values
  compass.read();

  // Return XYZ readings
  x = compass.getX();
  y = compass.getY();
  
  float heading = atan2(y, x);
  heading += (heading < 0) ? 2 * PI : 0;
  heading = degrees(heading);

  Serial.print("Heading: ");
  Serial.print(heading);
  Serial.println(" degrees");
  delay(250);
}
