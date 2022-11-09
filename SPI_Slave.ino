// SLAVE TRUYEN NHAN DU LIEU SPI THEO MODE 0 (CPOL = 0; CPHASE = 0)  MSB First
#define SCK  4   // chân SCK   
#define MOSI 5   // Chân MOSI
#define MISO 6   // chân MISO
#define SS   7     // Chân SS

void setup() 
{
  pinMode (SCK,INPUT);
  pinMode (MOSI,INPUT);
  pinMode (SS,INPUT);
  pinMode (MISO,OUTPUT);
}

uint8_t SPI_SOft_Transmit (uint8_t mData)  //Chuong trinh Slave gui nhan 1 byte
{
  uint8_t i = 0, x = 0;
  uint8_t byte_in = 0x00;   
  uint8_t ibit = 0x80;
  while ( digitalRead(SS) == HIGH); // doi cho den khi SS = 0 thi moi bat dau nhan
  for (int i = 0; i < 8; i++)
  {
    x = mData & ibit;     //Dua bit can truyen len chan MISO
     if ( x > 0)
    {
      digitalWrite (MISO,1);
    }
    else
    {
      digitalWrite (MISO,0);
    }
    while (digitalRead(SCK) == LOW); // Doi cho den khi SCK = 1 thi moi tiep tuc gui du lieu
    if ( digitalRead (MOSI) == HIGH)
    {
      byte_in = byte_in | ibit;  // Slave nhan ve bit 1 
    }
    else
    {
      byte_in = byte_in & (~ibit); // Slave nhan ve bit 0
    }
    while (digitalRead(SCK) == HIGH); // Doi cho toi khi SCK xuong muc 0 
    // Ket thuc chu ky gui nhan 1 bit
    ibit = ibit >> 1;
  }
}
void loop() {
  uint8_t rev;
  rev = SPI_SOft_Transmit('A'); //ASCII:0x41  65
  delay(1000);

}
