#define F_CPU 7372800UL

#include <avr/io.h>

#include <util/delay.h>

#include <avr/interrupt.h>

#include <stdlib.h>

​

volatile unsigned int distance = 0, flag = 0, count = 0, push = 0;

volatile unsigned char duty;

unsigned char num = 0;

int led;

​

void setting() {

	//DC모터

	TCCR1A = 0x09; //0b00001001 (Fast PWM 8비트)

	TCCR1B = 0x0b; //0b00001011 (분주비 64)

	//초음파 센서

	TCCR3B = 0x0a; //0b00001010 CTC모드, 분주비 8

	ETIMSK = 0x10; //0b00010000 비교일치 인터럽트 허용

	EICRB = 0x03; //0b00000011 상승 모서리에서 인터럽트 요구

	EIMSK = 0x10; //0b00010000 INT4 인터럽트 허용

	OCR3A = 0; //비교일치 레지스터 초기화

}

​

ISR(TIMER3_COMPA_vect) { //타이머카운터3 비교일치모드

	if (count < 10) { //10uS가 되기 전

		PORTE = 0x08; //E3(Trigger)

		OCR3A = 1; //1us

	}

	else { // 10uS가 되었을 때

		PORTE = 0x00;

		OCR3A = 55296; //(7372800/8)*0.06=55296 (측정 주기: 60ms 이상으로 할 것-데이터시트)

		count = 0;

	}

	count++;

}

​

ISR(INT4_vect) { //E4(Echo)

	if (flag == 0) {

		TCNT3 = 0; // TCNT값 리셋

		EICRB = 0x02; // 하강모서리 인터럽트

		flag = 1;

	}

	else {

		distance = TCNT3 / 58; //에코 신호 수신 공식:uS/58=cm

		EICRB = 0x03; //상승모서리 인터럽트

		flag = 0;

	}

}

​

int main(void) {

	DDRA = 0Xff; //led 출력

	DDRB = 0x80; //PORTB7 출력(EnableA)

	DDRD = 0xc0; //D0,D1,D2 스위치 입력, D7,D6 모터 출력

	DDRE = 0x08; //E3 트리거 입력, E4 에코 출력

	PORTA = ~0x00; //초기상태 led Off

	PORTB = 0x80; //모터 드라이버 출력 허용

	​

		setting();

	sei(); //전역 인터럽트 허용

	int x;

	​

		while (1) {

			//속도 조절

			x = abs(distance - 10); //절댓값 표시

			duty = 10 * x + 150; //dc모터의 회전 속도 조절

			if (duty >= 150) duty = 150; //dc모터의 최대 속도

			OCR1C = duty; //듀티값을 OCR값으로 설정

			​

				if ((~PIND & 0x0F) == 0x01) { //0번째 스위치를 눌렀을 때

					_delay_ms(20);

					push++;

					while (~PIND & 0x04);

				}

			if (push == 1) { //한 번 누르면 정회전

				if (3 > distance) {

					led = 0x01;

					PORTA = ~led;

					PORTD = 0x80;

				}

				else if (6 > distance) {

					led = 0x03;

					PORTA = ~led;

					PORTD = 0x80;

				}

				else if (9 > distance) {

					led = 0x07;

					PORTA = ~led;

					PORTD = 0x80;

				}

				else if (12 > distance) {

					led = 0x0f;

					PORTA = ~led;

					PORTD = 0x80;

				}

				else if (15 > distance) {

					led = 0x1f;

					PORTA = ~led;

					PORTD = 0x80;

				}

				else if (18 > distance) {

					led = 0x3f;

					PORTA = ~led;

					PORTD = 0x80;

				}

				else if (21 > distance) {

					led = 0x7f;

					PORTA = ~led;

					PORTD = 0x80;

				}

				else if (24 > distance) {

					led = 0xff;

					PORTA = ~led;

					PORTD = 0x80;

				}

			}

			else if (push == 2) { //두 번 누르면 역회전

				if (3 > distance) {

					led = 0x80;

					PORTA = ~led;

					PORTD = 0x40;

				}

				else if (6 > distance) {

					led = 0xc0;

					PORTA = ~led;

					PORTD = 0x40;

				}

				else if (9 > distance) {

					led = 0xe0;

					PORTA = ~led;

					PORTD = 0x40;

				}

				else if (12 > distance) {

					led = 0xf0;

					PORTA = ~led;

					PORTD = 0x40;

				}

				else if (15 > distance) {

					led = 0xf8;

					PORTA = ~led;

					PORTD = 0x40;

				}

				else if (18 > distance) {

					led = 0xfc;

					PORTA = ~led;

					PORTD = 0x40;

				}

				else if (21 > distance) {

					led = 0xfe;

					PORTA = ~led;

					PORTD = 0x40;

				}

				else if (24 > distance) {

					led = 0xff;

					PORTA = ~led;

					PORTD = 0x40;

				}

			}

			else if (push > 2) push = 1;

			​

				​

		}

	if ((~PIND & 0x0F) == 0x02) { //1번째 스위치를 눌렀을때

		_delay_ms(35);

		PORTD = 0x00; //정지

		while (~PIND & 0x02);

		_delay_ms(35);

	}

	​

	else if ((~PIND & 0x0F) == 0x04) { //2번째 스위치를 눌렀을때

		_delay_ms(20);

		num++;

		while (~PIND & 0x04);

	}

	if (num == 1) {

		_delay_ms(20);

		PORTD = 0x80; //정회전(오른쪽)

		OCR1C = 255;

	}

	else if (num == 2) {

		_delay_ms(20);

		PORTD = 0x40; //역회전(왼쪽)

		OCR1C = 255;

	}

	else if (num > 2) num = 1;

}