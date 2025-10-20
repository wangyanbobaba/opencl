# opencl
opencl使用说明：
1. 简介：  
    因为opencv支持opencl来调用gpu来处理图像，而且rk平台一般都支持opencl，因此这里介绍使用opencv的opencl版本来使用GPU处理图像。  

2. 参考资料：
    1. c++ OpenCL硬件加速，这个链接完整介绍了如何使用opencv，opencl来使用RK3588 gpu加速处理图像数据：https://blog.csdn.net/qq_39201211/article/details/142846807
    2. 安装opencv4.6.0，参考链接：https://blog.csdn.net/whitephantom1/article/details/136406214
    3. rk平台上gpu驱动环境配置：https://blog.csdn.net/CATTLE_L/article/details/147637512

3. 如何判断rk平台上有GPU驱动？  
    1. 参考资料3：https://blog.csdn.net/CATTLE_L/article/details/147637512

    2. 可以通过ls /dev/m*命令查看是否有内核驱动。没有/dev/mali0就是内核没有驱动
        ```
        root@firefly:~# ls /dev/m*
        /dev/mali0   /dev/media1  /dev/mem      /dev/mmcblk0boot0  /dev/mmcblk0p1  /dev/mmcblk0p3  /dev/mmcblk0p5  /dev/mmcblk0p7    /dev/mpp_service
        /dev/media0  /dev/media2  /dev/mmcblk0  /dev/mmcblk0boot1  /dev/mmcblk0p2  /dev/mmcblk0p4  /dev/mmcblk0p6  /dev/mmcblk0rpmb
        ```



4. 在rk平台上配置好环境后，如何使用opencv opencl调用gpu来做图像处理。
    1. 参考资料1（https://blog.csdn.net/qq_39201211/article/details/142846807）提供的demo.
    2. 如果安装到默认位置的opencv库不支持opencl，则自己安装opencv库。参考资料2（2. 安装opencv4.6.0，参考链接：https://blog.csdn.net/whitephantom1/article/details/136406214）。

5. 常用命令：
    1. 查看gpu占用率
        ```
        cat /sys/class/devfreq/fb000000.gpu/load
        # 范围从 0 到 100，数值越大表示 GPU 越忙
        ```


