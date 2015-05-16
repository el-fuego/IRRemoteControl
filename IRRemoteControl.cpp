
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "IRRemoteControl.h"


unsigned char IRRemoteControl::readBit () {
  unsigned long commandLength = pulseIn(pin, HIGH);

  if (commandLength > 1000) {
    return 1;
  } 
  if (commandLength > 300) {
    return 0;
  }
  return 2;
}

IRRemoteControl::IRRemoteControl (int _pin, float _consoleHeader) : pin(_pin), consoleHeader(_consoleHeader) {}


unsigned short IRRemoteControl::detectConsoleHeader () {
  unsigned long data = 0; // 16 bits (2 bytes) of IR sensor data
  unsigned char bit;
  
  for (unsigned char i=0; i<16; i++) {
    bit = readBit();
    
    // push reseived bit: 101 + 1 -> 1011
    data = (data << 1) + bit;
  }
  
  return data;
}

unsigned short IRRemoteControl::readCommand () {
  unsigned long data = 0; // 32 bits (4 bytes) of IR sensor data
  unsigned char bit;
  
  if (!consoleHeader) {
    consoleHeader = detectConsoleHeader();
    data = consoleHeader;
  }
  
  // wait for header + 2 bytes receiving
  while (data >> 16 != consoleHeader) {
    bit = readBit();
    
    // lost signal
    if (bit == 2) {
      return 0;
    }
    
    // push reseived bit: 101 + 1 -> 1011
    data = (data << 1) + bit;
  }
  
  // command = second 2 bytes
  return (data << 16) >> 16;
}