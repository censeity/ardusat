#include <SPI.h>
#include <Wire.h>
#include <ArdusatSDK.h>
#include <math.h>

Display display;
int demodelay=2000;
ArdusatSerial serialConnection(SERIAL_MODE_HARDWARE_AND_SOFTWARE, 8, 9);

Acceleration accel;
float accel_mag;
int sensorReading;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    serialConnection.begin(9600);
  accel.begin();
ArdusatSerial serialConnection(SERIAL_MODE_HARDWARE_AND_SOFTWARE, 8, 9);

Acceleration accel;

void setup(void)
{
  serialConnection.begin(9600);

  accel.begin();

  serialConnection.println("");
}

void loop(void)
{
  
  serialConnection.println(accel.readToJSON("accelerometer"));

  delay(100);
}

  delay(10);
  // Clear the OLED screen
  display.clearDisplay();
  
  // ------------------------------------------------------------------------------------------------
  // drawPixel(x, y, color)
  // Draw one single tiny pixel in the center of the display ( 128x32 pixels )
  // ------------------------------------------------------------------------------------------------
  display.drawSquare(50, 50, sensorReading, BLUE);
  display.fillSquare(50, 50, sensorReading, BLUE);
  
  display.display();  
}
