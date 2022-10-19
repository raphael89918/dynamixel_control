1. "camera_control" node調整相機角度
2. "control" 透過conio node按鍵操作各個步驟
3. "laser_control" node控制下面2根laser支架\
使用wheel_laser.msg進行控制 topic名稱 "/dynamixel/wheel_laser"\
if bool=1 支架展開,if bool=0 支架收起\
4. "trunk" node控制夾爪與擋板,自動化夾取與堆疊