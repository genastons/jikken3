// Practice3-7

import processing.serial.*;

Serial port;

String[] status = {"座ってください",
                    "背筋を伸ばしてください",
                    "前に傾きすぎです",
                    "後ろに傾きすぎです",
                    "背もたれによりかかりすぎています",
                    "右に傾きすぎです",
                    "左に傾きすぎです",
                    ""};

void setup() {
  size(600, 600); // 文字出力が100*600、姿勢表示がそれぞれ500*300
  port = new Serial(this, "COM3", 9600);
  port.clear();
}

// 最初は座ってないと表示するが、ステータスをうけっとたら変更し、NO_SEATEDを受け取らない限り座ってないと表示しない
void draw() {
  int c = 0;
  int st;
  int deg_hi;
  int deg_si;
  int dist_hi;
  int dist_lo;
  int orig_dist;
  if (port.available() > 0) {
    c = port.read();
    
    if (c == 255) {
        st = port.read();
        deg_hi = port.read();
        deg_si = port.read();
        dist_hi = port.read();
        dist_lo = port.read();
        orig_dist = port.read();
        text(status[st], 0, 0);

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
        float t = dx * (x1 + x2 -2 * dx)/(x1 * x2 - dx * dx);
        stroke(255,9,9);
        strokeWeight(2);
        bezier(x1, y1, t*dx, t*dy, t*dx, t*dy, x2, y2);
        line(100 - orig_dist, 400, 250 - orig_dist, 400);
        line(100 - orig_dist, 400, 100 - orig_dist, 550);
        line(250 - 39 * sin(deg_hi), 250 - 39 * cos(deg_hi), x1, y1);
        circle(250 - (39 + radius) * sin(deg_hi), 250 - (39 + radius) * cos(deg_hi), radius);

        // 椅子
        line(253, 243, 253, 403);
        line(133, 403, 253, 403);
        line(133, 403, 133, 550);
        line(253, 243, 253, 550);
     }
  }

}
