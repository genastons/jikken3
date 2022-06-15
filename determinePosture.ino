void determinePosture(void)
{
    if ((dist_hi > NO_SEATED_DIST) && (dist_lo > NO_SEATED_DIST)) {
        st = NO_SEATED;
    } else if (deg_hi > Pi/18) { // 調べろ  
        status = TOO_LEAN_FORWARD;
    } else if (deg_hi < 0) {
        st = TOO_LEAN_BACKWARD;
    } else if (deg_si < -Pi/36) {
        st = TOO_LEAN_FORRIGHT;
    } else if (deg_si > Pi/36) {
        st = TOO_LEAN_FORLEFT;
    }
    return 0;
}