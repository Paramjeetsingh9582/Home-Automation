void BT_connect(){
  if(Serial.available() > 0)  // Send data only when you receive data:
{
data = Serial.read();      //Read the incoming data and store it into variable data
Serial.print(data);        //Print Value inside data in Serial monitor
Serial.print(" ");        //New line 
      
if(data == 'L')            //Checks whether value of data is equal to 1 
digitalWrite(D1, HIGH);  //If value is 1 then LED turns ON
else if(data == 'l')       //Checks whether value of data is equal to 0
digitalWrite(D1, LOW);   //If value is 0 then LED turns OFF

if(data == 'F')            //Checks whether value of data is equal to 1 
digitalWrite(D2, HIGH);  //If value is 1 then LED turns ON
else if(data == 'f')       //Checks whether value of data is equal to 0
digitalWrite(D2, LOW);   //If value is 0 then LED turns OFF}                            

if(data == 'T')            //Checks whether value of data is equal to 1 
digitalWrite(D3, HIGH);  //If value is 1 then LED turns ON
else if(data == 't')       //Checks whether value of data is equal to 0
digitalWrite(D3, LOW);   //If value is 0 then LED turns OFF}                            

if(data == 'S')            //Checks whether value of data is equal to 1 
digitalWrite(D4, HIGH);  //If value is 1 then LED turns ON
else if(data == 's')       //Checks whether value of data is equal to 0
digitalWrite(D4, LOW);   //If value is 0 then LED turns OFF}                            

if(data == 'O')            //Checks whether value of data is equal to 1 
digitalWrite(D5, HIGH);  //If value is 1 then LED turns ON
else if(data == 'o')       //Checks whether value of data is equal to 0
digitalWrite(D5, LOW);   //If value is 0 then LED turns OFF}                            

} 
} 
