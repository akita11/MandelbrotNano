// draw Mandelbrot set on LonganNanoLite
// by akita11 (akita@ifdl.jp), 2019/12/15
// based on https://qiita.com/myston/items/0e32321e6d4c53280081

#include "lcd/lcd.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
    Lcd_Init();
    LCD_Clear(BLACK);
    BACK_COLOR=BLACK;

    int pixelX, pixelY;
    float Xs, Xe, sizeX, sizeY;
    int i, j, k;
    float x,y,a,b,_a,_b;
    // 16bit color: [RRRRRGGG] [GGGBBBBB]
    u16 col[] = {BLUE ,RED, MAGENTA, GREEN, CYAN, YELLOW, WHITE};
    int max = 500;
    int icol;

    sizeX = 4.0; sizeY = 2.0;
    Xs = -2.5; Xe = 1.5;
    pixelX = 160; pixelY = 80;
    for (i = 0; i < pixelX; i++) {
        x = i * (Xe - Xs) / pixelX + Xs;
        for(j = 0; j < pixelY;j++) {
            y = j *sizeY/pixelY - sizeY/2;
            a = 0;
            b = 0;
            for(k = 0;k < max;k++){
                _a = a * a - b * b + x;
                _b = 2 * a * b + y;
                a = _a;
                b = _b;
                if(a * a + b * b > 4.0) {

                    icol = k % 7;
                    LCD_DrawPoint(i, j, col[icol]);
                    break;
                }
            }
        }
    }
}

