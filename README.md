1. "camera_control" node調整相機角度
2. "control" 透過conio node按鍵操作各個步驟
3. "laser_control" node控制下面2根laser支架\
使用wheel_laser.msg進行控制 topic名稱 "/dynamixel/wheel_laser"\
if bool=1 支架展開,if bool=0 支架收起

4. "trunk" node控制夾爪與擋板,自動化夾取與堆疊\
使用arm_trunk.msg進行控制 topic名稱 "/dynamixel/arm_storage"\
if = 1 木板傾斜\
if = 2 夾爪夾取動作\
if = 3 積木放置於木板\
if = 4 夾爪回到前面夾取位置\
if = 5 積木放置堆疊\
if = 6 回到初始位置