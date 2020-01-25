# Control a WS2811 or WS2812b Led strip with an IR remote

    This sketch is designed to control a WS2811 or WS2812 Led strip using a RGB IR Remote:
    RGB Remote: https://images-na.ssl-images-amazon.com/images/I/71%2BXEYNSplL._SL1500_.jpg

    **Functions:**  OFF, ON, Increase/Decrease Brightness, Rainbow colors, Flash colors

    **External libraries used for custom colors: (these are now included in the sketch, no need to add separately) **
<s>      - MyGRBcolor for WS2811 strip:  http://bluenik.com/14971557/my-grb-color-library </s>
<s>      - MyRGBcolor for WS2812b strip: http://bluenik.com/14971557/my-rgb-color-library </s>

    Note: THIS SKETCH IS DIVIDED IN DIFFERENT TABS

    **CIRCUIT:**

    **WS2812b Led Strip:**
      - 5V   Pin  to  5V  Pin  of the Arduino
      - GND  Pin  to  GND Pin  of the Arduino
      - Data Pin  to  Pin 10   of the Arduino

    **IR Receiver:**
      - 5V   Pin  to  5V  Pin  of the Arduino
      - GND  Pin  to  GND Pin  of the Arduino
      - Data Pin  to  Pin 11   of the Arduino

    **Status Led [Optional]:**
      - Positive  Pin  to  Pin 13 of the Arduino
      - Negative  Pin  to  GND through a 220 Ohm Resistor
