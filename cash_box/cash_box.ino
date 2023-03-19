#define BA_PIN (12)

// 2 pulses means 20 pesos.
// 5 pulses means 50 pesos.
// 10 pulses means 100 pesos.
// 20 pulses means 200 pesos.
// 50 pulses means 500 pesos.
// 100 pulses means 1000 pesos.

unsigned long curr_time;

unsigned long pulse_end;
unsigned long pulse_begin;
unsigned long pulse_duration;

int pulse_pause;
int pulse_state;
int pulse_count;

int amount;
int amount_recieved;
int amount_per_pulse;

int last_state;
int debounce_speed;
int min_pulse_width;
int max_pulse_width;

void setup() {
  Serial.begin(115200);
  pinMode(BA_PIN, INPUT);

  last_state = 0;

  debounce_speed = 4;
  min_pulse_width = 40;
  max_pulse_width = 60;

  pulse_end = 0;
  pulse_pause = 300;

  amount = 0;
  amount_recieved = 0;
  amount_per_pulse = 10;


  Serial.println("Device Ready");
}

void loop() {
  pulse_state = digitalRead(BA_PIN);
  curr_time = millis();

  // pulse entered a new pulse.
  if ((pulse_state == 1) && (last_state == 0)) {
    // save the current milis()
    pulse_begin = curr_time;
    // set the previous state
    last_state = 1;
    // this means that the a pulse just ended
  } else if ((pulse_state == 0) && (last_state == 1)) {
    pulse_duration = curr_time - pulse_begin;
    if (pulse_duration > debounce_speed) {
      last_state = 0;
    }
    if ((pulse_duration > min_pulse_width) && (pulse_duration < max_pulse_width)) {
      pulse_end = curr_time;
      pulse_count++;
    }
  }

  if ((pulse_end > 0) && (curr_time - pulse_end > pulse_pause)) {
    amount_recieved += pulse_count * amount_per_pulse;

    amount += amount_recieved;
    Serial.print("Total Amount: ");
    Serial.println(amount);

    pulse_end = 0;
    pulse_count = 0;
    amount_recieved = 0;
  }
}
