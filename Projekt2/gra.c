#include <allegro.h>
#include<math.h>
#include<stdio.h>

double pozycja_x = 400.0, pozycja_y = 550.0;
double predkosc = 0;
double kat = 270.0;

kolizje()
{
         if(pozycja_x<0)pozycja_x=0;
         if(pozycja_y<0)pozycja_y=0;
         if(pozycja_x>(800 - 50))pozycja_x=(800 - 50);
         if(pozycja_y>(600 - 50))pozycja_y=(600 - 50);
}

ruch()
{
          if( predkosc > 5 ) predkosc = 5;
          if( predkosc <- 3 ) predkosc =- 3;
          predkosc *= 0.99;
          pozycja_x += predkosc * cos(( kat * M_PI ) / 180.0 );
          pozycja_y += predkosc * sin(( kat * M_PI ) / 180.0 );
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

BITMAP *bufor = NULL;

BITMAP *statek = NULL;

bufor = create_bitmap(800,600);

statek = load_bmp("statek.bmp",default_palette);

while( !key[KEY_ESC])
{       
        if( key[KEY_LEFT])kat -= 0.4, play_sample(dzwiek, 50,127,500,0);

        if( key[KEY_RIGHT]) kat += 0.4, play_sample(dzwiek, 50,127,500,0);

        if( key[KEY_UP]) predkosc += 0.01, play_sample(dzwiek, 100,127,250,0);

        if( key[KEY_DOWN]) predkosc -= 0.01, play_sample(dzwiek, 100,127,250,0);

kolizje();
ruch();
        
clear_to_color(bufor, makecol(10,10,10));
rotate_sprite( bufor, statek,( int ) round( pozycja_x ),( int ) round( pozycja_y ), ftofix(( kat * 256 ) / 360.0 ) );
blit( bufor, screen, 0,0,0,0, 800,600);

rest(4);
}

stop_sample(dzwiek);

destroy_sample(dzwiek);

destroy_bitmap(statek);

destroy_bitmap(bufor);

allegro_exit();

return 0;

}

END_OF_MAIN();
