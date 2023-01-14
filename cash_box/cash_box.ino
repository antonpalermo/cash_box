// serial initializer
void serial_init();
// LED device state indicator.
void device_state(unsigned long interval = 50);
// collection procedures
void execute_collection_procedures(int red, int green, int blue);

#include <tcs3200.h>
#include <JC_Button.h>

// button pins
const int PIN_RESET = 4;
const int PIN_COLLECT = 2;
// color sensor pins
const int PIN_S0 = 8;
const int PIN_S1 = 9;
const int PIN_S2 = 10;
const int PIN_S3 = 11;
const int PIN_OUTPUT = 12;

// bool that checks of the LED indicator is on
bool is_reset = false;
// current milliseconds.
unsigned long current_millis = 0;

Button reset_button(PIN_RESET);
Button collect_button(PIN_COLLECT, 100);
// color sensor setup.
tcs3200 tcs(PIN_S0, PIN_S1, PIN_S2, PIN_S3, PIN_OUTPUT);  // (S0, S1, S2, S3, output pin)  //

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

int red, green, blue;

void loop() {
  // reset button (red) digital reading.
  reset_button.read();
  // collect button (white) digital reading.
  collect_button.read();
  // set current milliseconds
  current_millis = millis();
  // LED that indicates the device state.
  device_state();

  // red color reading.
  red = tcs.colorRead("r");
  // green color reading.
  green = tcs.colorRead("g");
  // blue color reading.
  blue = tcs.colorRead("b");

  // if collection button is pressed.
  if (collect_button.wasPressed()) {
    // execute collection procedures.
    execute_collection_procedures(red, green, blue);
  }
}
