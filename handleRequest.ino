void handleTheRequest(){
    
    request = client.readStringUntil('\r');
    Serial.println(request);
    
    if (request.indexOf("/roof_open") != -1) {
        // Open the roof
         web_control_flag = true;
         close_roof_servo();
       
    } else if (request.indexOf("/roof_close") != -1) {
        // Close the roof
        web_control_flag = true; // Activate web control
         open_roof_servo();
        
    } 
    else if (request.indexOf("/light_on") != -1) {
        // Turn on the light
        web_control_flag = true; // Activate web control
        led_on();
    } else if (request.indexOf("/light_off") != -1) {
        // Turn off the light
        web_control_flag = true; // Activate web control 
        led_off();
    } else if (request.indexOf("/auto_mode") != -1) {
        web_control_flag = false; // Deactivate web control, back to auto mode
    }

}