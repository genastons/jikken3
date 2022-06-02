void getData() {
    // モータを動かすが、setupでも呼び出して初期値を取得できるように書き込む値は引数で渡す  
    // モータがどれだけ動いたか取得する
    int moved = moveSensors();

    // 現在のモータの角度を取得する
    int pre_r = servo_right.read();
    int pre_l = servo_left.read();

    // モータを動かす
    servo_right.write(pre_r + moved);
    servo_left.write(pre_l - moved);

    getDist(dist_up);
    getDist(dist_ri);
    getDist(dist_le);
    dist_dw = (dist_ri + dist_le) / 2;

    deg_up = atan(sqrt(pow(dist_dw - dist_up), 2) + pow(__DIST_FROM_UP_TO_DOWN, 2));
    deg_dw = atan(sqrt(pow(dist_dw - orig_dis_dw), 2) + pow(__HEIGHT_FROM_DOWNSIDE_TO_LOWERSENSOR,2));
}
