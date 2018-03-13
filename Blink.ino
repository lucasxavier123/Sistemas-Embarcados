// the setup function runs once when you press reset or power the board

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void piscar(int ms, int times){
  for(int i = 0; i < times; i++){
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(ms);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
    delay(ms); 
  }
}

// the loop function runs over and over again forever
void loop() {
  piscar(1000, 3);
  piscar(2000, 5);
}
