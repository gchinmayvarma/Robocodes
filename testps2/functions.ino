void print_ps2_sticks() {
  Serial.print("Stick Values:");
  Serial.print(ps2x.Analog(PSS_LY), DEC);
  Serial.print(",");
  Serial.print(ps2x.Analog(PSS_LX), DEC);
  Serial.print(",");
  Serial.print(ps2x.Analog(PSS_RY), DEC);
  Serial.print(",");
  Serial.println(ps2x.Analog(PSS_RX), DEC);
  // Use this: map(ps2x.Analog(PSS_RX), 0, 255, -100,100);
}

void setup_ps2() {
  Serial.println("Connecting to Controller");
  int error = ps2x.config_gamepad(PIN_PS2_CLOCK, PIN_PS2_COMMAND, PIN_PS2_ATTENTION, PIN_PS2_DATA, true, false);  //GamePad(clock, command, attention, data, Pressures?, Rumble?)
  if (error == 0) Serial.println("Found Controller ok.");
  else if (error == 1) Serial.println("Controller not found.");
  else if (error == 2) Serial.println("Controller found, not accepting commands.");
  else if (error == 3) Serial.println("Controller found, not entering Pressures mode.");
  else Serial.println("Unable to check errors.");  // byte type = ps2x.readType();
}

void loop_ps2() {
  ps2x.read_gamepad(false, 0);  //read controller and set large motor to spin at 'vibrate' speed
  if (ps2x.ButtonPressed(PSB_RED)) Serial.println("Circle pressed");
  if (ps2x.ButtonPressed(PSB_PINK)) Serial.println("Square pressed");
  if (ps2x.ButtonPressed(PSB_BLUE)) Serial.println("Cross pressed");
  if (ps2x.ButtonPressed(PSB_GREEN)) Serial.println("Triangle pressed");
  if (ps2x.ButtonPressed(PSB_L1)) Serial.println("L1 pressed");
  if (ps2x.ButtonPressed(PSB_R1)) Serial.println("R1 pressed");
  if (ps2x.ButtonPressed(PSB_L2)) Serial.println("L2 pressed");
  if (ps2x.ButtonPressed(PSB_R2)) Serial.println("R2 pressed");
  if (ps2x.ButtonPressed(PSB_START)) Serial.println("Start pressed");
  if (ps2x.ButtonPressed(PSB_SELECT)) Serial.println("Select pressed");
  if (ps2x.ButtonPressed(PSB_PAD_UP)) Serial.println("UP pressed");
  if (ps2x.ButtonPressed(PSB_PAD_DOWN)) Serial.println("DOWN pressed");
  if (ps2x.ButtonPressed(PSB_PAD_LEFT)) Serial.println("LEFT pressed");
  if (ps2x.ButtonPressed(PSB_PAD_RIGHT)) Serial.println("RIGHT pressed");
  if (ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) print_ps2_sticks();
  if (ps2x.Button(PSB_PAD_UP)) {
    Serial.print("Up held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
  }
  // if (ps2x.Button(PSB_START)) Serial.println("Start is being held"); //will be TRUE as long as button is pressed
  // if (ps2x.ButtonReleased(PSB_PINK)) //will be TRUE if button was JUST released
  // if (ps2x.NewButtonState(PSB_BLUE)) //will be TRUE if button was JUST pressed OR released
}