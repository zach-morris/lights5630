// Define the pins we're going to call pinMode on
int light1 = D0;  // First light string
int light2 = D1; // Second light string
int light3 = D2;  // Third light string
int light4 = D3; // Fourth light string

int lightcmd(String command);
int offonoffdelay = 850; //Variable for delayed cycle
int offonoffdelay2 = 250; //Variable for delayed cycle
int offonoffdelay1 = 50; //Variable for delayed cycle
int resultint = 0;  //Variable to determine what the heck is going on
int stopit = 0;  //Variable to stop while loop
int inprog = 0; //Checking if game is in progress
int lastcmdsync = 0;  //Determine if the last command was just an idle timeout to on command

String resultstr = "Default";  //Variable to determine what the heck is going on


unsigned long lastPlay = millis();

int rndom(int minVal, int maxVal)  //Function to create random number between minval and maxval
{
  return rand() % (maxVal-minVal+1) + minVal;
}


// This routine runs only once upon reset
void setup() {
    //Register our Spark function here
    Particle.function("lightcmd", lightcmd);
    Particle.variable("resultint", &resultint, INT);
    Particle.variable("resultstr", &resultstr, STRING);

    // Initialize outputs
    pinMode(light1, OUTPUT);
    pinMode(light2, OUTPUT);
    pinMode(light3, OUTPUT);
    pinMode(light4, OUTPUT);
    
    //Initialize outputs OFF
    digitalWrite(light1, LOW);
    digitalWrite(light2, LOW);
    digitalWrite(light3, LOW);
    digitalWrite(light4, LOW);
    
}

// This routine loops forever
void loop()
{
  //Turn the lights back on if someone hasn't played in a one minute
  if(stopit<1 && lastcmdsync<1){
    if ((millis()-lastPlay) > 60000) {
      digitalWrite(light1, HIGH);
      digitalWrite(light2, HIGH);
      digitalWrite(light3, HIGH);
      digitalWrite(light4, HIGH);
      lastPlay = millis();
      lastcmdsync = 1;
      resultint = 9000;  //Restarted and ready
    }
  }
}

