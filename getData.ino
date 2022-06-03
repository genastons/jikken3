void getData() {
    // モータを動かすが、setupでも呼び出して初期値を取得できるように書き込む値は引数で渡す  
    // モータがどれだけ動いたか取得する
    int moved = moveSensors();

    getDist(dist_hi);
    getDist(dist_ri);
    getDist(dist_le);
    dist_lo = (dist_ri + dist_le) / 2;

    deg_hi = atan(sqrt(pow(dist_lo - dist_hi), 2) + pow(__DIST_FROM_HIGH_TO_LOW, 2));
    deg_lo = atan(sqrt(pow(dist_lo - orig_dis_lo), 2) + pow(__HEIGHT_FROM_DOWNSIDE_TO_LOWERSENSOR,2));

    return 0;
}
