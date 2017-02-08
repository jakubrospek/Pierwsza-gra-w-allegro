#include <allegro.h>
#include<stdlib.h>

int statek_x = 400, statek_y = 525;
int mars_x = 400, mars_y = 525;
int statek_kx, statek_ky;
int mars_kx, mars_ky;

void start_statek()
{
     int zarodek;
	zarodek = time(NULL);
	srand(zarodek);
	int kierunek;
	kierunek = rand() % 2;
	if(kierunek == 0)
        statek_kx = -1;
    else
        statek_kx = 1;
    kierunek = rand() % 2;
    if(kierunek == 0)
        statek_ky = -1;
    else
        statek_ky = 1;
}

void odbijanie_statek()
{
     if(statek_x == 0)
     {
         statek_kx = 1;
     }
     else if(statek_x == 761)
     {
         statek_kx = -1;     
     }
     if(statek_y == 0)
     {
        statek_ky = 1;     
     }
     else if(statek_y == 542)
     {
        statek_ky = -1;
     }
}

void ruch_statek()
{
     statek_x += statek_kx;
     statek_y += statek_ky;
}

void sterowanie_statek()
{
     if(key[KEY_LEFT]) statek_x--;

     if(key[KEY_RIGHT]) statek_x++;

     if(key[KEY_UP]) statek_y--;

     if(key[KEY_DOWN]) statek_y++;
}

void kolizje_statek()
{
     if(statek_x<0)statek_x=0;
     if(statek_y<0)statek_y=0;
     if(statek_x>800 - 39)statek_x = 800 - 39;
     if(statek_y>600 - 58)statek_y = 600 - 58;
}     

void start_mars()
{
     int zarodek;
	zarodek = time(NULL);
	srand(zarodek);
	int kierunek;
	kierunek = rand() % 2;
	if(kierunek == 0)
        mars_kx = -1;
    else
        mars_kx = 1;
    kierunek = rand() % 2;
    if(kierunek == 0)
        mars_ky = -1;
    else
        mars_ky = 1;
}

void ruch_mars()
{
     mars_x += mars_kx;
     mars_y += mars_ky;
}

void odbijanie_mars()
{
     if(mars_x == 0)
     {
         mars_kx = 1;
     }
     else if(mars_x == 700)
     {
         statek_kx = -1;     
     }
     if(mars_y == 0)
     {
        statek_ky = 1;     
     }
     else if(mars_y == 499)
     {
        mars_ky = -1;
     }
}

int main()

{

allegro_init();

start_statek();

start_mars();

install_keyboard();

set_color_depth(16);

set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

BITMAP *bufor = NULL;
bufor = create_bitmap(800,600);

BITMAP *statek = NULL;
statek = load_bmp("statek.bmp",default_palette);
BITMAP *mars = NULL;
mars = load_bmp("mars.bmp",default_palette);

//statek_x = 200; 
//statek_y = 100;
//mars_x = 50;
//mars_y = 100;

while(!key[KEY_ESC])
{
                    
//sterowanie_statek();
//kolizje_statek();

ruch_statek();
ruch_mars();
odbijanie_statek();
odbijanie_mars();

clear_to_color(bufor, makecol(10,10,10));
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h);
masked_blit( mars, bufor, 0,0, mars_x, mars_y, mars->w, mars->h);
blit( bufor, screen, 0,0,0,0, 800,600);
rest(5);
}


destroy_bitmap(statek);
destroy_bitmap(mars);

destroy_bitmap(bufor);

allegro_exit();

return 0;

}

END_OF_MAIN();
