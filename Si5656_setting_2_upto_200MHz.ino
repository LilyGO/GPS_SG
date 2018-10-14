///// Silicon Labs. Si5656 clock driver///
////  Register values are generated from Clock Builder Pro
////  from Silicon labs. 
////  Current setting are, input 8MHz, output are 10, 20, 100, 200 MHz.
////  kodera2t Oct. 14, 2018
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
  Wire.beginTransmission(AD_5656);
  Wire.write(ad);
  Wire.requestFrom(AD_5656, 1);
  Serial.print(ad);
  Serial.print(":");
  Serial.println(Wire.read(),BIN);
  Wire.endTransmission();  
}

void check_and_write(byte mem_ad, byte wr_value, byte mask_bit)
{
  byte curr_val,write_value,clear_curr_val,clear_new_val;
  Wire.beginTransmission(AD_5656);
  Wire.write(mem_ad);
  Wire.endTransmission(false);
  Wire.requestFrom(AD_5656, 1);
  curr_val = Wire.read();
  //delay(5);
  Wire.endTransmission(true);
  //delay(5);
  clear_curr_val = curr_val & (~mask_bit);
  clear_new_val = wr_value & mask_bit;
  write_value = clear_curr_val | clear_new_val;
  Wire.beginTransmission(AD_5656);
  //delay(5);
  Wire.write(mem_ad);
  //delay(5);
    Wire.endTransmission(false);
  Wire.write(write_value);
  //delay(5);
  Wire.endTransmission(true);
}          


void setup() {
  Wire.begin();
  Serial.begin(9600);
  i2c_write(230,0xFF);
  i2c_write(241,0x65);

  
  i2c_write(6,0x04);
  //i2c_write(27,0x70,0x80);
  i2c_write(28,0x37 );
  i2c_write(29,0x20 );
  i2c_write(30,0xA8 );
  ///
  i2c_write(31,0xC0 );  
  i2c_write(32,0xC0 );
  i2c_write(33,0xC0 );
  i2c_write(34,0xC0 );
  i2c_write(35,0x00 );
  i2c_write(36,0x03);
  //////
  i2c_write(37,0x03);
  i2c_write(38,0x03);
  i2c_write(39,0x03);
  i2c_write(40,0xF7 ); 
  i2c_write(41,0x5E);  
  i2c_write(42,0x37);
  i2c_write(47,0x14 );
  i2c_write(48,0x3E);
  i2c_write(49,0x95);
  i2c_write(50,0xDE);   
//
///////////////////////////////////
  i2c_write(52,0x10);
  i2c_write(53,0x00 );
  i2c_write(54,0x6C );
  i2c_write(55,0x00 );
  i2c_write(56,0x00 );
  i2c_write(57,0x00 );
  i2c_write(58,0x00 );
  i2c_write(59,0x01 );
  i2c_write(60,0x00 );  
  i2c_write(61,0x00 );  
  i2c_write(62,0x00 );
  i2c_write(63,0x10);
  i2c_write(64,0x00 );
  i2c_write(65,0x35 );
  i2c_write(66,0x00 );
  i2c_write(67,0x00 );
  i2c_write(68,0x00 );
  i2c_write(69,0x00 );
  i2c_write(70,0x01 );  
  i2c_write(71,0x00 );  
  i2c_write(72,0x00 );
  i2c_write(73,0x00);
  i2c_write(74,0x10);
  i2c_write(75,0x00 );
  i2c_write(76,0x09 );
  i2c_write(77,0x00 );
  i2c_write(78,0x00 );
  i2c_write(79,0x00 );
  i2c_write(80,0x00 );  
  i2c_write(81,0x01 );  
  i2c_write(82,0x00 );
  i2c_write(83,0x00 );
  i2c_write(84,0x00);
  i2c_write(85,0x10);
  i2c_write(86,0x80 );
  i2c_write(87,0x03 );
  i2c_write(88,0x00 );
  i2c_write(89,0x00 );
  i2c_write(90,0x00 );  
  i2c_write(91,0x00 );  
  i2c_write(92,0x01 );
  i2c_write(93,0x00 );
  i2c_write(94,0x00 );
  i2c_write(95,0x00);
  
  i2c_write(97,0x80 );
  i2c_write(98,0x87 );
  i2c_write(99,0x00 );
  i2c_write(100,0x00 );  
  i2c_write(101,0x00 );  
  i2c_write(102,0x00 );
  i2c_write(103,0x01 );
  i2c_write(104,0x00 );
  i2c_write(105,0x00 );
  i2c_write(106,0x80);
  i2c_write(107,0x00 );
  i2c_write(108,0x00);

  i2c_write(110,0x40);  
  i2c_write(111,0x00 );  
  i2c_write(112,0x00);

  i2c_write(114,0x40);
  i2c_write(115,0x00 );
  i2c_write(116,0x80);

  i2c_write(118,0xC0);
  i2c_write(119,0x00 );  
  i2c_write(120,0x00 ); 

  i2c_write(122,0x40 ); 

  i2c_write(129,0x00);
  i2c_write(130,0x00); 

  i2c_write(144,0x00); 

  i2c_write(158,0x00);
  i2c_write(159,0x00);

  i2c_write(181,0x00);
  i2c_write(203,0x00);


  //i2c_write(246,2,0xFF);

  //check_and_write(226,4,0xFF);
  //delay(10);
  //check_and_write(226,0,0xFF);

    i2c_write(246,0x02);
    
  //check_and_write(230,0x00);
  i2c_write(230,0x00);
//  for(int j=1;j<3;j++)
//    for(int i=1;i<256;i++){
//  status_check(i);
//  }
}

void loop() {
//  for(int i=1;i<256;i++){
//  status_check(i);
//  }
//  status_check(28);  
  delay(1000);
  // put your main code here, to run repeatedly:

}
