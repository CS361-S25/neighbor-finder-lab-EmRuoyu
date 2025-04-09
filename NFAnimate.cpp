#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"
#include "emp/math/math.hpp"

emp::web::Document doc{"target"};

class NFAnimator : public emp::web::Animate {
    emp::web::Canvas canvas;
   
    public: 
    NFAnimator() : canvas(100, 100, "canvas") {
      canvas.Rect(0, 0, 10, 10, "white", "black");
      //create a 15 x 10 grid of rectangles on canvas
      for (int i = 0; i < 15; ++i) {
          for (int j = 0; j < 10; ++j) {
              canvas.Rect(i * 10, j * 10, 10, 10, "white", "black");
          }
      }
  
       doc << canvas;
       doc << "Hi, This is Neighbor Finder Lab of Emma";
    }
    void FindNeighbors(int x, int y){
    canvas.Rect(x*10, y*10, 10, 10, "black", "black");
    for (int neighborx = -1; neighborx <= 1; neighborx++) {
    for (int neighbory = -1; neighbory <= 1; neighbory++) {
        if (neighborx == 0 && neighbory == 0) continue; // skip center cell
        int modx = emp::Mod(x + neighborx, 15);
        int mody = emp::Mod(y + neighbory, 10);
        if (modx >= 0 && modx < 15 && mody >= 0 && mody < 10) {
        canvas.Rect(modx * 10, mody * 10, 10, 10, "red", "black");
      }
    }
  }
}
};

NFAnimator animator;

int main() {
   animator.FindNeighbors(0, 0);
    animator.Step();
}