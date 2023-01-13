// set the previous milliseconds.
unsigned long prev_millis_indicator = 0;

// indicator that the reset has been toggled.
// usage: reset_indicator(millis()) or reset_indicator(millis(), true) if the reset is complete.;
void device_state(unsigned long interval = 50) {
  // if the reset is complete then turn off the LED
  if (is_reset) {
    // else keep on flickering.
    if ((current_millis - prev_millis_indicator) >= interval) {
      // save the last time the LED blinked.
      prev_millis_indicator = current_millis;
      // toggle the LED off then turn it on vice versa.
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
  } else {
    // if the is_reset variable is false then turn the LED off.
    digitalWrite(LED_BUILTIN, LOW);
  }
}