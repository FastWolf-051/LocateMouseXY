#include <t_include.h>

#define KEY_SPACE 0x20
#define SetCMDTitle SetConsoleTitleA

float SleepforS(float Seconds) {
    Sleep((long double)Seconds * 1000);
    return Seconds;
};

int main() {
    SetCMDTitle("Locate mouse XY");
    CursorPos MousePos;
    bool Is_run = true;
    DisableCursor();
    while (Is_run) {
        if (GetCursorPos(&MousePos)) {
            printf("Xpos = %i,Ypos = %i\n",MousePos.Xpos,MousePos.Ypos);
            printf("(_Press space to exit_)");
            SleepforS(0.1);
            if (GetKeyState(KEY_SPACE)) {
                Is_run = false;
            }
        }
        system("cls");
    }
    return 0;
}