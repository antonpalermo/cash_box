// serial initializer
void serial_init();
// LED device state indicator.
void device_state(unsigned long interval = 50);
// collection procedures
void execute_collection_procedures();

#include <JC_Button.h>

const int PIN_RESET = 4;
const int PIN_COLLECT = 2;

// bool that checks of the LED indicator is on
bool is_reset = false;
// current milliseconds.
unsigned long current_millis = 0;

Button reset_button(PIN_RESET);
Button collect_button(PIN_COLLECT, 100);

void setup() {
  serial_init();
  // set light indicator.
  pinMode(LED_BUILTIN, OUTPUT);
  // setup reset button.
  reset_button.begin();
  // setup collect button.
  collect_button.begin();
  // setup complete.
  Serial.println("initializing serial complete...");
}


void loop() {
  // reset button (red) digital reading.
  reset_button.read();
  // collect button (white) digital reading.
  collect_button.read();
  // set current milliseconds
  current_millis = millis();
  // LED that indicates the device state.
  device_state();

  // if collection button is pressed.
  if (collect_button.wasPressed()) {
    // execute collection procedures.
    execute_collection_procedures();
  }
}
