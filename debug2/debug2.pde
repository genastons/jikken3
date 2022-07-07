// Practice3-7

import processing.serial.*;

Serial port;

String[] status = {"座ってください",
                    "背筋を伸ばしてください",
                    "前に傾きすぎです",
                    "後ろに傾きすぎです",
                    "骨盤が後ろに傾いています",
                    "右に傾きすぎです",
                    "左に傾きすぎです",
                    ""};

void setup() {
  size(600, 600); // 文字出力が100*600、姿勢表示がそれぞれ500*300
  //port = new Serial(this, "COM3", 9600);
  //port.clear();
  PFont font = createFont("Meiryo", 50);
textFont(font);
}

  int dist_hi = 20;
  int dist_lo = 2;
int flag = 0;
// 最初は座ってないと表示するが、ステータスをうけっとたら変更し、NO_SEATEDを受け取らない限り座ってないと表示しない
void draw() {
  delay(150);
//if (dist_hi != dist_lo) dist_hi--;
  //else dist_hi++;
  
  int c = 0;
  int st = 4;
  int deg_si = 5;
  int orig_dist = 4;
  float deg_hi;
  if (dist_hi == dist_lo) deg_hi = 90;
  else deg_hi = atan(30/(dist_hi - dist_lo));
  background(255);
 // if (port.available() > 0) {
   // c = port.read();
    
   // if (c == 255) {
     //   st = port.read();
        //deg_hi = port.read();
        //deg_si = port.read();
    //    dist_hi = port.read();
      //  dist_lo = port.read();
       // orig_dist = port.read();
       fill(0);
    textSize(40);
    textAlign(CENTER);
        text(status[st], 0, 15, 600, 100);
        fill(255);

        if ((st == 0) || (st == 1)) {
          return;
        }

        int x1 = 250 - dist_hi*3;
        int y1 = 241;
        int x2 = 250 - orig_dist*3;
        int y2 = 400;
        int dx = 250 - dist_lo*3;
        int dy = 331;
        int radius = 36;
        // 描写開始
        // 人間
        float p, q, t;
        if (x1 + x2 < 2 * dx) {
          t = (x1 - dx)/(x1 + x2 - 2 * dx);
          p = (dx +sqrt((dx - x1) * (dx - x2)))/dx;
          q = (y1 - y2 + dy)/(2*(t - t*t)*dy);
        } else {
          background(0);
          t = (y1 - dy + sqrt(dy*(y1 + y2 - dy) - y1 * y2))/(y1 + y2 - 2 * dy);
          p = (x1 - x2 + dx)/(2*(t-t*t)*dx);
          q = 1;
        }
        stroke(1,1,200);
        point(dx, dy);
        
        stroke(9,9,9);        
        circle(x1 - (39 + radius)* cos(deg_hi), y1 - (39 + radius) * sin(deg_hi), radius *2);
        strokeWeight(4);
        bezier(x1, y1, p*dx, q*dy, p*dx, q*dy, x2, y2);
        line(x2 - 130, 400, x2, 400);
        line(x2 - 130, 400, x2 - 130, 550);
        line(x1 - 39 * cos(deg_hi), y1- 39 * sin(deg_hi), x1, y1);

        // 椅子
        stroke(160, 120,  70);
        line(253, 243, 253, 403);//semotare
        line(133, 403, 253, 403);//zamen
        line(133, 403, 133, 550);//ashimae
        line(253, 243, 253, 550);//ashiushiro
  //  }
 // }

}
