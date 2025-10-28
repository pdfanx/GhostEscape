#include "game.h"

void Game::run()
{
    while(is_running_)
    {
        auto start = SDL_GetTicksNS();


        handleEvents();
        update(0.0f);
        render();
        auto end = SDL_GetTicksNS();
        auto elspsed = end -start;
    }
}

void Game::init(std::string title, int width, int height)
{
    screen_size_ = glm::vec2(width,height);

    // SDL3初始化
    if(!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"SDL初始化失败：%s\n",SDL_GetError());
    }
    
    // SDL3_mixer初始化
    if(Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) != (MIX_INIT_MP3 | MIX_INIT_OGG)){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"SDL_Mixer初始化失败：%s\n",SDL_GetError());
    }

    if(!Mix_OpenAudio(0,NULL)){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"SDL_Mixer打开音频失败：%s\n",SDL_GetError());
    }

    // 分配16个音频通道
    Mix_AllocateChannels(16);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 4);    //设置音乐音量
    Mix_Volume(-1,MIX_MAX_VOLUME / 4);      //设置音效音量

    // SDL3_ttf初始化
    if(!TTF_Init()){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"SDL_TTF初始化失败：%s\n",SDL_GetError());
    }

    // 创建窗口和渲染器
    SDL_CreateWindowAndRenderer(title.c_str(),width,height,SDL_WINDOW_RESIZABLE,&window_,&renderer_);
    if(!window_ || !renderer_)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"窗口或渲染器创建失败：%s\n",SDL_GetError());
    }

    // 设置逻辑分辨率
    SDL_SetRenderLogicalPresentation(renderer_,width,height,SDL_LOGICAL_PRESENTATION_LETTERBOX);
}

void Game::handleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_EVENT_QUIT:
                is_running_ = false;
                break;
            default:
                break;
        }
    }
}

void Game::update(float delta)
{
}

void Game::render()
{
}

void Game::clean()
{
}
