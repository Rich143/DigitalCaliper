// include the library code:
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7


// The pins the quadrature encoder is connected.
// We connect the second signal of the encoder to pin 4.
// int.1 is free for other use.
int in_a = 2;
int in_b = 3;

// The number of pulses per revolution
// depends on your index disc!!
unsigned int pulsesperturn = 32;
unsigned int pulsespercentimetre = 3;

// The total number of revolutions
int distance = 0;

// Initialize the counter
volatile int pulses = 0;
volatile int numInterrupts = 0;
volatile int numBInterrupts = 0;

volatile unsigned long lastTrigger = 0;
volatile unsigned long lastBTrigger = 0;

#define debounceTime 5 // debounce time in microseconds

void count() {
  // This function is called by the interrupt
  // If in_b is HIGH increment the counter
  // otherwise decrement it
  if (micros() - lastTrigger > debounceTime) {
    numInterrupts++;

    if (digitalRead(in_b)) {
      pulses--;
    }
    else {
      pulses++;
    }
  }
  
  lastTrigger = micros();
}

void countB() {
  if (micros() - lastBTrigger > debounceTime) {
    numBInterrupts++;
    
    if (digitalRead(in_a)) {
      pulses++;
    }
    else {
      pulses--;
    }
  }
  
  lastBTrigger = micros();
}

void setup() {
  Serial.begin(9600);
  pinMode(in_a, INPUT);
  pinMode(in_b, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(in_b), countB, FALLING);
  attachInterrupt(digitalPinToInterrupt(in_a), count, FALLING);
  
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  lcd.setBacklight(BLUE);
  lcd.print("Distance: ");
  
}

void loop() {
  
  distance = (pulses * 107) / 58; // 5  pulses per centimetre
  
  //int a = digitalRead(in_a);
  //int b = digitalRead(in_b);
  
  //Serial.print("A=");
  //Serial.println(a?"High":"Low");
  //Serial.print(" B=");
  //Serial.println(b?"High":"Low");
  
  Serial.print("ints: ");
  Serial.print(numInterrupts);
  Serial.print(" intB: ");
  Serial.print(numBInterrupts);
  Serial.print(" pulses: ");
  Serial.print(pulses);
  Serial.print(" distance: ");
  Serial.println(distance);
  
  lcd.setBacklight(random(1,8));
  lcd.setCursor(10,0);
  lcd.print(distance);
  
  delay(500);
  
}
