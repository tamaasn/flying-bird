#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
struct Player{
    SDL_Rect rect;
    SDL_Rect src_rect = {32 , 0 , 32 , 32};
    int anim_timer=5;
    int anim_index=0;
};

struct Leaf{
    double angle=90;
    SDL_Rect rect;
    bool alive=false;
};

struct Cloud{
    SDL_Rect rect;
    bool alive=false;
};

SDL_Surface *leaf_surface;
SDL_Surface *player_surface;
SDL_Surface *cloud_surface;

SDL_Texture *leaf_texture;
SDL_Texture *player_texture;
SDL_Texture *cloud_texture;

int leaf_timer=20;
const int leaf_max=10;
const int cloud_max=10;
int cloud_timer=3;

const int width=640;
const int height=480;

Player player;
Leaf leafs[leaf_max];
Cloud clouds[cloud_max];

void LOAD_TEXTURES(SDL_Renderer *rend){
    player_surface = IMG_Load("images/player.png");
    leaf_surface = IMG_Load("images/leaf.png");
    cloud_surface = IMG_Load("images/cloud.png");

    leaf_texture = SDL_CreateTextureFromSurface(rend , leaf_surface);
    player_texture = SDL_CreateTextureFromSurface(rend , player_surface);
    cloud_texture = SDL_CreateTextureFromSurface(rend , cloud_surface);
    SDL_FreeSurface(player_surface);
    SDL_FreeSurface(leaf_surface);
    SDL_FreeSurface(cloud_surface);
}

void DESTROY_TEXTURES(){
    SDL_DestroyTexture(leaf_texture);
    SDL_DestroyTexture(player_texture);
    SDL_DestroyTexture(cloud_texture);
}


