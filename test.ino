#include <servo.h>
#include <math.h>
// データ格納用の変数の宣言
// 腰幅格納用
int width;

// 背もたれからの距離
int dist_up;
int dist_dw;
int dist_ri;
int dist_le;

// 背中の角度
double deg_up;

// 腰の角度
double deg_dw;

// 初期状態での背もたれからの距離
int orig_dist_up;
int orig_dist_dw;
int orig_dist_ri;
int orig_dist_le;
int orig_width;


// 設定用の定数の宣言
// 1cmセンサを動かすのに必要なモータの回転角度
const int DEGREE_TO_1CM = 180;

// 人が座っているかどうか判断するための距離(mm)を表す定数
const int NO_SEATED_DIST = 500;

// センサのピンの設定
const int ECHO_UP = 2;
const int TRIG_UP = 3;
const int ECHO_RI = 4;
const int TRIG_RI = 5;
const int ECHO_LE = 6;
const int TRIG_LE = 7;

//モータのピンの設定
const int SRVO_RI = 8;
const int SRVO_LE = 9;

//サーボモータの設定
Servo servo_right;
Servo servo_left;

void setup() {
  // シリアル通信の開始
  Serial.begin(9600);

  // 超音波測距センサのピンを入力に設定
  pinMode(ECHO_UP, INPUT);
  pinMode(ECHO_RI, INPUT);
  pinMode(ECHO_LE, INPUT);

  // 超音波測距センサのピンを出力に設定
  pinMode(TRIG_UP, OUTPUT);
  pinMode(TRIG_RI, OUTPUT);
  pinMode(TRIG_LE, OUTPUT);

  // サーボモータをピンに割り当て
  servo_right.attach(SRVO_RI);
  servo_left.attach(SRVO_LE);

  //
}

void loop() {
  // 新しいデータを取得する
  //格納したデータはそのまま取り扱うので、グローバル変数として宣言する
  getData(); 
  
  // 参考用のよい姿勢をとったときのデータを取得する
  init();

  // 取得したデータを変換する
  processData();

  // 変換したデータから姿勢を決定する
  determinePosture();

  // Processingにデータを渡す
  toProcessing();

  // データを保存する
  saveData();
}
