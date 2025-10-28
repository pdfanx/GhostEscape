#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <glm/glm.hpp>
#include <string>

class Game
{
private:
    glm::vec2 screen_size_ = glm::vec2(0);
    bool is_running_ = true;

    SDL_Window* window_ = nullptr;
    SDL_Renderer *renderer_ = nullptr;
    // 私有化构造函数
    Game(){}
    
    // 禁用拷贝构造和复制预算符
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
public:
    static Game& Instance()
    {
        static Game instance;
        return instance;
    }

    // 运行游戏，执行主循环
    void run();

    // 初始化游戏
    void init(std::string title,int width,int height);

    // 处理事件
    void handleEvents();

    // 更新游戏状态
    void update(float delta);

    // 渲染游戏
    void render();

    // 清理游戏资源
    void clean();
};