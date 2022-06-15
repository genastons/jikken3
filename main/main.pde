// Practice3-7

import processing.serial.*;

Serial port;

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
        deg_hi = port.read();
        deg_lo = port.read();
        deg_si = port.read();

     }
  }
  // 描写を行っていく

}
