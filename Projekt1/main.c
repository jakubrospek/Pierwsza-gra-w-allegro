#include <allegro.h>

int main()

{

allegro_init();

install_keyboard();

set_color_depth(16);

set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

BITMAP *bufor = NULL;

BITMAP *statek = NULL;

bufor = create_bitmap(800,600);

if (!bufor)

{

set_gfx_mode(GFX_TEXT,0,0,0,0);

allegro_message("Nie mogê utworzyæ bufora !");

allegro_exit();

return 0;

}

statek = load_bmp("statek.bmp",default_palette);

if (!statek)

{

set_gfx_mode(GFX_TEXT,0,0,0,0);

allegro_message("nie mogê za³adowaæ obrazka statek !");

allegro_exit();

return 0;

}

int statek_x = 400, statek_y = 525;
while( !key[KEY_ESC])

{

if( key[KEY_LEFT]) statek_x--;

if( key[KEY_RIGHT]) statek_x++;

if( key[KEY_UP]) statek_y--;

if( key[KEY_DOWN]) statek_y++;

clear_to_color(bufor, makecol(10,10,10));

rest(2);

masked_blit( statek, bufor, 0,0, statek_x, statek_y, statek->w, statek->h);

blit( bufor, screen, 0,0,0,0, 800,600);

}


destroy_bitmap(statek);

destroy_bitmap(bufor);

allegro_exit();

return 0;

}

END_OF_MAIN();
