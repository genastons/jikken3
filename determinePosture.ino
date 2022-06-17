void determinePosture(void)
{
    if (deg_hi > M_PI/18) {   
        st = status::TOO_LEAN_FORWARD;
    } else if (deg_hi < 0) {
        st = status::TOO_LEAN_BACKWARD;
    } else if (deg_si < -M_PI/36) {
        st = status::TOO_LEAN_FORRIGHT;
    } else if (deg_si > M_PI/36) {
        st = status::TOO_LEAN_FORLEFT;
    }
}
