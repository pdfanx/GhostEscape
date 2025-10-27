## ttf

![1761556376480](images/SDL/1761556376480.png)

![sdl2-ttf](images/SDL/1761556272532.png)

### 区别

sdl2每一帧都要创建和销毁surface和texture;

sdl3只有变化时才会创建和销毁物理；


## 获取鼠标状态

state = SDL_GetMouseState(&x,&y);
