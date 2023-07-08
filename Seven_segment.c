#include<lpc21xx.h>
void delay(void);
unsigned char i;

unsigned int Disp[16]={0x003F0000, 0x00060000, 0x005B0000, 0x004F0000,
0x00660000,0x006D0000,0x007D0000, 0x00070000, 0x007F0000,
0x006F0000, 0x00770000,0x007C0000,0x00390000, 0x005E0000,
0x00790000, 0x00710000 };
int main()
{

IODIR0=0x30ff0000; // making po.16 to p0.23 (data)  and p0.28 to p0.29 (select segment) output lines
IOSET0=0x10000000;
IOCLR0=0x00ff0000;
 while(1)
 {

for(i=0;i<16;i++)
{
IOSET0=Disp[i];      
delay();
IOCLR0=0x00ff0000;
}

}
}


void delay(void)
{
unsigned long int j;
  for(j=0;j<3000000;j++);
}
