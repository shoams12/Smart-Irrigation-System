void connectToWifi(){
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)// checks the connection status and continues until the connection is successful
    delay(500);
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: "); 
  Serial.println(WiFi.localIP());//retrieves the IP address assigned to the microcontroller by the WiFi network
}
