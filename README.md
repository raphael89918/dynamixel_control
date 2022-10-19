2. "camera_control" node調整相機角度
3. "control" 透過conio node按鍵操作各個步驟
4. "laser_control" node控制下面2根laser支架
[Tab]使用wheel_laser.msg進行控制 topic名稱 "/dynamixel/wheel_laser"
[Tab] if bool=1 支架展開,if bool=0 支架收起
5. "trunk" node控制夾爪與擋板,自動化夾取與堆疊