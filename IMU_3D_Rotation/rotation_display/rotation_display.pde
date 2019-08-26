import processing.serial.*;
Serial myPort;
String val; 

void setup()
{
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
    myPort = new Serial(this, portName, 9600);
  size(640,360,P3D);
  
  //lights();
  delay(200);
}

int count = 0;
float[] angles = new float[3];

void draw()
{  
   background(0);
  if ( myPort.available() > 0) 
  {  
    val = myPort.readStringUntil('\n');         // read it and store it in val
    if(val != null)
    {
      angles[count] = float(val);
      //print(count + ":" + angles[count] + " ");
      count++;
    }
        if (count == 3)
    {
    
    //for(int i= 0; i<3; i++)
    //if(angles[i] == Double.NaN)
    //break;
    
       for(int i= 0; i<3; i++)
          print(i + ":" + angles[i] + " ");
       
      pushMatrix();
      translate(320, height/2, 0);
      rotateX(radians(angles[1]));
      rotateY(radians(angles[2]));
      rotateZ(radians(angles[0]));
      //noStroke();
      box(200, 20, 100);
      popMatrix();
      count = 0;
       
       count = 0;
       print('\n');
    
    }
    //if(count == 3)
    //{
    //  count = 0;
    //  print('\n');
    //  for(int i= 0; i<3; i++)
    //  print(angles[i] + " ");
      
    //  pushMatrix();
    //  translate(320, height/2, 0);
    //  rotateX(angles[0]);
    //  rotateY(angles[1]);
    //  rotateZ(angles[2]);
    //  //noStroke();
    //  box(100);
    //  popMatrix();
    //  count = 0;
    //}  
  } 
 //print it out in the console
}
