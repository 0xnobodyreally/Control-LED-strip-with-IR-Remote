
//  The animations below can be assigned to any button of your remote.
//  Available animations:

//  Strobe               (WHITE, 10, 50, 1000);
//  CylonBounce          (RED, 4, 10, 50);
//  candle();                                           //  Candle effect
//  rainbowCycle(RAINBOW_SPEED);                        //  Rainbow colors
//  NewKITT              (RED, 8, 10, 100);
//  Twinkle              (RED, 10, 100, false);
//  TwinkleRandom        (20, 100, false);
//  Sparkle              (GREEN, 0);                    //  Fixed color - Green
//  Sparkle              (random(255), random(255), random(255), 0);    //  Random colors
//  SnowSparkle          (GREY, 20, 200);               //  Fixed time
//  SnowSparkle          (GREY, 20, random(100,1000));  //  Random time
//  RunningLights        (YELLOW, SPEED);
//  theaterChaseRainbow  (SPEED);
//  BouncingBalls        (RED, 3);

//  ===========================================================================

void colorWipe(uint32_t c, uint8_t wait) {

  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

//  ===========================================================================

void candle() {
   uint8_t green; // brightness of the green
   uint8_t red;  // add a bit for red
   for(uint8_t i=0; i<100; i++) {
     green = 50 + random(155);
     red = green + random(50);
//     strip.setPixelColor(random(strip.numPixels() - 1), red, green, 0); //  RGB
     strip.setPixelColor(random(strip.numPixels() - 1), green, red, 0);   //  GRB
     strip.show();
     delay(5);
  }
}

//  ===========================================================================

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

    for(j=0; j<256*RAINBOW_REPEAT; j++) {               // # of cycles of all colors
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//  ===========================================================================

void theaterChase(uint32_t c, uint8_t wait) {

  for (int j=0; j<10; j++) {                          //  do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);                  //  turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);                  //  turn every third pixel off
      }
    }
  }
}

//  ===========================================================================

void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause){
  for(int j = 0; j < StrobeCount; j++) {
    setAll(red,green,blue);
    showStrip();
    delay(FlashDelay);
    setAll(0,0,0);
    showStrip();
    delay(FlashDelay);
  }

 delay(EndPause);
}

//  ===========================================================================

void CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay){

  for(int i = 0; i < LED_COUNT-EyeSize-2; i++) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue);
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(SpeedDelay);
  }

  delay(ReturnDelay);

  for(int i = LED_COUNT-EyeSize-2; i > 0; i--) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue);
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(SpeedDelay);
  }

  delay(ReturnDelay);
}

//  ===========================================================================

