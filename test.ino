#include <Servo.h>
#include <math.h>

// 設定用の定数の宣言
// 1cm動かすのに必要な回転速度(仮)
const int ROTATE = 91;

// count1つごとに何mm移動するか
const int COUNT_TO_MM = 5;
// 体が捻られているか判断する用の定数(mm)
const int TWIST = 50;

// 人が座っているかどうか判断するための距離(mm)を表す定数
const int NO_SEATED_DIST = 400;

// 移動距離限界を10cmとし、カウントで表す
const int MOVE_LIMIT = 100;

const int DIST_FROM_HIGH_TO_LOW = 530;
const int HEIGHT_FROM_DOWNSIDE_TO_LOWERSENSOR = 300;

// センサのピンの設定
const int ECHO_HI = 8;
const int TRIG_HI = 9;
const int ECHO_RI = 10;
const int TRIG_RI = 11;
const int ECHO_LE = 2;
const int TRIG_LE = 3;

//モータのピンの設定
const int SRVO_RI = 5;
const int SRVO_LE = 6;

//サーボモータの設定
Servo servo_ri;
Servo servo_le;

// Processingに引き渡すメッセージ
enum status {
  NO_SEATED, // 座ってないよ
  INITIALIZING, // 初期化処理中
  TOO_LEAN_FORWARD,
  TOO_LEAN_BACKWARD,
  TOO_LEAN_PELVIS,
  TOO_LEAN_FORRIGHT,
  TOO_LEAN_FORLEFT,
  NO_PROBLEM, // 異常無し
};

// データ格納用の変数の宣言

// スタートフラグ
int started = 0;

// 背もたれからの距離
int dist_hi;
int dist_lo;
int dist_ri;
int dist_le;

// 背中の角度
int8_t deg_hi;

// 腰の角度
int8_t deg_lo;

// 体の左右の傾き
int8_t deg_si;

// 初期状態での背もたれからの距離
int orig_dist;

// 左右方向への累計移動距離記憶用
int moved_dist = 0;

// Processingへ渡すステータス格納用変数
// 姿勢の状態を表す、デフォルトでは問題ないとするが後で変更する
int st;

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
}

int te = 100;
void loop() {
  st = status::NO_PROBLEM;
  // 実行開始
  // 参考用のよい姿勢をとったときのデータを取得する
  getInit();
  
  // init内でスタートフラグが変更されない限り、以降の動作は行わない
  if (started == 1) {
  
    // 新しいデータを取得する
    // データを格納する変数は、現在の所グローバルであるが、変更する可能性あり
    getData(); 
  
    // 姿勢判定を行う
    determinePosture();

  }

  // Processingにデータを渡す
  // シリアル通信開始用のヘッダ
  Serial.println(deg_hi);
  byte data[] = {st, deg_hi, deg_si, (int8_t)(dist_hi/10), (int8_t)(dist_lo/10), (int8_t)(orig_dist/10)};
  Serial.write(data, 5);
}
