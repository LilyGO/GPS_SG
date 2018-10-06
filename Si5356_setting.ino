///// Silicon Labs. Si5656 clock driver///
////  Register values are generated from Clock Builder Pro
////  from Silicon labs. 
////  Current setting are, input 8MHz, output are 10, 20, 30, 40 MHz.
////  kodera2t Oct. 2, 2018
////  GPL, as is, no warranty.

#include <Wire.h>
#define AD_5656 0x70

void i2c_write(byte memory_address, byte value)
{
  Wire.beginTransmission(AD_5656);
  Wire.write(memory_address);
  Wire.write(value);
  Wire.endTransmission();
}


void status_check(byte ad)
{
  byte readval;
  Wire.beginTransmission(AD_5656);
  Wire.write(ad);
  Wire.endTransmission(false);
  Wire.requestFrom(AD_5656, 1);
  while (Wire.available()) {
    readval = Wire.read();
  }
  Serial.print(ad);
  Serial.print(":");
  Serial.println(readval,BIN);
  //Wire.endTransmission();  
}

void status_check2(byte ad)
{
    byte readval;
  Wire.beginTransmission(AD_5656);
  Wire.write(ad);
  Wire.endTransmission(false);
  Wire.requestFrom(AD_5656, 1);
  Serial.print(ad+256);
  Serial.print(":");
    while (Wire.available()) {
    readval = Wire.read();
  }
  Serial.println(readval,BIN);
  Wire.endTransmission();  
}

void check_and_write(byte mem_ad, byte wr_value, byte mask_bit)
{
  byte curr_val,write_value,clear_curr_val,clear_new_val;
  //if(mask_bit != 0xFF){
  Wire.beginTransmission(AD_5656);
  Wire.write(mem_ad);
  Wire.endTransmission(false);
  Wire.requestFrom(AD_5656, 1);
    while (Wire.available()) {
    curr_val = Wire.read();
  }
  delay(10);
  Wire.endTransmission();
  delay(10);
  clear_curr_val = curr_val & (~mask_bit);
  clear_new_val = wr_value & mask_bit;
  write_value = clear_curr_val | clear_new_val;
  //}else{
  //  write_value=wr_value;
  //}
  //Wire.endTransmission(); 
  //delay(10); 
  Wire.beginTransmission(AD_5656);
  //delay(10);
  Wire.write(mem_ad);
  //delay(10);
    //Wire.endTransmission(false);
  Wire.write(write_value);
  //delay(10);
  Wire.endTransmission();
}          


