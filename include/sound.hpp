#include <SDL2/SDL.h>

class Audio{
    public:
        void load(const char *filename);
        void play();
        Uint32 get_state();
        void destroy();
        void stop();
        bool ready=false;
        void resume();
    private:
        Uint32 wavlength;
        Uint8 *wavbuffer;
        SDL_AudioSpec wavspec;
        SDL_AudioDeviceID deviceid;
};

void Audio::load(const char *filename){
    SDL_LoadWAV(filename , &wavspec , &wavbuffer , &wavlength);
    deviceid = SDL_OpenAudioDevice(NULL , 0 , &wavspec , NULL , 0);
    ready=true; 
}

void Audio::play(){
    if (ready){
        SDL_QueueAudio(deviceid , wavbuffer , wavlength);        
        SDL_PauseAudioDevice(deviceid , 0);
    }
}

Uint32 Audio::get_state(){
    return SDL_GetQueuedAudioSize(deviceid);
}

void Audio::destroy(){
    SDL_FreeWAV(wavbuffer);
    SDL_CloseAudioDevice(deviceid);
}

void Audio::stop(){
    SDL_PauseAudioDevice(deviceid , 1);
}

void Audio::resume(){
    SDL_PauseAudioDevice(deviceid , 0);
}
