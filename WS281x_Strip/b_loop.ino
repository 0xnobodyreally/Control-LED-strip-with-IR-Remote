
void loop() {

  if (irrecv.decode(&results)) {                // Check if an IR signal is received

    Serial.print(results.value, HEX);           // Display buttons RAW values in Serial monitor

    RGB_Remote();                               // Functions of remote in the next tab
  }
}                                               //  End of void loop
