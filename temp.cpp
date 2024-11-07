#include <iostream>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include "max6675.h"  // This is a placeholder for an appropriate C++ library to interact with MAX6675

using namespace std;

int soPin = 4; // SO = Serial Out (MISO)
int csPin = 5; // CS = Chip Select
int sckPin = 6; // SCK = Serial Clock (SCLK)

MAX6675 thermocouple(sckPin, csPin, soPin);  // Create an instance of the MAX6675 object

void setup() {
    // Initialize wiringPi library
    if (wiringPiSetup() == -1) {
        cout << "Error setting up wiringPi" << endl;
        exit(1);
    }

    cout << "MAX6675 Temperature Sensor" << endl;
}

void loop() {
    // Read and display temperature in Celsius and Fahrenheit
    cout << "C = " << thermocouple.readCelsius() << " ";
    cout << "F = " << thermocouple.readFahrenheit() << endl;

    delay(10000);  // Wait for 10 seconds between readings
}

int main() {
    setup();
    while (true) {
        loop();
    }
    return 0;
}
