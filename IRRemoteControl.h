
#ifndef IRRemoteControl_h
#define IRRemoteControl_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class IRRemoteControl {
  private:
    int pin;
    unsigned short consoleHeader;
    
    unsigned char readBit ();
  
  public:
    
    IRRemoteControl(int _pin, float _consoleHeader=0);

    unsigned short detectConsoleHeader ();

    unsigned short readCommand ();

};

#endif
