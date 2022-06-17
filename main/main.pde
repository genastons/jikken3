// Practice3-7

import processing.serial.*;

Serial port;

String status[7] = {"座ってください",
                    "背筋を伸ばしてください",
                    "前に傾きすぎです",
                    "後ろに傾きすぎです",
                    "右に傾きすぎです",
                    "左に傾きすぎです",
                    ""}

void setup() {
  size(600, 600); // 文字出力が100*600、姿勢表示がそれぞれ500*300
  port = new Serial(this, "COM3", 9600);
  port.clear();
}

// 最初は座ってないと表示するが、ステータスをうけっとたら変更し、NO_SEATEDを受け取らない限り座ってないと表示しない
void draw() {
  int c = 0;
  int status;
  int deg_hi;
  int deg_lo;
  int deg_si;
  if (port.available() > 0) {
    c = port.read();
    
    if (c == 255) {
        st = port.read();

        text(status[st], 0, 0);

        if ((st == 0) || (st == 1)) {
          continue;
        }

        deg_hi = port.read();
        deg_lo = port.read();
        deg_si = port.read();

        // 描写開始
     }
  }

}
