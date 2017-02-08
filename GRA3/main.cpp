#include <allegro.h>



int mapa_x = 0, mapa_y = 0;             // wspó³rzedne lewego górnego rogu mapy
int mx = 0, my = 0, mb = 0;
int zycie =3;
int czolg_x = 288, czolg_y = 320;       // wspó³rzêdne 'startu' czolgu
int czolg_klatka = 0;                   // wspó³rzedna y na grafice
int czolg_kierunek = 2;              // wspó³rzedna x na grafice

int wrog1_x=32,wrog1_y=32;             // wspó³rzene 'startu' wroga == pozycja w jakiej czolg 'startuje';

BITMAP *kursor=NULL;
BITMAP *bufor = NULL;
BITMAP *mapa = NULL;
BITMAP *czolg = NULL;
BITMAP *wrog1 = NULL;



void myszka()
{
        mx = mouse_x;
        my = mouse_y;
        mb = mouse_b;
};

void laduj_kursor()
{

    kursor = load_bitmap( "kursor.bmp",default_palette);
    if( !kursor )
    {
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "Nie moge zaladowac grafiki ( kursor )" );
        allegro_exit();
    }
};

short int map[15][20] =
{
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,
    1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,


};

void wys_map()
{
      int licznik_x, licznik_y;
      for (licznik_x=0; licznik_x<20; licznik_x++)
      {
      for (licznik_y=0; licznik_y<15; licznik_y++)
      {
           masked_blit(mapa,bufor,( map[licznik_y + mapa_y][licznik_x + mapa_x]%7 )*32, (map[licznik_y + mapa_y][licznik_x + mapa_x]/7)*32, licznik_x*32,licznik_y*32,32,32);
      }
      }    // masked_blit( bitmapa Ÿród³owa sk¹d kopiowany jest obraz , bitmapa docelowa ,);
}



void wrog()
{

    int a=rand()%3+1;
    if(a==1)     {wrog1_x+=32;}
    else if(a==2){wrog1_x-=32;}
    else if(a==3){wrog1_y+=32;}

    if(map[(wrog1_y)/32][(wrog1_x-32)/32]!=1)
        wrog1_x-=32;

    if(map[(wrog1_y)/32][(wrog1_x+32)/32]!=1)
        wrog1_x+=32;

    if(map[(wrog1_y-32)/32][(wrog1_x)/32]!=1)
        wrog1_y-=32;

    if(map[(wrog1_y+32)/32][(wrog1_x)/32]!=1)
        wrog1_y+=32;

}

int main()
{
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);

    laduj_kursor();
    install_mouse();
    show_mouse(screen);
    set_mouse_sprite(kursor);
    unscare_mouse();


    bufor = create_bitmap(640,480);
    if (!bufor)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora !");
        allegro_exit();
        return 0;
    }

    mapa = load_bmp("grafika.bmp",NULL);
    if (!mapa)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora (grafika) !");
        allegro_exit();
        return 0;
    }

    czolg = load_bmp("grafika.bmp",NULL);
    if (!czolg)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora (pacman) !");
        allegro_exit();
        return 0;
    }

    wrog1 = load_bmp("grafika.bmp",NULL);
    if (!wrog1)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê utworzyæ bufora (duch) !");
        allegro_exit();
        return 0;
    }





    while( !key[KEY_ESC])
    {
            myszka();
            clear_to_color(bufor, makecol(0,0,0));
            if( key[KEY_LEFT])
            { 
                czolg_kierunek = 6;
                if(map[(czolg_y)/32][(czolg_x-32)/32]!=1)
                czolg_x-=32;
            }
            else if( key[KEY_RIGHT])
            {
                 czolg_kierunek = 7;
                 if(map[(czolg_y)/32][(czolg_x+32)/32]!=1)
                 czolg_x+=32;
            }
            else if( key[KEY_UP])
            {
                 czolg_kierunek = 5;
                 if(map[(czolg_y-32)/32][(czolg_x)/32]!=1)
                 czolg_y-=32;
            }
            else if( key[KEY_DOWN])
            {
                 czolg_kierunek = 2;
                 if(map[(czolg_y+32)/32][(czolg_x)/32]!=1)
                 czolg_y+=32; 
            }

            if(czolg_x == wrog1_x && czolg_y == wrog1_y)
            {
                allegro_message("Straciles zycie!!!");
                czolg_kierunek = 2;
                czolg_x = 288, czolg_y = 320;
                zycie--;
                if(zycie == 0)
                {
                         allegro_message("GAME OVER");
                         return 0;
                }

            }
            wrog();

        clear(bufor);
        wys_map();
        textprintf_ex(bufor, font, 20, 20, makecol( 200, 200, 200 ), - 1, "Myszka x = %d, y = %d, czolg x = %d, y = %d,", mx, my,czolg_x, czolg_y);
        textprintf_ex(bufor, font, 470, 464, makecol( 0, 0, 0 ), - 1, "ZYCIE: %d",zycie);
        masked_blit(czolg, bufor, czolg_kierunek*32,czolg_klatka*32,czolg_x, czolg_y, 32,32);
        masked_blit(wrog1, bufor, 128,0,wrog1_x, wrog1_y, 32,32);
        blit(bufor, screen, 0,0,0,0, 640,480);
        rest(100);
    }

    allegro_exit();
    return 0;
}
END_OF_MAIN();
