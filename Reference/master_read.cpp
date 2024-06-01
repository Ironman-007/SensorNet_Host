#include
<Wire.h>




// Array of node addresses

byte NODE_ADDRESSES[] = {0x04};

//byte NODE_ADDRESSES[] = {0x08, 0x09, 0x0A};

int NUM_NODES = sizeof(NODE_ADDRESSES)
 / sizeof(NODE_ADDRESSES[0]);

//int NUM_NODES = 11;




void
setup()
{

   Serial.begin(9600);
  // start serial for output

  while
(!Serial);

  Serial.println("TEST");




  Wire.begin();




   byte error, address;

  int nDevices;

 

  Serial.println("Scanning...");

 

  nDevices = 0;

  for(address =
1; address <
127; address++
)

  {

    // The i2c_scanner uses the return value of

    // the Write.endTransmisstion to see if

    // a device did acknowledge to the address.

    Wire.beginTransmission(address);

    error = Wire.endTransmission();

 

    if
(error ==
0)

    {

      Serial.print("I2C
 device found at address 0x");

      if
(address<16)

        Serial.print("0");

      Serial.print(address,HEX);

      Serial.println("
  !");

 

      nDevices++;

    }

    else
if
(error==4)

    {

      Serial.print("Unknown
 error at address 0x");

      if
(address<16)

        Serial.print("0");

      Serial.println(address,HEX);

    }    

  }

  if
(nDevices ==
0)

    Serial.println("No
 I2C devices found\n");

  else

    Serial.println("done\n");

}




void
loop()
{

  for
(int node =
0; node < NUM_NODES; node++)
{

    byte NODE_ADD = NODE_ADDRESSES[node];




    Wire.beginTransmission(NODE_ADD);

    if
(Wire.endTransmission())
{

      Serial.print("Node_");

      Serial.print(NODE_ADD,
 HEX);

      Serial.print("_Not_found");

      delay(100);

      continue;  // Skip this iteration if node is not found

    }

    Wire.requestFrom(NODE_ADD,
56);  // request 56 bytes from the current node




    byte i = 0;

    byte c[56];




    while
(Wire.available())
{

      c[i++] =
Wire.read();
  // receive a byte as character

    }




    uint8_t deviceID, tempimu, proximity;

    uint16_t  ambient, red, green, blue;

    float temp, pres, hum;

    float quat_w, quat_x, quat_y, quat_z, accel_x, accel_y, accel_z, magnet_x, magnet_y, magnet_z;




    deviceID = c[0];

    Serial.print(deviceID);Serial.print(",");

    if(deviceID ==4)

    {//bot,right,top, left

      Serial.print(0);Serial.print(",");

      Serial.print(0);Serial.print(",");

      Serial.print(0);Serial.print(",");

      Serial.print(5);Serial.print(",");

      Serial.print(0);Serial.print(",");

      Serial.print(0);Serial.print(",");

    }




    proximity = c[1];

    ambient = (c[3]<<8)
 + c[2];

    red = (c[5]<<8)
 + c[4];

    green = (c[7]<<8)
 + c[6];

    blue = (c[9]<<8)
 + c[8];

    Serial.print(proximity);Serial.print(",");

    Serial.print(ambient);Serial.print(",");

    Serial.print(red);Serial.print(",");

    Serial.print(green);Serial.print(",");

    Serial.print(blue);Serial.print(",");






    temp = ((float)((c[11]<<8)
 + c[10]))/100;

    pres = ((float)((c[13]<<8)
 + c[12]))/100;

    hum = ((float)((c[15]<<8)
 + c[14]))/100;

    Serial.print(temp);Serial.print(",");

    Serial.print(pres);Serial.print(",");

    Serial.print(hum);Serial.print(",");




    quat_w = ((float)((c[19]<<24)
 + (c[18]<<16)
 + (c[17]<<8)
 + c[16]))/100;

    quat_x = ((float)((c[23]<<24)
 + (c[22]<<16)
 + (c[21]<<8)
 + c[20]))/100;

    quat_y = ((float)((c[27]<<24)
 + (c[26]<<16)
 + (c[25]<<8)
 + c[24]))/100;

    quat_z = ((float)((c[31]<<24)
 + (c[30]<<16)
 + (c[29]<<8)
 + c[28]))/100;

    Serial.print(quat_w);Serial.print(",");

    Serial.print(quat_x);Serial.print(",");

    Serial.print(quat_y);Serial.print(",");

    Serial.print(quat_z);Serial.print(",");




    accel_x = ((float)((c[35]<<24)
 + (c[34]<<16)
 + (c[33]<<8)
 + c[32]))/100;

    accel_y = ((float)((c[39]<<24)
 + (c[38]<<16)
 + (c[37]<<8)
 + c[36]))/100;

    accel_z = ((float)((c[43]<<24)
 + (c[42]<<16)
 + (c[41]<<8)
 + c[40]))/100;

    Serial.print(accel_x);Serial.print(",");

    Serial.print(accel_y);Serial.print(",");

    Serial.print(accel_z);Serial.print(",");




    magnet_x = ((float)((c[47]<<24)
 + (c[46]<<16)
 + (c[45]<<8)
 + c[44]))/100;

    magnet_y = ((float)((c[51]<<24)
 + (c[50]<<16)
 + (c[49]<<8)
 + c[48]))/100;

    magnet_z = ((float)((c[55]<<24)
 + (c[54]<<16)
 + (c[53]<<8)
 + c[52]))/100;

    Serial.print(magnet_x);Serial.print(",");

    Serial.print(magnet_y);Serial.print(",");

    Serial.print(magnet_z);Serial.print("
 ");

    Serial.println();

  }

    //Serial.println();

    delay(50);
  // Delay before communicating with the next node

}