#include <allegro.h>
#include<stdlib.h>

int mur_x=0, mur_y=0;
int statek_x = 400, statek_y = 545;
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
     if(statek_x>800 - 40)statek_x = 800 - 40;
     if(statek_y>600 - 40)statek_y = 600 - 40;
     
     if(statek_x<100 && statek_y<90) statek_x=100, statek_y=50;
     
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

BITMAP *mur = NULL;
mur = load_bmp("stal.bmp",default_palette);

BITMAP *zasieki = NULL;
zasieki = load_bmp("zasieki.bmp",default_palette);

void przeszkody()
{
masked_blit(mur, bufor, 0,0, mur_x+60, mur_y+50, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+60, mur_y+140, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+60, mur_y+230, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+60, mur_y+320, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+60, mur_y+410, mur->w, mur->h);

masked_blit(mur, bufor, 0,0, mur_x+150, mur_y+50, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+150, mur_y+140, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+150, mur_y+230, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+150, mur_y+320, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+150, mur_y+410, mur->w, mur->h);

masked_blit(mur, bufor, 0,0, mur_x+240, mur_y+50, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+240, mur_y+140, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+240, mur_y+230, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+240, mur_y+320, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+240, mur_y+410, mur->w, mur->h);

masked_blit(mur, bufor, 0,0, mur_x+330, mur_y+50, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+330, mur_y+140, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+330, mur_y+230, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+330, mur_y+320, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+330, mur_y+410, mur->w, mur->h);
masked_blit(zasieki, bufor, 0,0, mur_x+370, mur_y+430, zasieki->w, zasieki->h);
masked_blit(zasieki, bufor, 0,0, mur_x+370, mur_y+410, zasieki->w, zasieki->h);

masked_blit(mur, bufor, 0,0, mur_x+420, mur_y+50, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+420, mur_y+140, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+420, mur_y+230, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+420, mur_y+320, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+420, mur_y+410, mur->w, mur->h);

masked_blit(mur, bufor, 0,0, mur_x+510, mur_y+50, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+510, mur_y+140, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+510, mur_y+230, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+510, mur_y+320, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+510, mur_y+410, mur->w, mur->h);

masked_blit(mur, bufor, 0,0, mur_x+600, mur_y+50, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+600, mur_y+140, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+600, mur_y+230, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+600, mur_y+320, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+600, mur_y+410, mur->w, mur->h);

masked_blit(mur, bufor, 0,0, mur_x+690, mur_y+50, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+690, mur_y+140, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+690, mur_y+230, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+690, mur_y+320, mur->w, mur->h);
masked_blit(mur, bufor, 0,0, mur_x+690, mur_y+410, mur->w, mur->h);
}

while(!key[KEY_ESC])
{
                    
if(key[KEY_LEFT])
{
play_sample(dzwiek, 100,127,250,0), statek_x--;
statek = load_bmp("statek_lewo.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
przeszkody();
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(5);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}

if(key[KEY_RIGHT])
{
play_sample(dzwiek, 100,127,250,0), statek_x++;
statek = load_bmp("statek_prawo.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
przeszkody();
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(5);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}

if(key[KEY_UP])
{
play_sample(dzwiek, 100,127,250,0), statek_y--;
statek = load_bmp("statek.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
przeszkody();
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(5);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}

if(key[KEY_DOWN])
{
play_sample(dzwiek, 100,127,250,0), statek_y++;
statek = load_bmp("statek_dol.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
przeszkody();
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(5);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}

kolizje_statek();

//ruch_statek();
//odbijanie_statek();

clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
przeszkody();
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(5);


}


stop_sample(dzwiek);

destroy_sample(dzwiek);

destroy_bitmap(statek);

destroy_bitmap(mur);

destroy_bitmap(bufor);

allegro_exit();

return 0;

}

END_OF_MAIN();
