#include <stdio.h>
#include <math.h>

using namespace std;

//GAVE UP FUCK
//LOGICAL ERROR

int pc = 0, boxs[6];

int main() {
  bool on = true;

  while (on)
  {
    pc = 0;
    on = false;
    for (int i = 0; i < 6; i++) {
      scanf("%d", &boxs[i]);
      if (boxs[i] != 0) on = true;
    }

    if (!on) break;

    for (int i = 5; i >= 0; i--) {
      int spaceLeft = 0;
      if (i > 3) {
        pc += boxs[i];
        spaceLeft = boxs[i] * (36 - (int)pow((i + 1), 2));
      }
      else {
        pc += (int)ceil(boxs[i] * (pow((i + 1), 2) / 36));
        spaceLeft = 36 - ((boxs[i] * (int)pow((i + 1), 2)) % 36);
      }

      if (spaceLeft) {
        if (i == 4 || i == 1) {
          if (spaceLeft >= boxs[0]) boxs[0] = 0;
          else boxs[0] -= spaceLeft;
        }

        if (i == 2) {
          if (spaceLeft / 9 >= boxs[1]) { spaceLeft -= 4 * boxs[1]; boxs[1] = 0; }
          else { spaceLeft -= 5 * spaceLeft / 9; boxs[1] -= spaceLeft / 9; }

          if (spaceLeft >= boxs[0]) boxs[0] = 0;
          else boxs[0] -= spaceLeft;
        }

        if (i == 3) {
          if (spaceLeft >= boxs[1] * 4) { spaceLeft -= 4 * boxs[1]; boxs[1] = 0; }
          else { boxs[1] -= spaceLeft / 4; }

          if (spaceLeft >= boxs[0]) boxs[0] = 0;
          else boxs[0] -= spaceLeft;
        }
      }
    }

    printf("%d\n", pc);
  }
}