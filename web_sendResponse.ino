
void sendResponse() {
  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();

  client.println("<!DOCTYPE html>");
  client.println("<html lang=\"en\">");
  client.println("<head>");
  client.println("<meta charset=\"UTF-8\">");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
  client.println("<title>Document</title>");
  client.println("<style>");
  client.println("body{ background-color: burlywood; font-size: 20px; }");
  client.println("h1{ margin-left: 25%; color: rgb(58, 108, 8); }");
  client.println("div{ font-size: 30px; margin: 7%; margin-left: 30%; }");
  client.println("#moisture, #light, #shed { border: 3px solid rgb(135, 80, 7); width: 400px; }");
  client.println("#tmprtr{ text-align: center; background-color: rgb(161, 108, 38); width: 200px; height: 130px; }");
  client.println("h4{ font-size: 25px; color: rgb(110, 206, 15); text-shadow: 2px 2px 4px rgba(0,0,0,0.5); }");
  client.println("#weather{ text-align: center; background-color: rgb(161, 108, 38); width: 200px; height: 130px; margin-left: 45%; margin-top: -15.5%; }");
  client.println("#auto_mode{ color:rgb(110, 206, 15) ; text-shadow: 2px 2px 4px rgba(0,0,0,0.5); background-color: rgb(161, 108, 38); border-radius: 10%; width: 150px;}");
  client.println("input{ width:110px; height: 70px; margin: 3%; margin-left: 15%; }");
  client.println("#on{ background-color: rgb(84, 161, 191); color: rgb(235, 242, 101); border-radius: 10%; }");
  client.println("#off{ background-color: rgb(14, 13, 37); color: aliceblue; border-radius: 10%; }");
  client.println("</style>");
  client.println("<script>");
  client.println("function ChangeState(state, divId) {");
  client.println("let writeToDiv = document.getElementById(divId);");
  client.println("if (state === 'on') { writeToDiv.innerHTML = 'on'}");
  client.println("else if (state === 'off') { writeToDiv.innerHTML = 'off'; } }");
  
  client.println("function change(){");
  client.println("let writeToDiv = document.getElementById('auto');");
  client.println("if(writeToDiv.innerHTML == 'on'){");
  client.println("writeToDiv.innerHTML = 'off';");
  client.println("} else {");
  client.println("writeToDiv.innerHTML = 'on';");
  client.println("}");
  client.println("}");
  
  client.println("function open_shed(){fetch('/roof_open')}");
  client.println("function close_shed(){fetch('/roof_close')}");
  client.println("function lighton(){fetch('/light_on')}");
  client.println("function lightoff(){fetch('/light_off')}");
  client.println("function auto_mode(){fetch('/auto_mode')}");
  client.println("</script>");
  client.println("</head>");
  client.println("<body>");
  client.println("<h1>Welcome to your planting system</h1>");
  client.println("<input id=\"auto_mode\" type=\"button\" value=\"Turn On Auto Mode\" onclick=\" auto_mode(); \"></div>");
  client.println("<div id=\"tmprtr\"><h4>Current Plant Temperature:</h4><div>" + return_temp() + "</div></div>");
  client.println("<div id=\"weather\"><h4>Weather:</h4><div>" + return_weather() + "</div></div>");
  client.println("<div id=\"light\"><label for=\"l\">Light Levels:</label><div>" + ligthLevel + "</div>");
  client.println("<input id=\"on\" type=\"button\" value=\"ON\" onclick=\"ChangeState('on', 'lightdiv'); lighton();\">");
  client.println("<input id=\"off\" type=\"button\" value=\"OFF\" onclick=\"ChangeState('off', 'lightdiv'); lightoff();\">");
  client.println("<div>Light:</div><div id=\"lightdiv\"></div></div>");
  client.println("<div id=\"shed\"><label for=\"l\">Roof State:</label><div id=\"state\">-</div>");
  client.println("<input id=\"on\" type=\"button\" value=\"Open\" onclick=\"ChangeState('off', 'state'); open_shed();\">");
  client.println("<input id=\"off\" type=\"button\" value=\"Close\" onclick=\"ChangeState('on', 'state'); close_shed();\"></div>");//working
  client.println("</body>");
  client.println("</html>");
}