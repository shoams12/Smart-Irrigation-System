// // //water level sensor
bool water_container_sensor(){
  resval = analogRead(WATER_PIN); //Read data from analog pin 
  Serial.print("water state: ");
  Serial.println(resval);

   if (resval<=150||(resval>1500 && resval<=1900)) {
   Serial.println("Water Level: Low"); 
   return true;
  } 
     

  else if (resval>2150 ||(resval>1900 && resval<=2010)) { 
    Serial.println("Water Level: High"); 
    return false;
  }
  return false;
  
}

bool rain_detect(){
   rainval=analogRead(WATER_SENSOR_RAIN);
  if (rainval>2000 ){
    //  is_roof_open_flag = false;
     return true;
     }
  else{ 
    // is_roof_open_flag = true;
    return false;}
 
}
String return_weather(){
  if(rain_detect()){
    return "It's raining";}
    else {
      return "Weather is nice";}
}