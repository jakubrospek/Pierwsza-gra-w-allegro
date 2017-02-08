#include <allegro.h>
#include<stdlib.h>

int mx=0,my=0,mb=0;

void myszka()
{
if( mx != mouse_x || my != mouse_y || mb != mouse_b)
{
mx = mouse_x;

my = mouse_y;

mb = mouse_b;
}
}

int main()
{
    
int i;
int rozmiar=1000;    
int *x, *y;
x=(int *)malloc(rozmiar*sizeof(int));
y=(int *)malloc(rozmiar*sizeof(int));
    
allegro_init();

install_keyboard();

set_color_depth(16);

set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

install_mouse();

show_mouse(screen);

unscare_mouse();

show_mouse(screen);

unscare_mouse();

BITMAP *bufor = NULL; //wska�nik nz struktur� bitmp
bufor = create_bitmap(800,600);

BITMAP *statek = NULL;
statek = load_bmp("statek.bmp",default_palette);


while(!key[KEY_ESC])
{
myszka();

clear_keybuf();

if(mb==1)
{   
masked_blit( statek, bufor, 0,0, mx-18, my-29, statek->w, statek->h);
blit( bufor, screen, 0,0,0,0, 800,600);

         for(i = 0; i < rozmiar; i++)
         {
         if(x[i] == 0 && y[i] == 0)
         {
         x[i] = mx;
         y[i] = my;
         break;
         }
         }
}

if(mb==2)
{
clear_to_color(bufor, makecol(0,0,0));
blit( bufor, screen, 0,0,0,0, 800,600);

       for(i = 0; i < rozmiar; i++)
       {
       if((x[i] < mx - 18) || (x[i] > mx + 18) || (y[i] < my - 29) || (y[i] > my + 29))
       //gdy myszka jest poza obrazkiem
       {
       if(x[i] != 0 && y[i] != 0)
       //jesli wsp�rz�dne obrazka nie s� puste, zostanie wyswietlony
       blit(statek, bufor, 0,0, x[i]-18, y[i]-29, statek->w, statek->h);
       }
       else
       {
       //jesli kursor jest w granicach obrazka, to usuwamy go poprzez zerowanie wsp�rz�dnych
       x[i] = 0;
       y[i] = 0;
       }
       }
}
blit(bufor, screen, 0,0, 0,0, bufor->w, bufor->h); // wy�wietlenie bufora
rest(10); //zw�oka, dla jednego klikni�cia
}

destroy_bitmap(statek);

destroy_bitmap(bufor);

allegro_exit();

return 0;

}

END_OF_MAIN();
