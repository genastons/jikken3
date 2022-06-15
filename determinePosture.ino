void determinePosture(void)
{
    if (deg_hi > Pi/18) {   
        st = TOO_LEAN_FORWARD;
    } else if (deg_hi < 0) {
        st = TOO_LEAN_BACKWARD;
    } else if (deg_si < -Pi/36) {
        st = TOO_LEAN_FORRIGHT;
    } else if (deg_si > Pi/36) {
        st = TOO_LEAN_FORLEFT;
    }
    return 0;
}