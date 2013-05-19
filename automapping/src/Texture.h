#ifndef TEXTURA_H_
#define TEXTURA_H_

#include "SDL.h"
#include "SDL_image.h"

class cTexture {
    public:
        cTexture();

    public:
        static SDL_Texture* OnLoad(SDL_Renderer *renderer, const char* File);
        static bool OnDraw(SDL_Renderer *Renderer, SDL_Texture* Tex_Src,const int X,const int Y);
        static bool OnDraw(SDL_Renderer* Renderer, SDL_Texture* Tex_Src,const int X,const int Y,const int X2,const int Y2,const int W,const int H);
};


#endif /* TEXTURA_H_ */
