
// #include <MyRGBcolors.h>            //  My RGB color library for WS2812b strip
//#include <MyGRBcolors.h>          //  My GRB color library for WS2811 strip

#include "./Libraries/MyRGBcolors.h"//  My color library for RGB WS2812b strip
// #include "./Libraries/MyGRBcolors.h"//  My color library for GRB WS2812b strip


#include <Adafruit_NeoPixel.h>      //  Library for WS2811/WS2812b Led strips
#include "IRremote.h"               //  Library for IR Remote

#define IR_Receiver           11    //  Pin 1 of IR receiver to Arduino digital Pin 11
#define LED_PIN               10    //  Data Pin of Led strip
#define LED_COUNT             12    //  Number of LEDs in your strip
#define StatusLed_PIN         13    //  [OPTIONAL] Pin of the status Led
#define SPEED                 50    //  Speed of each Color Transition (in ms)
#define NOW                    0    //  Transition happen instantly
#define RAINBOW_SPEED         10    //  Rainbow Transition speed
#define RAINBOW_REPEAT         1    //  How many times the Rainbow Cycle is repeated
#define BRIGHTNESS            55    //  Initial Brightness
#define BRIGHTNESS_INCREMENT  50    //  Increase/Decrease Brightness by this value
#define MIN_BRIGHTNESS         5    //  Minimum Brightness
#define MAX_BRIGHTNESS       255    //  Maximum Brightness

int currentBrightness;              //  This will save the current Brightness
int buttonPushCounterA    =    0;   //  Counts how many times the button has been pushed
int buttonStateA          =    0;   //  Current state of the button
int lastButtonStateA      =    0;   //  Previous state of the button

//  Initialize Led Strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//  Initialize IR Receiver
IRrecv irrecv(IR_Receiver);         //  create instance of 'irrecv'
decode_results results;             //  create instance of 'decode_results'
