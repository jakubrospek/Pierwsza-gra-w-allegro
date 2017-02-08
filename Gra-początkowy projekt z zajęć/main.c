#include <allegro.h>
#include<stdlib.h>

int statek_x = 400, statek_y = 550;
int statek_kx, statek_ky;

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
     else if(statek_x == 756)
     {
         statek_kx = -1;     
     }
     if(statek_y == 0)
     {
        statek_ky = 1;     
     }
     else if(statek_y == 550)
     {
        statek_ky = -1;
     }
}

void ruch_statek()
{
     statek_x += statek_kx;
     statek_y += statek_ky;
}

void kolizje_statek()
{
     if(statek_x<0)statek_x=0;
     if(statek_y<0)statek_y=0;
     if(statek_x>800 - 50)statek_x = 800 - 50;
     if(statek_y>600 - 50)statek_y = 600 - 50;
}

int main()

{

allegro_init();

start_statek();

install_keyboard();

set_color_depth(16);

set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"");

set_volume(255,255);

SAMPLE *dzwiek = NULL;

dzwiek = load_sample("warkot.wav");

BITMAP *bufor = NULL; //wskaŸnik na strukturê bitmap
bufor = create_bitmap(800,600);

BITMAP *statek = NULL;
statek = load_bmp("statek.bmp",default_palette);


while(!key[KEY_ESC])
{
                    
if(key[KEY_LEFT])
{
play_sample(dzwiek, 100,127,250,0), statek_x--;
statek = load_bmp("statek_lewo.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(3);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}


if(key[KEY_RIGHT])
{
play_sample(dzwiek, 100,127,250,0), statek_x++;
statek = load_bmp("statek_prawo.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(3);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}

if(key[KEY_UP])
{
play_sample(dzwiek, 100,127,250,0), statek_y--;
statek = load_bmp("statek.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(3);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}

if(key[KEY_DOWN])
{
play_sample(dzwiek, 100,127,250,0), statek_y++;
statek = load_bmp("statek_dol.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(3);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}

kolizje_statek();

//ruch_statek();
//odbijanie_statek();

clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(0);
}


stop_sample(dzwiek);
destroy_sample(dzwiek);

destroy_bitmap(statek);

destroy_bitmap(bufor);

allegro_exit();

return 0;

}

END_OF_MAIN();
