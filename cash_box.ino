const int PIN_RESET = 4;
const int PIN_COLLECT = 2;

void setup() {
  initialize_serial();
  // set light indicator.
  pinMode(LED_BUILTIN, OUTPUT);
  // set reset button as input.
  pinMode(PIN_RESET, INPUT_PULLUP);
  // set store button as input.
  pinMode(PIN_COLLECT, INPUT_PULLUP);
  // print if all setup is complete.
  Serial.println("Setup Complete");
}

// current milliseconds.
unsigned long current_millis = 0;

void initialize_serial() {
  Serial.begin(9600);
  Serial.println("Initializing...");
  delay(1000);
}

int debounce = 50;
// previous state of reset button.
int reset_previous_state = LOW;
//
unsigned long reset_millis;

void reset_onhold() {
  // reset digital reading.
  int pinReset = digitalRead(PIN_RESET);
  // 
  int press_duration;
  //
  if ((current_millis - reset_millis) > debounce) {
    reset_millis = current_millis;
  }
}

void collect_onpress() {
  // collect digital reading.
  int pinCollect = digitalRead(PIN_COLLECT);
}

void loop() {
  // set current milliseconds
  current_millis = millis();

  // listen for reset long press.
  reset_onhold();

  // listen for collect press.
  collect_onpress();
}
