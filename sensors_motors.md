01. 초음파 센서


1) 초음파 센서란?

- 사람의 귀에 들리지 않을 정도로 높은 주파수(약 20 KHz 이상)의 소리인 초음파가 가지고 있는 특성을 이용한 센서

- 가까운 거리에 있는 물체 혹은 사람의 유, 무, 거리 측정, 속도 측정 등에 사용됨.


2) 초음파 센서 사양

<img width="380" alt="image" src="https://user-images.githubusercontent.com/87634136/174248340-796ce529-cb31-4c71-8a3f-301bf7e1d0bc.png">

3) 초음파 센서 작동 원리

<img width="323" alt="image" src="https://user-images.githubusercontent.com/87634136/174248394-2525d1b9-fcee-4187-9c2f-8f95235f112e.png">

- 1cm 이동하는데 걸리는 시간 : 58us


<동작 순서>

1.초음파 센서의 Trigger 입력으로 10us의 펄스 입력

2.초음파 센서에서는 40KHz의 초음파를 8번 연속해서 발생

3.초음파 발생 직후 Echo 출력을 High로 설정

4.반사된 초음파를 수신하면 Echo 출력을 Low로 설정

5.Echo 출력의 펄스폭을 주어진 공식으로 계산하여 거리를 구함


4) 초음파 센서 거리 측정

<img width="395" alt="image" src="https://user-images.githubusercontent.com/87634136/174249120-47324120-7740-48f9-94ca-d1a93919fb56.png">



02. DC 모터


1) DC 모터란?

- 직류 전압을 사용하는 모터를 말하며, 속도 및 방향을 비교적 간단하게 제어할 수 있기 때문에 다양한 분야에서 사용됨

- Ex) RC카, 휴대용 선풍기 등


2) DC 모터 사양

<img width="373" alt="image" src="https://user-images.githubusercontent.com/87634136/174249203-1edf1c0c-dd18-4e2a-b2b5-5fb646f5ef09.png">

3) DC 모터의 회전 원리

<img width="192" alt="image" src="https://user-images.githubusercontent.com/87634136/174249260-61976ebd-a409-48a5-81f1-00682edd5ec8.png">

- 직류 전류를 전원으로 하여 돌아가는 모터 

- 전류가 흐르면 오른손 법칙에 의해서 N극은 힘이 위로 S극은 힘이 아래로 받음 -> 시계방향으로 회전함.


4) DC 모터 속도 조절

<img width="206" alt="image" src="https://user-images.githubusercontent.com/87634136/174249305-d777fe5d-763d-456b-a0fb-66856976b7cb.png">

-> PWM 제어를 사용

- 모터의 회전 속도를 증가, 감소하기 위한 가장 효율적이고 간편한 방법

- If ) 8bit일때, 비교일치/255 *100 = 듀티비


03. 레귤레이터

1) 레귤레이터란?

: 일정 전압을 잡아주는 역할 ( 리니어 레귤레이터 )


2) 레귤레이터 사양

<img width="260" alt="image" src="https://user-images.githubusercontent.com/87634136/174249414-f8fd1971-3784-4200-a7bb-6e740192b003.png">


04. 모터 드라이버

​

1) 모터 드라이버

- 모터드라이버를 사용하면 토크 제어, 속도 제어, 전압 제어, 전류 제어, 위치 제어 등을 정확하게 할 수 있고, 모터 보호 기능 또한 할 수 있음

- 모터 제어 및 방향, 속도 조절 Enable 핀으로 모터 자체를 끄고 켤 수 있음.

<img width="308" alt="image" src="https://user-images.githubusercontent.com/87634136/174249489-9bd25e96-b242-42b8-8fe5-1131a596d50c.png">


2) 모터 드라이버 사양

<img width="328" alt="image" src="https://user-images.githubusercontent.com/87634136/174249528-5daa4d4e-eaa8-4946-8d88-a5ebc7b35848.png">


3) 모터 드라이버 방향 제어 (H-Bridge 회로)

<img width="257" alt="image" src="https://user-images.githubusercontent.com/87634136/174249567-3c4ebfa2-1534-4757-9db3-37c68ca37504.png">

- 모터를 정방향, 역방향으로 제어 할 수 있도록 구성된 정역 제어 회로​


4) 모터 드라이버 내부 로직

<img width="326" alt="image" src="https://user-images.githubusercontent.com/87634136/174249615-d609353e-ffa8-4b20-862c-2d35a83e7a00.png">
