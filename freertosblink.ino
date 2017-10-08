#include <Arduino_FreeRTOS.h>

TaskHandle_t TaskHandle_1;
TaskHandle_t TaskHandle_2;
TaskHandle_t TaskHandle_3;


void setup()
{  
    Serial.begin(9600);
    pinMode(1,OUTPUT);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    
    Serial.println(F("In Setup function"));

   

    /* Create a task with priority 3. Capture the Task details to its handler*/
    xTaskCreate(MyTask1, "Task1", 120, NULL, 1, &TaskHandle_1);
    xTaskCreate(MyTask2, "Task2", 120, NULL, 2, &TaskHandle_2);  
    xTaskCreate(MyTask3, "Task3", 120, NULL, 3, &TaskHandle_3);
}


void loop()
{
    // Hooked to IDle task, it will run whenever CPU is idle
    Serial.println(F("Loop function"));
    delay(1000);
}


/* Task1 with priority 1 */
static void MyTask1(void* pvParameters)
{
    while(1)
    {
        Serial.println(F("Task1 Running"));
        digitalWrite(1,HIGH);
        delay(200);
        digitalWrite(1,LOW);
        delay(200);
        vTaskDelay(250/portTICK_PERIOD_MS);
    }
}


/* Task2 with priority 2 */
static void MyTask2(void* pvParameters)
{
    while(1)
    {    
        Serial.println(F("Task2 Running"));
        digitalWrite(2,HIGH);
        delay(200);
        digitalWrite(2,LOW);
        delay(200);
        vTaskDelay(300/portTICK_PERIOD_MS);
    }
}


/* Task3 with priority 3 */
static void MyTask3(void* pvParameters)
{
    
       while(1)
      {    
        Serial.println(F("Task3 Running"));
        digitalWrite(3,HIGH);
        delay(200);
        digitalWrite(3,LOW);
        delay(200);
        vTaskDelay(400/portTICK_PERIOD_MS);
    }
}
