bool ldr_sensor() {

  int analogReadPin;
  String print_str;

  analogReadPin = analogRead(LDR);//

  print_str = "ldr is: " + String(analogReadPin);
 
// Less light, more resistance
  if (analogReadPin < 2000){
   ligthLevel= "dark outside"; 
    return true;}

  else{
  ligthLevel= "light outside";
    return false;}
}
