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
