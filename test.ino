#include <servo.h>
#include <math.h>
// データ格納用の変数の宣言
// 背もたれからの距離
int dist_hi;
int dist_lo;
int dist_ri;
int dist_le;

// 背中の角度
double deg_hi;

// 腰の角度
double deg_lo;

// 初期状態での背もたれからの距離
int orig_dist_hi;
int orig_dist_lo;

// 腰幅格納用
int width;

// 腰がどれだけ左右に動いたか
int moved;

// モータの現在位置を把握
int loca_ri;
int laca_le;

// 設定用の定数の宣言
// スタートフラグ
int stared = 0;

// 1cm動かすのに必要な回転速度(仮)
const int ROTATE = 110;

// 人が座っているかどうか判断するための距離(mm)を表す定数
const int NO_SEATED_DIST = 500;

// 移動距離限界を10cmとし、カウントで表す
const int MOVE_LIMIT = 100;

// センサのピンの設定
const int ECHO_HI = 2;
const int TRIG_HI = 3;
const int ECHO_RI = 4;
const int TRIG_RI = 5;
const int ECHO_LE = 6;
const int TRIG_LE = 7;

//モータのピンの設定
const int SRVO_RI = 8;
const int SRVO_LE = 9;

//サーボモータの設定
Servo servo_ri;
Servo servo_le;

void setup() {
  // シリアル通信の開始
  Serial.begin(9600);

  // 超音波測距センサのピンを入力に設定
  pinMode(ECHO_HI, INPUT);
  pinMode(ECHO_RI, INPUT);
  pinMode(ECHO_LE, INPUT);

  // 超音波測距センサのピンを出力に設定
  pinMode(TRIG_HI, OUTPUT);
  pinMode(TRIG_RI, OUTPUT);
  pinMode(TRIG_LE, OUTPUT);

  // サーボモータをピンに割り当て
  servo_ri.attach(SRVO_RI);
  servo_le.attach(SRVO_LE);

  //
}

void loop() {
  // 参考用のよい姿勢をとったときのデータを取得する
  init();

  // init内でスタートフラグが変更されない限り、以降の動作は行わない
  if (started == 0) continue;
  
  // 新しいデータを取得する
  // データを格納する変数は、現在の所グローバルであるが、変更する可能性あり
  getData(); 
  
  // 取得したデータを変換する
  processData();

  // 変換したデータから姿勢を決定する
  determinePosture();

  // Processingにデータを渡す
  passToProcessing();

  // データを保存する
  saveData();
}
