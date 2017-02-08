#include <allegro.h>
#include<stdlib.h>
int orzel_x=380, orzel_y=570;
int mur_x=0, mur_y=0;
int statek_x = 430, statek_y = 560;
int statek_kx, statek_ky;

void kolizje_statek()
{
     if(statek_x<0)statek_x=0;
     if(statek_y<0)statek_y=0;
     if(statek_x>800 - 40)statek_x = 800 - 40;
     if(statek_y>600 - 40)statek_y = 600 - 40;
}

int main()

{

allegro_init();

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

BITMAP *orzel = NULL;
orzel = load_bmp("orzel.bmp",default_palette);

void przeszkody()
{
     
     
//if( key[ KEY_UP ] && getpixel( bufor, statek_x, statek_y ) != makecol(10,10,10))
//     {
//     statek_x--;
//     }
     
     
masked_blit(orzel, bufor, 0,0, orzel_x, orzel_y, orzel->w, orzel->h);

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
if(getpixel( bufor, statek_x, statek_y) == makecol(0,0,0))
statek_x--;
else statek_x++;
play_sample(dzwiek, 100,127,250,0);
statek = load_bmp("statek_lewo.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
przeszkody();
kolizje_statek();
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(5);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}

if(key[KEY_RIGHT]&&getpixel( bufor, statek_x, statek_y ) != makecol(128,128,128))
{
statek_x++;
play_sample(dzwiek, 100,127,250,0);
statek = load_bmp("statek_prawo.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
przeszkody();
kolizje_statek();
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(5);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}

if(key[KEY_UP]&&getpixel( bufor, statek_x, statek_y) != makecol(128,128,128))
{
statek_y--;
play_sample(dzwiek, 100,127,250,0);
statek = load_bmp("statek.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
przeszkody();
kolizje_statek();
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(5);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}

if(key[KEY_DOWN]&&getpixel( bufor, statek_x, statek_y) != makecol(128,128,128))
{
statek_y++;

play_sample(dzwiek, 100,127,250,0);
statek = load_bmp("statek_dol.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h); //rysuje statek na buforze
przeszkody();
kolizje_statek();
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(5);
BITMAP *bufor = NULL;
BITMAP *statek = NULL;
}

//kolizje_statek();

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
