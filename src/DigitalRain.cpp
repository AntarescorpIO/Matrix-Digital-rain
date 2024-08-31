
#include <Arduino.h>
#include "DigitalRainAnimation.hpp"
#include <Adafruit_GFX.h> 
#include <Arduino_GFX_Library.h>
#define GFX_BL 2

// option 1:
// Estas lineas son para la configuracion del bus que usa el display para comunicarse con el esp32s3 y poder graficar
Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    40 /* DE */, 41 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
    45 /* R0 */, 48 /* R1 */, 47 /* R2 */, 21 /* R3 */, 14 /* R4 */,
    5 /* G0 */, 6 /* G1 */, 7 /* G2 */, 15 /* G3 */, 16 /* G4 */, 4 /* G5 */,
    8 /* B0 */, 3 /* B1 */, 46 /* B2 */, 9 /* B3 */, 1 /* B4 */,
    0 /* hsync_polarity */, 8 /* hsync_front_porch */, 4 /* hsync_pulse_width */, 43 /* hsync_back_porch */,
    0 /* vsync_polarity */, 8 /* vsync_front_porch */, 4 /* vsync_pulse_width */, 12 /* vsync_back_porch */,
    1 /* pclk_active_neg */, 9000000 /* prefer_speed */);
Arduino_RGB_Display *gfx = new Arduino_RGB_Display(480 /* width */, 272 /* height */, rgbpanel);/* !defined(DISPLAY_DEV_KIT) */ 
/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/
DigitalRainAnimation<Arduino_GFX> matrix_effect = DigitalRainAnimation<Arduino_GFX>();


void setup() 
{
  Serial.begin(115200);

 
#ifdef GFX_BL 
  pinMode(GFX_BL , OUTPUT);
  digitalWrite(GFX_BL , HIGH);
#endif

  gfx->begin();
  gfx->setRotation(1);

  
 //matrix_effect.setTextAnimMode(AnimMode::SHOWCASE,  "\nWake Up, Neo...    \nThe Matrix has you.    \nFollow     \nthe white rabbit.     \nKnock, knock, Neo.                 ");
  //matrix_effect.setAnimText("Desde Iztapalapa para el mundo");
 //matrix_effect.init(gfx);
 
matrix_effect.init(gfx, false, true);

}

void loop() {
 matrix_effect.loop();
 

}
