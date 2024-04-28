# kernel-programming

1. ioctl 통신 확인을 위해 터미널 창 2개 켜기

2. 모니터링을 위해 터미널 1에서는 ```dmesg -w```

3. ```sudo insmod ssafy.ko``` : 커널 내부에 삽입할 커널 모듈 형식의 디바이스 드라이버
   
<br>

```sudo mknod /dev/ssafyFile c 100 0``` : user 프로그램이 디바이스 드라이버에 접근하기 위한 디바이스 파일 생성

<br>

```sudo chmod 666 /dev/ssafyFile``` : 디바이스 파일에 권한 부여

<br>

```./user``` : 통신



![ioctl](https://github.com/BaeYunjae/kernel-ioctl/assets/88019800/4afe6d5e-3662-4f4b-af7c-533a3064e1c8)
