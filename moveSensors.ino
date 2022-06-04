// 現在この関数の使用はしない

int moveSensors()
{
    // 先に右側のモータを動かす
    int moved = moveSensor("ri", 0);

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

    return moved;
}