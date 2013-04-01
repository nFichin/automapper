#include "Texture.h"


Textura::Textura() {
}

SDL_Texture* Textura::OnLoad(SDL_Renderer *renderer,const char* File) {
	SDL_Texture *Tex = NULL;
    if((Tex = IMG_LoadTexture(renderer,File)) == NULL) {
        return NULL;
    }
    return Tex;
}
bool Textura::OnDraw(SDL_Renderer *renderer,SDL_Texture* texSrc,const int x,const int y) {
    if(texSrc == NULL || renderer == NULL) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = x;
    DestR.y = y;

    SDL_QueryTexture(texSrc, NULL, NULL, &DestR.w, &DestR.h);

    SDL_RenderCopy(renderer,texSrc,NULL,&DestR);
    return true;
}

bool Textura::OnDraw(SDL_Renderer* renderer, SDL_Texture* texSrc,const int x,const int y,const int x2,const int y2,const int w,const int H) {
    if(texSrc == NULL || renderer == NULL) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = x;
    DestR.y = y;
    DestR.w = w;
    DestR.h = H;
    SDL_Rect SrcR;

    SrcR.x = x2;
    SrcR.y = y2;
    SrcR.w = w;
    SrcR.h = H;

    SDL_RenderCopy(renderer,texSrc,&SrcR,&DestR);
    return true;
}

