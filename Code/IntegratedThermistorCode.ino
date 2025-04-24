

const int temperaturePin = A0; //read from thermistor 
const int potentPin = A1; //read from potentiometer
const int redPin = 13; //set LED pins 
const int greenPin = 12;
const int bluePin = 11;

void setup()
{
  //initialize LED pins
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    Serial.begin(9600); //Initialize serial port 
}

void loop()
{

  //Declare variables 
    float voltage, degreesC, degreesF, potentvoltage, setdegreesC, setdegreesF, tempdiff, desiredtemp; 
    
    desiredtemp = 3; //input max temperature difference between thermistor and potentiometer 
    voltage = getVoltage(temperaturePin); //Measure the voltage at the analog 0 pin
    potentvoltage = getVoltage(potentPin); //Measure the voltage at the analog 1 pin, gives desired temperature from potentiometer 

    degreesC = (-1.9844*pow(voltage,3))+(16.11*pow(voltage,2))-(62.957*voltage)+113.32-2; // Convert the voltage to degrees Celsius using calibrated thermistor data 
    //Note: Thermometer used to calibrate thermistor reads about 2 degrees higher than the rest, the thermistor temperature is subtracted by an arbitrary 2 to account for the shift

    setdegreesC = (-1.9844*pow(potentvoltage,3))+(16.11*pow(potentvoltage,2))-(62.957*potentvoltage)+113.32-2; //convert potentiometer voltage to degrees Celsius with calibrated data
  //Convert degrees Celsius to Fahrenheit
    degreesF = degreesC * (9.0 / 5.0) + 32.0; 
    setdegreesF = setdegreesC * (9/5)+32;

    tempdiff = degreesC - setdegreesC; //difference between desired and measured temperature 

  //check if measured temp is within desired range. Light different LEDs depending on desired temperature difference 
    if(tempdiff<-desiredtemp) //if temp too low
    {
      digitalWrite(bluePin, HIGH);
      digitalWrite(redPin,LOW);
      digitalWrite(greenPin,LOW);
      Serial.print("Status:  Temperature exceeds allowed range and is too cold  ");
    }
    else if(tempdiff>=-desiredtemp && tempdiff <= desiredtemp) //if temp in desired range 
    {
      digitalWrite(greenPin,HIGH);
      digitalWrite(redPin,LOW);
      digitalWrite(bluePin,LOW);
      Serial.print("Status:  Temperature in range  ");
    }
    else //if temp too high
    {
      digitalWrite(redPin,HIGH);
      digitalWrite(bluePin,LOW);
      digitalWrite(greenPin,LOW);
      Serial.print("Status:  Temperature exceeds allowed range and is too hot  ");
    }
  
  //print results 
    Serial.print("voltage: ");
    Serial.print(voltage);
    Serial.print("  deg C: ");
    Serial.print(degreesC);
    Serial.print("  deg F: ");
    Serial.print(degreesF);
    Serial.print("  Set Voltage:  ");
    Serial.print(potentvoltage);
    Serial.print("  Set Degrees C: ");
    Serial.println(setdegreesC);
    
    delay(3000); // repeat once per second (change as you wish!)
}

float getVoltage(int pin)   //Get voltage from analog pins
{
    return (analogRead(pin) * 0.004882814); //converts analog data to true voltage 
}


