void getData() {
    // モータがどれだけ動いたか取得する

    moved = moveSensor("ri", 0);

    if (moved > 0) {
        // モータの回転方向が互いに逆になるように配置することで、
        // もう一方のモータは逆方向に動かす
        moveSensor("le", moved);
    } else {
        moved = moveSensor("le", 0);
        if (moved > 0) {
            moveSensor("ri", moved);
        }
    }

    dist_hi = getDist(TRIG_HI, ECHO_HI);
    dist_lo = (getDist(TRIG_RI, ECHO_RI) + getDist(TRIG_LE, ECHO_LE)) / 2;

    deg_hi = atan(sqrt(pow(dist_lo - dist_hi), 2) + pow(__DIST_FROM_HIGH_TO_LOW, 2));
    deg_lo = atan(sqrt(pow(dist_lo - orig_dis_lo), 2) + pow(__HEIGHT_FROM_DOWNSIDE_TO_LOWERSENSOR,2));

    return 0;
}
