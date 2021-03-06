// taken from http://www.raspberrypi.org/forums/viewtopic.php?t=26884&p=253297
    #include <stdio.h>
    #include <fcntl.h>
    #include <linux/i2c-dev.h>
    #include <linux/i2c.h>
    #include <unistd.h>


    int deviceHandle;
    int readBytes;

    int i =0;
     char buffer = {0x06 ,0x00}  ; //for config register with value '0'
     char buffer1 ={0x02 , 0x00};  // for output register with value '0'

    int main (void)
    {
          // print infos
          printf("Raspberry Pi Max7311 Sample with leds on port 1  \n");
          printf("========================================\n");
          
          
          // address of MAX7311 device
          int deviceI2CAddress = 0x20;

          

          // open device on /dev/i2c-1                                   
          if ((deviceHandle = open("/dev/i2c-1", O_RDWR)) < 0) {
                printf("Error: Couldn't open device! %d\n", deviceHandle);
                return 1;
          }


          if (ioctl(deviceHandle, I2C_SLAVE, deviceI2CAddress) < 0) {
                printf("Error: Couldn't find device on address!\n");
                return 1;
          }
          

               readBytes = write(deviceHandle, buffer, 2);        // for config reg
               readBytes = write(deviceHandle, buffer1, 2);     // for  output reg
          
          
           // printf("%d \n" , readBytes);
           // printf("%d \n", sizeof(buffer));
           
          
       // close connection and return
          close(deviceHandle);
          return 0;
    }      
       

