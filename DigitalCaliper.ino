// The pins the quadrature encoder is connected.
// We connect the second signal of the encoder to pin 4.
// int.1 is free for other use.
int in_a = 2;
int in_b = 4;

// The number of pulses per revolution
// depends on your index disc!!
unsigned int pulsesperturn = 36;

// The total number of revolutions
int revolutions = 0;

// Initialize the counter
volatile int pulses = 0;

void count() {
  // This function is called by the interrupt
  // If in_b is HIGH increment the counter
  // otherwise decrement it
  if (digitalRead(in_b)) {
    pulses++;
  }
  else {
    pulses--;
  }
}

void setup() {
  pinMode(in_a, INPUT);
  pinMode(in_b, INPUT);
  attachInterrupt(0, count, RISING);
}

void loop() {
  revolutions = pulses / pulsesperturn
  // Here you can output the revolutions, e. g. once a second
  //
  //
  delay(1000);
}
