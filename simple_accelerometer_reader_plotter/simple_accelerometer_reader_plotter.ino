int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read

int x[] = {0, 0, 0, 0, 0, 0};
int y[] = {0, 0, 0, 0, 0, 0};
int z[] = {0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);           //  setup serial 

  while(!Serial) {
    ;           //wait for connection to begin broadcasting data
  }
  
}

void loop() {

  int counter = 0;

  if(counter == 0) {
    for(int i=0;i<6; i++){
      x[i] = analogRead(A1);
      y[i] = analogRead(A2);
      z[i] = analogRead(A3);
    }
  }
    
  int j = counter % 6;

  int means[] = {0, 0, 0};

  for(int i=0;i<6;i++){
    means[0] += x[i];
    means[1] += y[i];
    means[2] += z[i];
  }

  means[0] /= 6;
  means[1] /= 6;
  means[2] /= 6;

  int diffs[] = {0, 0, 0};

  diffs[0] = analogRead(A1) - means[0];
  diffs[1] = analogRead(A2) - means[1];
  diffs[2] = analogRead(A3) - means[2];
  
  
  //The accel variable is the acceleration in Newtons, output is initially in volts
  //with 5000 milli-volts split over 1024 bits. 300 mV of output equates to one g of acceleration,
  //Which is the equivalent of 9.81 m/sec^2
  double accel = sqrt(diffs[0]*diffs[0] + diffs[1]*diffs[1] + diffs[2]*diffs[2]) * 5000 / 1023 * 9.81 / 300; 
  Serial.println(accel);
  
  
  
  x[j] = analogRead(A1);  // read the input pin
  y[j] = analogRead(A2);
  z[j] = analogRead(A3);

  

  
  //Serial.print("X = "); Serial.println(x);
  //Serial.print("Y = "); Serial.println(y);
  //Serial.print("Z = "); Serial.println(z);
  //Serial.println("======================");

  
  
  
  //delay(20);

  
}
