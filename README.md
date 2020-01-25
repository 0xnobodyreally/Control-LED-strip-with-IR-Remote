# Control a WS2811 or WS2812b Led strip with an IR remote

    This sketch is designed to control a WS2811 or WS2812 Led strip using a RGB IR Remote:
    RGB Remote: [https://images-na.ssl-images-amazon.com/images/I/71%2BXEYNSplL._SL1500_.jpg]

    YouTube Demo: [https://youtu.be/WszzmkpDbmA]

    **Functions:**  OFF, ON, Increase/Decrease Brightness, Rainbow colors, Flash colors


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
