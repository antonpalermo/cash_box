void reset_indicator(int count);

const int PIN_RESET = 4;
const int PIN_COLLECT = 2;

// boolean that checks if the button is pressed.
boolean reset_triggered = false;
// reset interval
int reset_interval = 5000;
// reset button previous state.
int reset_previous_state = LOW;
// duration the reset button is pressed.
unsigned long reset_pressed_duration = 0;

void setup() {
  initialize_serial();
  // set light indicator.
  pinMode(LED_BUILTIN, OUTPUT);
  // set reset button as input.
  pinMode(PIN_RESET, INPUT_PULLUP);
  // set store button as input.
  pinMode(PIN_COLLECT, INPUT_PULLUP);
  //
  Serial.println("Setup Complete");
}

unsigned long interval = 50;
// current milliseconds.
unsigned long current_millis = 0;

void reset_onhold() {
  // reset digital reading.
  int pinReset = digitalRead(PIN_RESET);

  if (pinReset == HIGH) {
    if (millis() - reset_pressed_duration > reset_interval) {
      reset_triggered = true;
    } else {
      if (reset_triggered) {
        //
        Serial.println("reset triggered!");
        // reset_notification(10);
        delay(5000);
        reset_triggered = false;
      }
      reset_pressed_duration = millis();
    }
  }
}

void collect_onpress() {
  // collect digital reading.
  int pinCollect = digitalRead(PIN_COLLECT);
}

void initialize_serial() {
  Serial.begin(9600);
  Serial.println("Initializing...");
  delay(500);
}

void loop() {
  // set current milliseconds
  current_millis = millis();
  reset_pressed_duration = millis();

  // listen for reset long press.
  reset_onhold();

  // listen for collect press.
  collect_onpress();
}
