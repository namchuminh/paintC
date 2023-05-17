#include<iostream>
#include<graphics.h>
using namespace std;
int size = 100;
int posX = 10;
int posY = 10;
void veBangMau(){
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    rectangle(posX, posY, posX + size, posY + size);
    floodfill(posX+1,posY+1,WHITE);
	
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    rectangle(posX, posY + size + 10, posX + size, posY + size * 2 + 10);
    floodfill(posX+1,posY + size + 10 + 1,BLUE);
	
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    rectangle(posX, posY + size * 2 + 20, posX + size, posY + size * 3 + 20);
    floodfill(posX+1,posY + size * 2 + 20 + 1,RED);
	
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    rectangle(posX, posY + size * 3 + 30, posX + size, posY + size * 4 + 30);
    floodfill(posX+1,posY + size * 3 + 30 + 1,YELLOW);
	
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(posX, posY + size * 4 + 40, posX + size, posY + size * 5 + 40);
    floodfill(posX+1,posY + size * 4 + 40 + 1,GREEN);
    
    setlinestyle(SOLID_LINE, 0, 1); // doi kieu net ve
    setcolor(WHITE);
    line(size + 20, 0, size + 20, 800); 
}
void hienThiChu(){
    setlinestyle(SOLID_LINE, 0, 1); // doi kieu net ve
    setcolor(WHITE);
    line(120, 550, 800, 550);

    int x = 200;
    int y = 560;

    setlinestyle(SOLID_LINE, 0, 4);
    setcolor(WHITE);
    outtextxy(x, y, "WHITE: W");
    setcolor(BLUE);
    outtextxy(x + 100, y, "BLUE: B");
    setcolor(RED);
    outtextxy(x + 200, y, "RED: R");
    setcolor(YELLOW);
    outtextxy(x + 300, y, "YELLOW: Y");
    setcolor(GREEN);
    outtextxy(x + 400, y, "GREEN: G");
}
int main()
{
    initwindow(800, 600, "Paint Program");
    veBangMau();  
    hienThiChu();  
    setcolor(WHITE); // thiet lap màu ve?
    int x1, y1, x2, y2; // luu toa do cua hai diem
    bool isDragging = false; // bien kiem tra xem có kéo chuot không
    while(true){
        if(ismouseclick(WM_LBUTTONDOWN)){
            x1 = mousex(); // lay toa do chuot khi bat dau kéo
            y1 = mousey();
            isDragging = true;
            clearmouseclick(WM_LBUTTONDOWN);
        }
        else if(ismouseclick(WM_LBUTTONUP)){
            isDragging = false;
            clearmouseclick(WM_LBUTTONUP);
        }
        else if(ismouseclick(WM_MOUSEMOVE)){
            if (isDragging){
                // lay toa do x,y khi kéo chuot
                x2 = mousex();
                y2 = mousey();
                setlinestyle(SOLID_LINE, 0, 2); // doi kieu net ve
                line(x1, y1, x2, y2); 
                x1 = x2; // cap nhat lai toa do diem dau`
                y1 = y2;
                clearmouseclick(WM_MOUSEMOVE);
            }
        }
        if(kbhit()){
            char c = getch();
            if (c == 27) //ESC
            {
                break;
            }
        }
        if(kbhit()){
            char c = getch();
            if (c == 119){ //NHAN PHIM W
                setcolor(WHITE);
            }
            if (c == 98){ //NHAN PHIM B
                setcolor(BLUE);
            }
            if (c == 114){ //NHAN PHIM R
                setcolor(RED);
            }
            if (c == 121){ //NHAN PHIM Y
                setcolor(YELLOW);
            }
            if (c == 103){ //NHAN PHIM G
                setcolor(GREEN);
            }
            if (c == 8){ //DELETE
                cleardevice();
                veBangMau();
                hienThiChu();
                setcolor(WHITE);
            }
        }
    }
    closegraph();
    return 0;
}

