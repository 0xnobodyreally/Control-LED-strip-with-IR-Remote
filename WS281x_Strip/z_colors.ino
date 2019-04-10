
//  COLOR WHEEL USED BY RAINBOW COLORS

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
//    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);  //  R
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);  //  G
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
//    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);  //  G
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);  //  R
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);    //  B
}
