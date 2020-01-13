void App_Wifi()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  
      delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    if (i == "ONLED") {
      digitalWrite(D1,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("ON");
      client.println("</html>");
      client.stop();
      delay(1);
    }
    if (i == "OFFLED") {
      digitalWrite(D1,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("OFF");
      client.println("</html>");
      Serial.print("OFF");
      client.stop();
      delay(1);

    }
   if (i == "ONFAN") {
      digitalWrite(D2,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("ON");
      client.println("</html>");
      client.stop();
      delay(1);
    }
    if (i == "OFFFAN") {
      digitalWrite(D2,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("OFF");
      client.println("</html>");
      Serial.print("OFF");
      client.stop();
      delay(1);

    }
   if (i == "ONTUBE") {
      digitalWrite(D3,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("ON");
      client.println("</html>");
      client.stop();
      delay(1);
    }
    if (i == "OFFTUBE") {
      digitalWrite(D3,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("OFF");
      client.println("</html>");
      Serial.print("OFF");
      client.stop();
      delay(1);

    }
   if (i == "ONSOCKET") {
      digitalWrite(D4,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("ON");
      client.println("</html>");
      client.stop();
      delay(1);
    }
    if (i == "OFFSOCKET") {
      digitalWrite(D4,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("OFF");
      client.println("</html>");
      Serial.print("OFF");
      client.stop();
      delay(1);

    }
   if (i == "ONOTHERS") {
      digitalWrite(D5,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("ON");
      client.println("</html>");
      client.stop();
      delay(1);
    }
    if (i == "OFFOTHERS") {
      digitalWrite(D5,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("OFF");
      client.println("</html>");
      Serial.print("OFF");
      client.stop();
      delay(1);

    }
}
