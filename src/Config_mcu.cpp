/************************************************************************************************************

                                      configurações Mega ADK
************************************************************************************************************/

                                   /* Arquivos de Bibliotecas */

 // ========================================================================================================
// --- Bibliotecas Auxiliares --- //

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_BusIO_Register.h>
#include <TCA9548A.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 3



/**********************************************************************************************************/
                                        /* Arquivos de inclusão */


#include "Config_mcu.h"






LiquidCrystal_I2C lcd(0x27,20,4);            // Set the LCD address to 0x27 for a 16 chars and 2 line display
Adafruit_SSD1306 display(OLED_RESET);        // Objeto para o OLED
TCA9548A I2CMux;                             // Address can be passed into the constructor




// ============================================================
// --- Variáveis Globais ---




//==============================================================
//  -----Diretivas TCA9548A
#define i2clcd        0
#define i2coled       1





#define usalcd    I2CMux.openChannel(i2clcd)
#define usaoled   I2CMux.openChannel(i2coled)








// ======================================================================================================
// --- Função de inicialização do Display ---
// ======================================================================================================
// --- Objetos ---
 void config_mcu()

 {
                                   Wire.begin();
                           Serial.begin(115200);
                             I2CMux.begin(Wire);
                 
            


                                         usalcd;
                                     delay(100);
                                     lcd.init();
                                lcd.backlight();       
                         I2CMux.closeChannel(0);
       
                                         usalcd;
                                    lcd.clear(); 
                             lcd.setCursor(2,1);
                  lcd.print("MRPRO TECNOLOGIA");
                         I2CMux.closeChannel(0);





                                         usaoled;
       display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
                          display.clearDisplay();
                          I2CMux.closeChannel(1);




                                         usaoled;
                          display.clearDisplay();
                          display.setTextSize(1);
                     display.setTextColor(WHITE);
                         display.setCursor(30,0);
                        display.print("Umidade");
                                      delay(100);
                               display.display();  
                          I2CMux.closeChannel(1);
                
   
 
                                


 }

