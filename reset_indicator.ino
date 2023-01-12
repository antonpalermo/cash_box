// interval between LED on and off.
const long blink_interval = 50;
// set the previous milliseconds.
unsigned long prevMillis = 0;

// indicator that the reset has been toggled.
// usage: reset_indicator(millis()) or reset_indicator(millis(), true) if the reset is complete.;
void reset_indicator(unsigned long millis, bool complete = false) {
  // if the reset is complete then turn off the LED
  if (complete) {
    digitalWrite(LED_BUILTIN, LOW);
    // else keep on flickering.
  } else {
    //
    if ((millis - prevMillis) >= blink_interval) {
      // save the last time the LED blinked.
      prevMillis = millis;
      // toggle the LED off then turn it on vice versa.
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
  }
}