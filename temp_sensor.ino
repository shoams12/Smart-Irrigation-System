//temperature sensor
void configTemp(byte add) {
    Wire.beginTransmission(add);//Begins a transmission to the I2C device with the address
    Wire.write(0x0);//sets the pointer to the temperture register
    Wire.endTransmission();//sends the data to the device and ends the transmission
}

float readTemp(int add) {

  float temp;
 
  Wire.requestFrom(add, 2);//Requests 2 bytes of data from the sensor

  if(Wire.available()) {                                   // 0.125 to convert it to a temperature value
   temp = ((Wire.read() << 8 | Wire.read()) >> 5) * 0.125;// shifts the high byte left by 8 bits,second read- The combined value is then right-shifted by 5 bits,
   return temp;
  }
}

bool is_open_roof() {

   valtemp = readTemp(LM75_addr);//reads from the address
   Serial.println("Temperature = "+String(valtemp));

  if(valtemp >= 28){//32
    return true;
  }

  else {
    return false;
  }

}
String return_temp(){
   valtemp = readTemp(LM75_addr);
   Serial.println("Temperature = "+String(valtemp));
   return String(valtemp);
}