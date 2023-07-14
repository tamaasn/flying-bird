#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
class Font{
    public:
        void init();
        void create(SDL_Renderer *render , SDL_Texture** texture , const char* text);
        void destroy();
    private:
        SDL_Color color = {255,255,255};
        TTF_Font *font;
};

void Font::init(){
    TTF_Init();
    font = TTF_OpenFont("font.ttf" , 24);
}

void Font::create(SDL_Renderer *render , SDL_Texture** texture , const char* text){
    SDL_Surface *surface;
    surface = TTF_RenderText_Solid(font , text , color);
    *texture = SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
}

void Font::destroy(){
    TTF_CloseFont(font);
    font=NULL;
}
