#define redPin1 2
#define yellowPin1 3
#define greenPin1 4
#define redPin2 7
#define yellowPin2 A3
#define greenPin2 9
#define redPin3 A0
#define yellowPin3 A1
#define greenPin3 A2
#define interval 8000
const int ir11 = 5;
const int ir12 = 6;
const int ir21 = 10;
const int ir22 = 11;
const int ir31 = 12;
const int ir32 = 8;
int lane1[3] = { redPin1, yellowPin1, greenPin1 };
int lane2[3] = { redPin2, yellowPin2, greenPin2 };
int lane3[3] = { redPin3, yellowPin3, greenPin3 };

const int MAX_QUEUE_SIZE = 3;

class Queue {
private:
  int front, rear, count;
  int array[MAX_QUEUE_SIZE];
public:
  Queue() {
    front = 0;
    rear = -1;
    count = 0;
  }

  bool isEmpty() {
    return count == 0;
  }
  bool isFull() {
    return count == MAX_QUEUE_SIZE;
  }
  void enqueue(int value) {
    if (!isFull()) {
      rear = (rear + 1) % MAX_QUEUE_SIZE;
      array[rear] = value;
      count++;
    }
  }

  void dequeue() {
    if (!isEmpty()) {
      front = (front + 1) % MAX_QUEUE_SIZE;
      count--;
    }
  }

  int Front() {
    if (!isEmpty()) {
      return array[front];
    }
    return -1;  
  }
};

Queue myQueue;
void setup() {

  Serial.begin(9600);
  pinMode(redPin1, OUTPUT);
  pinMode(yellowPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(yellowPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(redPin3, OUTPUT);
  pinMode(yellowPin3, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(ir11, INPUT);
  pinMode(ir12, INPUT);
  pinMode(ir21, INPUT);
  pinMode(ir22, INPUT);
  pinMode(ir31, INPUT);
  pinMode(ir32, INPUT);
}
void loop() {
  int density1 = digitalRead(ir11) + digitalRead(ir12);
  int density2 = digitalRead(ir21) + digitalRead(ir22);
  int density3 = digitalRead(ir31) + digitalRead(ir32);
  int total_density = density2 + density1 + density3;

  float fairShare1 = (float)density1 / total_density * interval;
  float fairShare2 = (float)density2 / total_density * interval;
  float fairShare3 = (float)density3 / total_density * interval;
  if (fairShare1 == fairShare2 && fairShare2 == fairShare3) {
    digitalWrite(lane1[2], HIGH);
    delay(1000);
    digitalWrite(lane1[2], LOW);

    delay(500);
    digitalWrite(lane2[2], HIGH);
    delay(1000);
    digitalWrite(lane2[2], LOW);

    delay(500);
    digitalWrite(lane3[2], HIGH);
    delay(1000);
    digitalWrite(lane3[2], LOW);

    delay(500);
  }

  // if (fairShare1 != 0 || fairShare2 != 0 || fairShare3 != 0) {
  else {

    if (fairShare1 >= fairShare2 && fairShare2 >= fairShare3) {
      myQueue.enqueue(fairShare1);
      if(fairShare2>0 && fairShare3>0){
      myQueue.enqueue(fairShare2);
      myQueue.enqueue(fairShare3);
      }
    } else if (fairShare1 >= fairShare3 && fairShare3 >= fairShare2) {
      // std::cout << a << " " << c << " " << b << std::endl;
      myQueue.enqueue(fairShare1);
      if (fairShare3 > 0 && fairShare2 > 0) {
        myQueue.enqueue(fairShare3);
        myQueue.enqueue(fairShare2);
      }

    } else if (fairShare2 >= fairShare1 && fairShare1 >= fairShare3) {
      myQueue.enqueue(fairShare2);
      if (fairShare1 > 0 && fairShare3 > 0) {
        myQueue.enqueue(fairShare1);
        myQueue.enqueue(fairShare3);
      }

      // std::cout << b << " " << a << " " << c << std::endl;
    } else if (fairShare2 >= fairShare3 && fairShare3 >= fairShare1) {
      // std::cout << b << " " << c << " " << a << std::endl;
      myQueue.enqueue(fairShare2);
      if (fairShare3 > 0 && fairShare1 > 0) {
        myQueue.enqueue(fairShare3);
        myQueue.enqueue(fairShare1);
      }

    } else if (fairShare3 >= fairShare1 && fairShare1 >= fairShare2) {
      //std::cout << c << " " << a << " " << b << std::endl;
      myQueue.enqueue(fairShare3);
      if (fairShare1 > 0 && fairShare2 > 0) {
        myQueue.enqueue(fairShare1);
        myQueue.enqueue(fairShare2);
      }

    } else {
      // std::cout << c << " " << b << " " << a << std::endl;
      myQueue.enqueue(fairShare3);
      if (fairShare2 > 0 && fairShare1 > 0) {
        myQueue.enqueue(fairShare2);
        myQueue.enqueue(fairShare1);
      }
    }

    while (!myQueue.isEmpty()) {
      if (myQueue.Front() == fairShare1) {
        digitalWrite(lane1[2], HIGH);
        delay(fairShare1);
        digitalWrite(lane1[2], LOW);

      }else if (myQueue.Front() == fairShare2) {
        digitalWrite(lane2[2], HIGH);
        delay(fairShare2);
        digitalWrite(lane2[2], LOW);

      } else {
        digitalWrite(lane3[2], HIGH);
        delay(fairShare3);
        digitalWrite(lane3[2], LOW);
      }
      myQueue.dequeue();
    }
  }
}