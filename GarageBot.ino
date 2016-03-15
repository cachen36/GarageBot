// Set-up variables, Pin D1 will control the door relay and Pin D4 will check whether the door is open or closed
int door = D1;
int status = D4;

int statusvalue;


void setup()
{
// Sets the door relay pin as an output and the status pin as an input
   pinMode(door, OUTPUT);
   pinMode(status, INPUT);

// This sets up a Spark function that will recieve the open/close command from the Spark Cloud.
   Spark.function("led",doorToggle);

// This sets the initail condition of the relay.  It is off by default.
   digitalWrite(door, LOW);

//  This sends the door status open/closed to the Spark Cloud.
   Spark.variable("status", &statusvalue, INT);

}

void loop()
{
// Constantly checks the status of the door (open or closed).
    statusvalue = digitalRead(status);

}

// This gets called if the Spark Cloud commands a door open/close
int doorToggle(String command) {

// If the command is "on" the relay closes for 1 second and then opens again.
// You may have to adjust the delay depending on your garage door opener.
    if (command=="on") {
        digitalWrite(door,HIGH);
        delay(1000);
        digitalWrite(door,LOW);
        return 1;
    }
    else if (command=="off") {
        digitalWrite(door,LOW);
        return 0;
    }
    else {
        return -1;
    }
}