void NewKITT(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay){
  RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  LeftToRight(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  OutsideToCenter(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  CenterToOutside(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  LeftToRight(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  OutsideToCenter(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  CenterToOutside(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
}

void CenterToOutside(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for(int i =((LED_COUNT-EyeSize)/2); i>=0; i--) {
    setAll(0,0,0);

    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue);
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);

    setPixel(LED_COUNT-i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(LED_COUNT-i-j, red, green, blue);
    }
    setPixel(LED_COUNT-i-EyeSize-1, red/10, green/10, blue/10);

    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

void OutsideToCenter(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for(int i = 0; i<=((LED_COUNT-EyeSize)/2); i++) {
    setAll(0,0,0);

    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue);
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);

    setPixel(LED_COUNT-i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(LED_COUNT-i-j, red, green, blue);
    }
    setPixel(LED_COUNT-i-EyeSize-1, red/10, green/10, blue/10);

    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

void LeftToRight(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for(int i = 0; i < LED_COUNT-EyeSize-2; i++) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue);
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

void RightToLeft(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
  for(int i = LED_COUNT-EyeSize-2; i > 0; i--) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue);
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

//  ===========================================================================

void Twinkle(byte red, byte green, byte blue, int Count, int SpeedDelay, boolean OnlyOne) {
  setAll(0,0,0);

  for (int i=0; i<Count; i++) {
     setPixel(random(LED_COUNT),red,green,blue);
     showStrip();
     delay(SpeedDelay);
     if(OnlyOne) {
       setAll(0,0,0);
     }
   }

  delay(SpeedDelay);
}

//  ===========================================================================

void TwinkleRandom(int Count, int SpeedDelay, boolean OnlyOne) {
  setAll(0,0,0);

  for (int i=0; i<Count; i++) {
     setPixel(random(LED_COUNT),random(0,255),random(0,255),random(0,255));
     showStrip();
     delay(SpeedDelay);
     if(OnlyOne) {
       setAll(0,0,0);
     }
   }

  delay(SpeedDelay);
}

//  ===========================================================================

void Sparkle(byte red, byte green, byte blue, int SpeedDelay) {
  int Pixel = random(LED_COUNT);
  setPixel(Pixel,red,green,blue);
  showStrip();
  delay(SpeedDelay);
  setPixel(Pixel,0,0,0);
}

//  ===========================================================================

void SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay) {
  setAll(red,green,blue);

  int Pixel = random(LED_COUNT);
  setPixel(Pixel,0xff,0xff,0xff);
  showStrip();
  delay(SparkleDelay);
  setPixel(Pixel,red,green,blue);
  showStrip();
  delay(SpeedDelay);
}

//  ===========================================================================

void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position=0;

  for(int i=0; i<LED_COUNT*2; i++)
  {
      Position++;                               // = 0; //Position + Rate;
      for(int i=0; i<LED_COUNT; i++) {
        setPixel(i,((sin(i+Position) * 127 + 128)/255)*red,
                   ((sin(i+Position) * 127 + 128)/255)*green,
                   ((sin(i+Position) * 127 + 128)/255)*blue);
      }
      showStrip();
      delay(WaveDelay);
  }
}

//  ===========================================================================

void theaterChaseRainbow(int SpeedDelay) {
  byte *c;

  for (int j=0; j < 256; j++) {                 // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < LED_COUNT; i=i+3) {
          c = Wheel2( (i+j) % 255);
          setPixel(i+q, *c, *(c+1), *(c+2));    //turn every third pixel on
        }
        showStrip();

        delay(SpeedDelay);

        for (int i=0; i < LED_COUNT; i=i+3) {
          setPixel(i+q, 0,0,0);                 //turn every third pixel off
        }
    }
  }
}

byte * Wheel2(byte WheelPos) {
  static byte c[3];

  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }

  return c;
}

//  ===========================================================================

void BouncingBalls(byte red, byte green, byte blue, int BallCount) {
  float Gravity = -9.81;
  int StartHeight = 1;

  float Height[BallCount];
  float ImpactVelocityStart = sqrt( -2 * Gravity * StartHeight );
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int   Position[BallCount];
  long  ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];

  for (int i = 0 ; i < BallCount ; i++) {
    ClockTimeSinceLastBounce[i] = millis();
    Height[i] = StartHeight;
    Position[i] = 0;
    ImpactVelocity[i] = ImpactVelocityStart;
    TimeSinceLastBounce[i] = 0;
    Dampening[i] = 0.90 - float(i)/pow(BallCount,2);
  }

  while (true) {
    for (int i = 0 ; i < BallCount ; i++) {
      TimeSinceLastBounce[i] =  millis() - ClockTimeSinceLastBounce[i];
      Height[i] = 0.5 * Gravity * pow( TimeSinceLastBounce[i]/1000 , 2.0 ) + ImpactVelocity[i] * TimeSinceLastBounce[i]/1000;

      if ( Height[i] < 0 ) {
        Height[i] = 0;
        ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
        ClockTimeSinceLastBounce[i] = millis();

        if ( ImpactVelocity[i] < 0.01 ) {
          ImpactVelocity[i] = ImpactVelocityStart;
        }
      }
      Position[i] = round( Height[i] * (LED_COUNT - 1) / StartHeight);
    }

    for (int i = 0 ; i < BallCount ; i++) {
      setPixel(Position[i],red,green,blue);
    }

    showStrip();
    setAll(0,0,0);
  }
}

//  ===========================================================================

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

//  ===========================================================================

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

//  ===========================================================================

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < LED_COUNT; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
