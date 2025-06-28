# Smart Car Parking System

## Introduction
In our country, we see people suffer sometimes due to the poor parking system in parking slots, which are manually controlled by humans. Instead, if we use a smart car parking system, we can save time, and people will be able to park their cars in the slots by themselves easily. And also, A high car density on the road due to population growth results in inadequate parking spaces and traffic problems, according to a survey of metropolitan areas. Vehicle parking is a significant issue in many places because of the rise in urbanization. For many drivers, finding adequate parking spaces is a huge challenge, especially when they are visiting crowded public venues like malls, movie theaters, five-star hotels, etc. The parking spaces offered in multi-storey buildings, malls, multi-complex buildings, etc. typically work manually, meaning a person is designated to watch over vacant slots, which wastes time and fuel and is therefore inefficient. Drivers often squander time and fuel today when people are in a rush, and there is such high inflation that fuel prices are.

## Components
The proposed project requires:  
  - 2 pieces of Infrared Sensor (IR)
  - 1 piece of Servo Motor
  - 3 pieces of Ultrasonic Sonar Sensor
  - 1 piece of LED
  - 1 piece of Buzzer
  - 1 piece of LCD
  - 1 piece of Arduino Uno
  - Power Source
  - Jumper wires
  - Resistors

## Project Details
The proposed project will perform some smart actions depending on some specified components, such as:
  1. It can show the parking slot information (for example, if there's any empty slot or all slots are booked) via LCD on the basis of the information from the Sonar sensor.
  2. It has an automatic door/gate opening and closing system with the help of a servo and an IR sensor.
  3. It has an automatic lighting system (for example, at night or when it is cloudy weather, the parking area’s LED light will turn on, and during the daytime it is turned off automatically) with the help of an LDR sensor and LED.
  4. It will notify the entry and exit of a car via beeping with the help of a buzzer.  

Here when a new car come the IR sensor detect it send the data to Arduino and it open the Door via servo motor action and beep the buzzer once to indicate a new entry and when the car goes to one of the parking slots, the associated ultrasonic sonar sensor send data to the Arduino and via LCD it will shows the remaining empty slot. Now, when a car goes out similar thing happens, data goes from the associated ultrasonic sensor to Arduino, and Arduino beeps the buzzer twice to notify one exit and shows the remaining empty slot via LCD. Moreover, depending on the lighting situation in the parking area, the LDR sends a value to Arduino, and the Arduino turns on or off the LED light automatically.

## Project Design
The following figure shows the connection among the components and the overall setup:

![Hardware setup](https://github.com/faiyaz-masrur/iot-based-smart-car-parking-system-using-arduino-uno/blob/41458cb6b36f9f16ed893844583b91af559fee4a/Design.jpg)

