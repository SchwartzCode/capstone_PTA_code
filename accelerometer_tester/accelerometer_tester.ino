int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read

int x[] = {0, 0, 0, 0, 0, 0};
int y[] = {0, 0, 0, 0, 0, 0};
int z[] = {0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);           //  setup serial 
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
  
  int bound = 50;
  if(diffs[0] > bound || diffs[0] < -bound){
    Serial.print("X_DIFF: "); Serial.println(diffs[0]);
  }
  if(diffs[1] > bound || diffs[1] < -bound){
    Serial.print("Y_DIFF: "); Serial.println(diffs[1]);
  }
  if(diffs[2] >  bound|| diffs[2] < -bound){
    Serial.print("Z_DIFF: "); Serial.println(diffs[2]);
  }
  
  
  x[j] = analogRead(A1);  // read the input pin
  y[j] = analogRead(A2);
  z[j] = analogRead(A3);

  

  
  //Serial.print("X = "); Serial.println(x);
  //Serial.print("Y = "); Serial.println(y);
  //Serial.print("Z = "); Serial.println(z);
  //Serial.println("======================");

  
  
  
  //delay(20);

  
}