//Light commander on and off
int lightcmd(String command)
{
  resultint = 9001;  //Commanded to RUN


  if(command == "resetall"){
  resultint = 9002;  //Reset All
  stopit = 0;
  //Initialize them OFF
  digitalWrite(light1, LOW);
  digitalWrite(light2, LOW);
  digitalWrite(light3, LOW);
  digitalWrite(light4, LOW);
  }
  if(command == "stopall"){
  resultint = 9003;  //Stop All
  stopit = 1;
  //Initialize them OFF
  digitalWrite(light1, LOW);
  digitalWrite(light2, LOW);
  digitalWrite(light3, LOW);
  digitalWrite(light4, LOW);
  }
  if(inprog<1 && stopit<1){
    if(command == "light1ON"){
      inprog = 1;
      resultint = 1001;
      digitalWrite(light1, HIGH);
    }
    if(command == "light1OFF"){
      inprog = 1;
      resultint = 1002;
      digitalWrite(light1, LOW);
    }
    if(command == "light2ON"){
      inprog = 1;
      resultint = 2001;
      digitalWrite(light2, HIGH);
    }
    if(command == "light2OFF"){
      inprog = 1;
      resultint = 2002;
      digitalWrite(light2, LOW);
    }
    if(command == "light3ON"){
      inprog = 1;
      resultint = 3001;
      digitalWrite(light3, HIGH);
    }
    if(command == "light3OFF"){
      inprog = 1;
      resultint = 3002;
      digitalWrite(light3, LOW);
    }
    if(command == "light4ON"){
      inprog = 1;
      resultint = 4001;
      digitalWrite(light4, HIGH);
    }
    if(command == "light4OFF"){
      inprog = 1;
      resultint = 4002;
      digitalWrite(light4, LOW);
    }
    if(command == "light1C"){
      inprog = 1;
      resultint = 1003;
      digitalWrite(light1, LOW);
      delay(offonoffdelay1);
      digitalWrite(light1, HIGH);
      delay(offonoffdelay);
      digitalWrite(light1, LOW);
      delay(offonoffdelay2);
    }
    if(command == "light2C"){
      inprog = 1;
      resultint = 2003;
      digitalWrite(light2, LOW);
      delay(offonoffdelay1);
      digitalWrite(light2, HIGH);
      delay(offonoffdelay);
      digitalWrite(light2, LOW);
      delay(offonoffdelay2);
    }
    if(command == "light3C"){
      inprog = 1;
      resultint = 3003;
      digitalWrite(light3, LOW);
      delay(offonoffdelay1);
      digitalWrite(light3, HIGH);
      delay(offonoffdelay);
      digitalWrite(light3, LOW);
      delay(offonoffdelay2);
    }
    if(command == "light4C"){
      inprog = 1;
      resultint = 4003;
      digitalWrite(light4, LOW);
      delay(offonoffdelay1);
      digitalWrite(light4, HIGH);
      delay(offonoffdelay);
      digitalWrite(light4, LOW);
      delay(offonoffdelay2);
    }
    
    if(command == "alllightsON"){
      inprog = 1;
      resultint = 9004;  //All Lights On
      digitalWrite(light1, HIGH);
      digitalWrite(light2, HIGH);
      digitalWrite(light3, HIGH);
      digitalWrite(light4, HIGH);
    }
    if(command == "alllightsOFF"){
      inprog = 1;
      resultint = 9005;  //All lights Off
      digitalWrite(light1, LOW);
      digitalWrite(light2, LOW);
      digitalWrite(light3, LOW);
      digitalWrite(light4, LOW);
      lastcmdsync = 0;
      lastPlay = millis();
    }
    inprog = 0;
  }
  //Random light show
  if(command == "randomlightshow"){
    while(stopit<1)
    {
      lastPlay = millis();
      resultint = 9006;  //Random Light Show
      int fast_slow = 2000; //Make this number faster or slower
      int minn_time = 500;  //Smallest number to allow
      int rndom_num1 = rndom(minn_time,fast_slow);  // Random time to turn on and off
      int rndom_num2 = rndom(minn_time,fast_slow);
      int rndom_num3 = rndom(minn_time,fast_slow);
      int rndom_num4 = rndom(minn_time,fast_slow);
      int rndom_num5 = rndom(minn_time,fast_slow);
      int rndom_num6 = rndom(minn_time,fast_slow);
      int rndom_num7 = rndom(minn_time,fast_slow);
      int rndom_num8 = rndom(minn_time,fast_slow);

     int rndom_onoff1 = rndom(0,1); // For IF statement to turn on or off
     int rndom_onoff2 = rndom(0,1);
     int rndom_onoff3 = rndom(0,1);
     int rndom_onoff4 = rndom(0,1);
     int rndom_onoff5 = rndom(0,1);
     int rndom_onoff6 = rndom(0,1);
     int rndom_onoff7 = rndom(0,1);
     int rndom_onoff8 = rndom(0,1);

     //Switch the lights
     if(rndom_onoff1 == 1) {
      digitalWrite(light1, HIGH);
      delay(rndom_num1);
    }
    if(rndom_onoff2 == 1) {
      digitalWrite(light2, HIGH);
      delay(rndom_num2);
    }
    if(rndom_onoff3 == 1) {
      digitalWrite(light3, HIGH);
      delay(rndom_num3);
    }
    if(rndom_onoff4 == 1) {
      digitalWrite(light4, HIGH);
      delay(rndom_num4);
    }
    if(rndom_onoff5 == 1) {
      digitalWrite(light1, LOW);
      delay(rndom_num5);
    }
    if(rndom_onoff6 == 1) {
      digitalWrite(light2, LOW);
      delay(rndom_num6);
    }
    if(rndom_onoff7 == 1) {
      digitalWrite(light3, LOW);
      delay(rndom_num7);
    }
    if(rndom_onoff8 == 1) {
      digitalWrite(light4, LOW);
      delay(rndom_num8);
    }
  }
  stopit = 0;  //Reset after your out of the loop
}
if(command == "synctest"){
  int delay_start = 0;
  while(stopit<1)
  {
    resultint= 9007; //Sync Test
    delay(delay_start);
    digitalWrite(light2, HIGH); digitalWrite(light1, LOW);  digitalWrite(light3, LOW);  digitalWrite(light4, LOW);
    delay(157); digitalWrite(light2, LOW);
    delay(482); digitalWrite(light3, HIGH);     
    delay(215); digitalWrite(light3, LOW);      
    delay(423); digitalWrite(light4, HIGH);     
    delay(214); digitalWrite(light4, LOW);      
    delay(424); digitalWrite(light1, HIGH);     
    delay(471); digitalWrite(light1, LOW);
    stopit = 1;  //Just get out of the loop
  }
  stopit = 0;  //Allow the next song to run
}
return(resultint);
}