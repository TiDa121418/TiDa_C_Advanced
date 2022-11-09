// MASTER TRUYEN NHAN DU LIEU SPI THEO MODE 0 (CPOL = 0; CPHASE = 0) MSB First
#define SCK  4   // chân SCK   
#define MOSI 5   // Chân MOSI
#define MISO 6   // chân MISO
#define SS   7     // Chân SS

//SPI Speed: MHz(real), KHz (simulation)
// Slow_01: f = 20 KHz  => T = 50us
// Slow_02: f = 1 KHz   => T = 1000us
#define TFull 50
#define THalf  TFull/2

void setup() {

  SPI_Setup();
}

void SPI_Setup()
{
  digitalWrite (SCK,LOW);
  pinMode (SCK,OUTPUT);
  pinMode (MOSI,OUTPUT);
  digitalWrite (SS,HIGH);
  pinMode (SS,OUTPUT);
  pinMode (MISO,INPUT);
  delay(1);
}

void SPI_begin()
{
  digitalWrite (SS,LOW);
}

void SPI_end()
{
  digitalWrite (SCK,LOW);
  digitalWrite (SS,HIGH);
}

uint8_t SPI_SOft_Transmit (uint8_t mData)  //Chuong trinh Master gui nhan 1 byte
{
  uint8_t i = 0, x = 0;
  uint8_t byte_in = 0x00;   
  uint8_t ibit = 0x80;
  
  for (int i = 0; i < 8; i++)
  {
    x = mData & ibit;     //Dua bit can truyen len chan MOSI
    if ( x > 0)
    {
      digitalWrite (MOSI,1);
    }
    else
    {
      digitalWrite (MOSI,0);
    }
    delayMicroseconds (THalf);   //Sau khi doc duoc bit tu chan MOSI thi delay nua chu ky
    digitalWrite (SCK,1); // Cho chan SCK len 1 de truyen du lieu di
    digitalRead (MISO); // Doc du lieu chan MISO ngay khi SCK = 1
    if ( digitalRead (MISO) == HIGH)
    {
      byte_in = byte_in | ibit;  // Master nhan ve bit 1 
    }
    else
    {
      byte_in = byte_in & (~ibit); // Master nhan ve bit 0
    }
    
    delayMicroseconds (THalf);
    digitalWrite (SCK,0);   //Ket thuc 1 chu ky ( gui nhan 1 bit)
    ibit = ibit >> 1;
    
  }
  return byte_in;
}
void loop() {
   
  uint8_t rev;
  SPI_begin();
  rev = SPI_SOft_Transmit('a'); //ASCII:0x61  97
  SPI_end();
  delay(1000);
}
