# Integrated Thermistor Circuit-
Class/Personal project for an analog integrated thermistor circuit that measures temperature using a simple comparison system with visual feedback using LEDs and console output. 


## Project Overview 

The circuit continuously reads:
- A desired temperature, set using a 10kΩ dial potentiometer
- The room's (or object if attached) temperature with a 10kΩ thermistor (Calibrated using thermometer data)

The system compares the two temperatures and will light up:
- Red LED: if it is too hot
- Blue LED: if it is too cold
- Green LED: if it is just right (within range set in code)

This project is great because it blends analog components, component calibration, and simple boolean logic using an Arduino. It is also easily expandable to other projects. 

## Compenents required for project

| Component                      | Quantity |
|-------------------------------|----------|
| Arduino Uno or Nano           | 1        |
| 10kΩ Analog Thermistor        | 1        |
| 10kΩ Dial Potentiometer       | 1        |
| 10kΩ Resistor                 | 1        |
| 330Ω Resistors                | 3        |
| LEDs (Red, Green, Blue)       | 3        |
| Breadboard + Jumper Wires     | as needed |


## Circuit Description 

- The thermistor forms a voltage divider with a 10kΩ resistor, which is then connected to an analog pin to read temperature
- A dial potentiometer is used to set a desired temperature range from the user 
- The Arduino will compare the thermistor and potentiometer readings and will light up an LED to indicate:
  - **Too cold**: Thermistor reading below lower threshold
  - **Too hot**: Thermistor reading above upper threshold
  - **Just right**: Reading within user-defined range

## Circuit Schematic 

full schematic available in /schematic/ folder. 
This can be opened in KiCAD for viewing
You can also view the schematic pdf in said folder for easy viewing 


## Arduino IDE Code 

Arduino code to read and compare values is found in the /Code/ folder.
The code includes:
- variable to set desired range (ex: range=3, temperature range is plus or minus 3 away from desired temperature)
- Analog to voltage conversion function for easy reading
- LED boolean logic
- Analog inputs from thermistor and potentiometer
- Calibrated thermistor function to convert voltage to temperature (change depending on thermistor)
- Console output depending on temperature comparison


## Calibration 
The thermistor was calibrated using temperature data from a thermometer.  
There is a Microsoft Excel file located in the /Documents/ folder as well as a png of the calibration plot. 
You may change your thermistor calibration as you see fit

---

## Images
An image of the real-world circuit is in the /Images/ folder. The image is of an Arduino Uno but can be changed with an Arduino Nano if needed. 


## How to use 
1. Wire the circuit according to the schematic
2. Change desired temperature range within code 
3. Upload the code to your board
4. Turn the dial to set your desired temperature 
5. Observe LEDs and Arduino console for live output


## Future Improvements
- Add OLED display for real-time temperature readout instead of using console
  
## License
This project is open-source under the LICENSE

-- 

## Other project uses
I have used this circuit to measure the temperature of a refrigerator to study its heating/cooling processes as well as its coefficient of performance. 

