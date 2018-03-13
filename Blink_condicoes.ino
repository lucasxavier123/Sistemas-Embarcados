int incomingByte = 0;
double ms = 1000;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void piscar(int ms){
  if(ms == 0)
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  else{
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(ms);                       // wait for some time
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
    delay(ms); 
  }
}


// the loop function runs over and over again forever
void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    if(incomingByte == 'S') ms = 0;
    else if(incomingByte == '+')
      if(ms == 0)
        ms = 1000;
      else ms /= 2;
    else if(incomingByte == '-') ms *= 2;
  }
  piscar(ms);
}
