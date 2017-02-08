#include <allegro.h>
#include<stdlib.h>

//int statek_x = 400, statek_y = 550;
/*void kolizje_statek()
{
     if(statek_x<0)statek_x=0;
     if(statek_y<0)statek_y=0;
     if(statek_x>800 - 50)statek_x = 800 - 50;
     if(statek_y>600 - 50)statek_y = 600 - 50;
}*/

int mx=0,my=0,mb=0;
void myszka()
{
if( mx != mouse_x || my != mouse_y || mb != mouse_b)
{
mx = mouse_x;

my = mouse_y;

mb = mouse_b;
}
};

int main()

{

allegro_init();

install_keyboard();

set_color_depth(16);

set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

install_mouse();

//enable_hardware_cursor();

//select_mouse_cursor(MOUSE_CURSOR_BUSY);

show_mouse(screen);

unscare_mouse();

show_mouse(screen);

unscare_mouse();

clear_to_color(screen, makecol(0,0,0));

BITMAP *bufor = NULL; //wskaŸnik na strukturê bitmap
bufor = create_bitmap(800,600);

BITMAP *statek = NULL;
//statek = load_bmp("statek.bmp",default_palette);



while(!key[KEY_ESC])
{

clear_to_color(bufor, makecol(0,0,0));

myszka();

textprintf_ex(bufor,font,20,20,makecol(200,200,200),-1,"Myszka x = %d, y = %d, klawisz = %d !", mx,my,mb);

blit(bufor,screen,0,0,0,0,800,600);

clear_keybuf();

if(key[mouse_x])
{

statek = load_bmp("statek.bmp",default_palette);
clear_to_color(bufor, makecol(10,10,10)); //czyszczenie bufora
masked_blit( statek, bufor, 0,0, mx, my, statek->w, statek->h); //rysuje statek na buforze
blit( bufor, screen, 0,0,0,0, 800,600); //kopiowanie bufora na ekran
rest(3);
}

         
}




//destroy_bitmap(statek);

destroy_bitmap(bufor);

allegro_exit();

return 0;

}

END_OF_MAIN();
