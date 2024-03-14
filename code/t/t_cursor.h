#if !defined(t_cursor)
#define t_cursor

#define CURR_CMD_WINDOW abs(0xb)
#define GetStandardHandle GetStdHandle
#define GetCMDCursorInfo GetConsoleCursorInfo
#define SetCMDCursorInfo SetConsoleCursorInfo

typedef struct CMD_CURSOR_INFO {
    unsigned long Size;
    bool Visible;
} CursorInfo;

typedef struct CMD_CURSOR_POS {
    long Xpos;
    long Ypos;
} CursorPos;

void DisableCursor() {
    void* consoleHandle = GetStandardHandle(CURR_CMD_WINDOW);
    CursorInfo cursorInfo;
    GetCMDCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.Visible = false;
    SetCMDCursorInfo(consoleHandle, &cursorInfo);
}

#endif
