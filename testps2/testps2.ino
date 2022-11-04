// Try pressing buttons even when it says "Controller not found.",
// it may be faulty, but might be reading input.
// Check for the light on the controller first, only VCC and GND pin connections are enough
// The Analog button must be pressed (and the light must be glowing) for the joystick values to work.

// Hold down L1/R1 to Display Stick values
// if buttons are being displayed constantly as pressed, they are broken
// Comment out broken buttons in functions.ino

//---: Wirings :---
// WHITE(8), GREEN(9), GREY(3) can be ignored
// RED(5) to 3.3V
// BLACK(4) to GND
#define PIN_PS2_DATA 12       //BROWN(1)
#define PIN_PS2_CLOCK 13      //BLUE(7)
#define PIN_PS2_COMMAND 11    //ORANGE(2)
#define PIN_PS2_ATTENTION 10  //YELLOW(6)

#include <PS2X_lib.h>
PS2X ps2x;
void setup() {
  Serial.begin(9600);
  setup_ps2();
}
void loop() {
  delay(200);
  loop_ps2();
}
//<-Chinmay, Nov 2022