void setup() {
  Wire.begin();
  Wire.setClock(100000);
  Serial.begin(9600);
  check_and_write(230,0x1F,0x1F);
 // i2c_write(230,0xFF);
  i2c_write(241,0x65);

  
  check_and_write(6,0b00011101,0x1D);
//  check_and_write(27,0x70,0x80);
  check_and_write(28,0b00100000,0xFF);
  check_and_write(29,0x20,0xFF);
  check_and_write(30,0b10101000,0xFF);
  ///

  
  
  
  
  
  
  
  
  
  
  
  check_and_write(31,0xC0,0xFF);  
  check_and_write(32,0xC0,0xFF);
  check_and_write(33,0xC0,0xFF);
  check_and_write(34,0xC0,0xFF);
  //check_and_write(35,0x00,0xFF);
  i2c_write(35,0x00);
  check_and_write(36,0x01,0x1F);
  //////
  check_and_write(37,0x01,0x1F);
  check_and_write(38,0x01,0x1F);
  check_and_write(39,0x01,0x1F);
  check_and_write(40,0xF7,0xFF); 
  check_and_write(41,0x5E,0x7F);  
  check_and_write(42,0x37,0x3F);
  check_and_write(47,0x14,0xFC);
  check_and_write(48,0x3E,0x1D);
  check_and_write(49,0x95,0xFF);//////////////////
  check_and_write(50,0xDE,0xFF);   
  check_and_write(51,0x07,0x07);
//
///////////////////////////////////
  check_and_write(52,0x1C,0x0C);
  check_and_write(53,0xE3,0xFF);
  check_and_write(54,0x6B,0xFF);
  check_and_write(55,0x3C,0xFF);
  check_and_write(56,0x01,0xFF);
  check_and_write(57,0x00,0xFF);
  check_and_write(58,0x00,0xFF);
  check_and_write(59,0x5B,0xFF);
  check_and_write(60,0x00,0xFF);  
  check_and_write(61,0x00,0xFF);  
  check_and_write(62,0x00,0xFF);
  check_and_write(63,0x1C,0x0C);
  check_and_write(64,0xF1,0xFF);
  check_and_write(65,0x34,0xFF);
  check_and_write(66,0x54,0xFF);
  check_and_write(67,0x01,0xFF);
  check_and_write(68,0x00,0xFF);
  check_and_write(69,0x00,0xFF);
  check_and_write(70,0x5B,0xFF);  
  check_and_write(71,0x00,0xFF);  
  check_and_write(72,0x00,0xFF);
  check_and_write(73,0x00,0x3F);
  check_and_write(74,0x1C,0x0C);
  check_and_write(75,0xA1,0xFF);
  check_and_write(76,0x22,0xFF);
  check_and_write(77,0x3C,0xFF);
  check_and_write(78,0x01,0xFF);
  check_and_write(79,0x00,0xFF);
  check_and_write(80,0x00,0xFF);  
  check_and_write(81,0x11,0xFF);  
  check_and_write(82,0x01,0xFF);
  check_and_write(83,0x00,0xFF);
  check_and_write(84,0x00,0x3F);
  check_and_write(85,0x1C,0x0C);
  check_and_write(86,0x78,0xFF);
  check_and_write(87,0x19,0xFF);
  check_and_write(88,0x60,0xFF);
  check_and_write(89,0x01,0xFF);
  check_and_write(90,0x00,0xFF);  
  check_and_write(91,0x00,0xFF);  
  check_and_write(92,0x5B,0xFF);
  check_and_write(93,0x00,0xFF);
  check_and_write(94,0x00,0xFF);
  check_and_write(95,0x00,0x3F);
  
  check_and_write(97,0x80,0xFF);
  check_and_write(98,0x87,0xFF);
  check_and_write(99,0x00,0xFF);
  check_and_write(100,0x00,0xFF);  
  check_and_write(101,0x00,0xFF);  
  check_and_write(102,0x00,0xFF);
  check_and_write(103,0x01,0xFF);
  check_and_write(104,0x00,0xFF);
  check_and_write(105,0x00,0xFF);
  check_and_write(106,0x80,0x8F);
  check_and_write(107,0x00,0xFF);
  check_and_write(108,0x00,0x7F);

  check_and_write(110,0xC0,0xC0);  
  check_and_write(111,0x00,0xFF);  
  check_and_write(112,0x00,0x7F);

  check_and_write(114,0xC0,0xC0);
  check_and_write(115,0x00,0xFF);
  check_and_write(116,0x80,0x7F);

  check_and_write(118,0xC0,0xC0);
  check_and_write(119,0x00,0xFF);  
  check_and_write(120,0x00,0xFF); 

  check_and_write(122,0xC0,0xC0); 

  check_and_write(129,0x00,0x0F);
  check_and_write(130,0x00,0x0F); 

  check_and_write(144,0x80,0x80); 

  check_and_write(158,0x00,0x0F);
  check_and_write(159,0x00,0x0F);

  check_and_write(181,0x00,0x0F);
  check_and_write(203,0x00,0x0F);
  check_and_write(241,0x65,0xFF);  
  check_and_write(247,0x00,0xFF);    
  check_and_write(255,1,0xFF);///page bit to 1
  check_and_write(31,0x00,0xFF);  
  check_and_write(32,0x00,0xFF);
  check_and_write(33,0x01,0xFF);
  check_and_write(34,0x00,0xFF);
  check_and_write(35,0x00,0xFF);
  //i2c_write(35,0x00);
  check_and_write(36,0x30,0xFF);
  //////
  check_and_write(37,0x05,0xFF);
  check_and_write(38,0x88,0xFF);
  check_and_write(39,0x13,0xFF);
  check_and_write(40,0x82,0xFF); 
  check_and_write(41,0x39,0xFF); 
  check_and_write(49,0x01,0xFF); 
  check_and_write(52,0x90,0xFF); 
  check_and_write(53,0x0A,0xFF); 
  check_and_write(54,0xE2,0xFF); 
  check_and_write(55,0x04,0xFF);
  check_and_write(56,0x82,0xFF);
  check_and_write(57,0x39,0xFF);    
  check_and_write(65,0x01,0xFF);
  check_and_write(68,0x90,0xFF); 
  check_and_write(69,0x31,0xFF); 
  check_and_write(72,0x01,0xFF);  
  check_and_write(84,0x90,0xFF); 
  check_and_write(85,0x31,0xFF); 
  check_and_write(88,0x31,0xFF); 
  check_and_write(255,0,0xFF);///page bit to 0    






        
  i2c_write(246,0x02);
  i2c_write(246,0x00);
//
  //check_and_write(226,4,0xFF);
  //delay(10);
  //check_and_write(226,0,0xFF);

  
  //check_and_write(230,0x00,0xFF);
    check_and_write(230,0x00,0x1F);

    //i2c_write(230,0x00);
  //i2c_write(230,0x00);
   // i2c_write(241,0x65);
     for(int j=1;j<3;j++){
      
    for(int i=0;i<256;i++){
  status_check(i);
  }
  i2c_write(255,1);
      for(int i=0;i<256;i++){
  status_check2(i);
  }
  i2c_write(255,0);
     }
}

void loop() {
     // i2c_write(226,0x00);
//  status_check(226);
//  status_check(218); 
//  status_check(241); 
//   status_check(246); 
//    status_check(247); 
//  //check_and_write(246,2,2); 
//    //status_check(246); 
//  delay(1000);
  // put your main code here, to run repeatedly:

}
