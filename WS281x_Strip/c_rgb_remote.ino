
void RGB_Remote()  {                           //  Functions for IR Remote

  int currentButtonStateA = digitalRead(IR_Receiver);

    digitalWrite(StatusLed_PIN, LOW);          //  Blink the Status LED when an input is received
    delay(70);
    digitalWrite(StatusLed_PIN, HIGH);


  switch(results.value)  {                           //  IR Remote buttons

  case 0xFF906F:
    Serial.println("     BRIGHTNESS UP");            //  Increase Brightness
    currentBrightness += BRIGHTNESS_INCREMENT;
    if (currentBrightness > MAX_BRIGHTNESS)
    {   currentBrightness = MAX_BRIGHTNESS;  }
    lastButtonStateA = currentButtonStateA;
    strip.setBrightness(currentBrightness);          //  Set current Brightness
    Serial.print("Current Brightness: ");
    Serial.println(currentBrightness);               //  Print current Brightness
    strip.show();
    break;

  case 0xFFB847:
    Serial.println("     BRIGHTNESS DOWN");          //  Decrease Brightness
    currentBrightness -= BRIGHTNESS_INCREMENT;
    if (currentBrightness < MIN_BRIGHTNESS)
    {  currentBrightness = MIN_BRIGHTNESS;  }
    lastButtonStateA = currentButtonStateA;
    strip.setBrightness(currentBrightness);          //  Set current Brightness
    Serial.print("Current Brightness: ");
    Serial.println(currentBrightness);               //  Print current Brightness
    strip.show();
    break;

  case 0xFFF807:
    Serial.println("     OFF");
    colorWipe(strip.Color(0, 0, 0), SPEED);          //  Turn Led strip OFF
    digitalWrite(StatusLed_PIN, LOW);                //  Turn Status Led OFF
    break;

  case 0xFFB04F:
    Serial.println("     ON");
    colorWipe(strip.Color(WHITE), NOW);              //  White
    break;

  case 0xFF9867:
    Serial.println("     RED");
    colorWipe(strip.Color(RED), SPEED);              //  Red
    break;

  case 0xFFD827:
    Serial.println("     GREEN");
    colorWipe(strip.Color(GREEN), SPEED);            //  Green
    break;

  case 0xFF8877:
    Serial.println("     BLUE");
    colorWipe(strip.Color(BLUE), SPEED);             //  Blue
    break;

  case 0xFFA857:
    Serial.println("     WHITE");
    colorWipe(strip.Color(WHITE), SPEED);            //  White
    break;

  case 0xFFE817:
    Serial.println("     ORANGE");
    colorWipe(strip.Color(ORANGE), SPEED);           //  Orange
    break;

  case 0xFF48B7:
    Serial.println("     MINT");
    colorWipe(strip.Color(MINT), SPEED);             //  Mint
    break;

  case 0xFF6897:
    Serial.println("     DARK BLUE");
    colorWipe(strip.Color(DARK_BLUE), SPEED);        //  Dark Blue
    break;

  case 0xFFB24D:
    Serial.println("     * FLASH *");
    candle();                                        //  Candle effect
    Serial.println("     END");
    break;

  case 0xFF02FD:
    Serial.println("     BROWN");
    colorWipe(strip.Color(BROWN), SPEED);            //  Brown
    break;

  case 0xFF32CD:
    Serial.println("     AQUA");
    colorWipe(strip.Color(AQUA), SPEED);             //  Aqua
    break;

  case 0xFF20DF:
    Serial.println("     PURPLE");
    colorWipe(strip.Color(PURPLE), SPEED);           //  Purple
    break;

  case 0xFF00FF:
    Serial.println("     * STROBE *");
    RunningLights(YELLOW, SPEED);                    //  Yellow Running Lights
    Serial.println("     END");
    break;

  case 0xFF50AF:
    Serial.println("     BEIGE");
    colorWipe(strip.Color(BEIGE), SPEED);            //  Beige
    break;

  case 0xFF7887:
    Serial.println("     TOPAZ");
    colorWipe(strip.Color(TOPAZ), SPEED);            //  Topaz
    break;

  case 0xFF708F:
    Serial.println("     FUCHSIA");
    colorWipe(strip.Color(FUCHSIA), SPEED);          //  Fuchsia
    break;

  case 0xFF58A7:
    Serial.println("     * FADE RAINBOW COLORS *");
    rainbowCycle(RAINBOW_SPEED);                     //  Rainbow colors
    Serial.println("     END");
    break;

  case 0xFF38C7:
    Serial.println("     YELLOW");
    colorWipe(strip.Color(YELLOW), SPEED);           //  Yellow
    break;

  case 0xFF28D7:
    Serial.println("     SKY BLUE");
    colorWipe(strip.Color(SKY_BLUE), SPEED);         //  Sky Blue
    break;

  case 0xFFF00F:
    Serial.println("     PINK");
    colorWipe(strip.Color(PINK), SPEED);             //  Pink
    break;

  case 0xFF30CF:
    Serial.println("     * FLASHING RAINBOW COLORS *");
    theaterChaseRainbow(SPEED);                      //   Theatre chase random colors
    Serial.println("     END");
    break;

  case 0xFFFFFFFF:                                   //   Ignore this value
  Serial.println(" ");
    break;

  default:
    Serial.println("     [undefined button]   ");

  }
    delay(50);                                       //  short delay
    irrecv.resume();                                 //  Ready to receive the next input

} //  End of My Remote   */
