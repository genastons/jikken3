void getData() {
    // モータがどれだけ動いたか取得する
    int moved;
    if (started == 0) {
        // 初期値取得前なら、左側も同様に身体を検出するまで動かす
        moveSensor("ri", 0);
        moveSensor("le", 0);
    } else {
        moved = moveSensor("ri", 0);
        if (moved > 0) {
            moveSensor("le", moved);
        } else {
            moved = -moveSensor("le", 0);
            moveSensor("ri", moved);
        }
    }

    // 取得した距離から、背もたれとセンサ間の距離分差し引き補正する
    dist_hi = getDist(TRIG_HI, ECHO_HI) - 40;
    dist_ri = getDist(TRIG_RI, ECHO_RI) - 20;
    dist_le = getDist(TRIG_LE, ECHO_LE) - 20;
    dist_lo = (dist_ri + dist_le) / 2;

    moved_dist += moved * COUNT_TO_MM;
    // 体の角度を算出
    // 送信の簡略化のためintへ変換するが、小数点以下もほしいので2倍にしてから変換
    deg_hi = (int8_t)(atan(sqrt(pow(dist_lo - dist_hi, 2) + pow(DIST_FROM_HIGH_TO_LOW, 2)) * 2));
    deg_lo = (int8_t)(atan(sqrt(pow(dist_lo - orig_dist, 2) + pow(HEIGHT_FROM_DOWNSIDE_TO_LOWERSENSOR,2)) * 2));
    deg_si = (int8_t)(atan(sqrt(pow(moved_dist, 2) + pow(HEIGHT_FROM_DOWNSIDE_TO_LOWERSENSOR,2)) * 2));
}
