// serial initializer
void serial_init();
// LED device state indicator.
void device_state(unsigned long interval = 50);
// onhold reset button event.
void reset_onhold();
// onpress collect button event.
void collect_onpress();

const int PIN_RESET = 4;
const int PIN_COLLECT = 2;

// bool that checks of the LED indicator is on
bool is_reset = false;
// current milliseconds.
unsigned long current_millis = 0;

void setup() {
  serial_init();
  // set light indicator.
  pinMode(LED_BUILTIN, OUTPUT);
  // set reset button as input.
  pinMode(PIN_RESET, INPUT_PULLUP);
  // set store button as input.
  pinMode(PIN_COLLECT, INPUT_PULLUP);
  //
  Serial.println("device ready");
}

void loop() {
  // set current milliseconds
  current_millis = millis();
  // LED that indicates the device state.
  device_state();
  // listen for reset long press.
  reset_onhold();
  // listen for collect press.
  collect_onpress();
}
