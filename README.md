<img src="http://www.vetco.net/catalog/images/VUPN6334-1.jpg" align="right" width="300" height="253" />
### IR Remote Control for Arduino

Light remote control lib for Arduino with console linking

* Light-weight<br/>
* Can determine signals from few consoles<br/>
* Automatic console header hash detection<br/>

#### Example
```cpp
#include <IRRemoteControl.h>

// setup pin
const int IR_REMOTE_PIN = 2;

void setup() {
  // declare the LED pin as INPUT:
  pinMode(IR_REMOTE_PIN, INPUT);  

  // setup serial output
  Serial.begin(9600);
}

IRRemoteControl console(IR_REMOTE_PIN);

void loop() {
  // print command if detected
  unsigned short command = console.readCommand();
  if ( command ) {
    Serial.println(command);
  }
}
```

<img src="https://learn.adafruit.com/system/assets/assets/000/000/551/medium800/light_sonycodepulses.jpg" align="right" width="300" height="225" />

#### Predefined console header
Any command starts from console-specific header<br/>
Lib will detect signal from specified console only
```cpp
const int IR_REMOTE_PIN = 2;
// 16 first bytes for current console (like ID)
const unsigned short CONSOLE_HEADER = 0b1000000001111111;

IRRemoteControl console(IR_REMOTE_PIN, CONSOLE_HEADER);
```

#### Console header detection
Press shortly any button your remote console after reset Arduino
```cpp
const int IR_REMOTE_PIN = 2;
IRRemoteControl console(IR_REMOTE_PIN);

// get current console header
unsigned short header = console.detectConsoleHeader();
Serial.println(header);
```
