//整理者：极客工坊bg1lsy (lsy@sogou.com)
//整理时间：2013.05.25
#include <SPI.h>
#include <RFID.h>

RFID rfid(10,5);   //D10--读卡器MOSI引脚、D5--读卡器RST引脚
void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
}

void loop()
{
  //找卡
  if (rfid.isCard()) {
    Serial.println("Find the card!");
    //读取卡序列号
    if (rfid.readCardSerial()) {
      Serial.print("The card's number is  : ");
      Serial.print(rfid.serNum[0],HEX);
      Serial.print(rfid.serNum[1],HEX);
      Serial.print(rfid.serNum[2],HEX);
      Serial.print(rfid.serNum[3],HEX);
      Serial.print(rfid.serNum[4],HEX);
      Serial.println(" ");
    }
    //选卡，可返回卡容量（锁定卡片，防止多数读取），去掉本行将连续读卡
    rfid.selectTag(rfid.serNum);
  }
  
  rfid.halt();
}
