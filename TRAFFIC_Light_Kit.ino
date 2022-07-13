// Servo모터 라이브러리는 아두이노에 기본적으로 포함되어 있습니다
#include <Servo.h>                // 서보모터 라이브러리 헥사파일을 불러옵니다

Servo myservo;                    // 서보모터의 이름을 myservo로 설정합니다

int servoPin = 3;                 // 서보모터 제어선을 3번핀으로 선언합니다
int Gbutton = 4;                  // 그린버튼 제어선을 4번핀으로 선언합니다
int Rbutton = 5;                  // 레드버튼 제어선을 5번핀으로 선언합니다

int Green_SW = 0;                 // loop에서 사용할 Green_SW 변수를 선언합니다
int Red_SW = 0;                   // loop에서 사용할 Red_SW 변수를 선언합니다

int TrafficRed = 9;               // 신호등 Red LED 제어선을 9번핀으로 선언합니다
int TrafficYellow = 10;           // 신호등 Yellow LED 제어선을 10번핀으로 선언합니다
int TrafficGreen = 11;            // 신호등 Green LED 제어선을 11번핀으로 선언합니다


void setup() 
{
  pinMode(servoPin, OUTPUT);      // 서보모터 제어핀을 출력으로 설정합니다
  myservo.attach(servoPin);       // 서보모터가 servoPin(3번)에 접속되도록 설정합니다
  myservo.write(90);              // 서보모터를 90도에서 시작하게 설정합니다
  
  pinMode(Gbutton, INPUT);        // 그린버튼 제어핀을 입력으로 설정합니다
  pinMode(Rbutton, INPUT);        // 레드버튼 제어핀을 입력으로 설정합니다
  digitalWrite(Gbutton, 0);       // 그린버튼을 시작할때 설정을 초기화합니다
  digitalWrite(Rbutton, 0);       // 레드버튼을 시작할때 설정을 초기화합니다 
  
  pinMode(TrafficRed, OUTPUT);    // 신호등 Red LED 제어핀을 출력으로 설정합니다
  pinMode(TrafficYellow, OUTPUT); // 신호등 Yellow LED 제어핀을 출력으로 설정합니다
  pinMode(TrafficGreen, OUTPUT);  // 신호등 Green LED 제어핀을 출력으로 설정합니다
}

void loop() 
{
  Green_SW = digitalRead(Gbutton);   // 그린버튼을 디지털신호로 읽어서 선언된 변수 Green_SW에 저장합니다
  Red_SW = digitalRead(Rbutton);     // 레드버튼을 디지털신호로 읽어서 선언된 변수 Red_SW에 저장합니다
  
  if (Green_SW == HIGH) {              // 만약 Green_SW변수가 HIGH라면
    digitalWrite(TrafficRed, LOW);     // 신호등 Red LED를 꺼라
    digitalWrite(TrafficYellow, HIGH); // 신호등 Yellow LED를 켜라
    delay(1000);                       // 1초간 켜지고
    digitalWrite(TrafficYellow, LOW);  // 신호등 Yellow LED를 꺼라
    delay(300);                        // 0.3초간 꺼지고
    digitalWrite(TrafficGreen, HIGH);  // 신호등 Green LED를 켜라
    myservo.write(90);                 // 서보모터를 90도로 움직여라
  }
  
  if (Red_SW == HIGH) {                // 만약 Red_SW변수가 HIGH라면
    digitalWrite(TrafficGreen, LOW);   // 신호등 Green LED를 꺼라
    digitalWrite(TrafficYellow, HIGH); // 신호등 Yellow LED를 켜라
    delay(1000);                       // 1초간 켜지고
    digitalWrite(TrafficYellow, LOW);  // 신호등 Yellow LED를 꺼라
    delay(300);                        // 0.3초간 꺼지고
    digitalWrite(TrafficRed, HIGH);    // 신호등 Red LED를 켜라
    myservo.write(0);                  // 서보모터를 0도로 움직여라
  }

}
