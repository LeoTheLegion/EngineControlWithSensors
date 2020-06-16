extern "C"{
    #include <Sensors.h>
    #include <Engine.h>
}

int SSR = 8;

float lightSensor,tempSensor;

float normalLight,normalTemp;

bool shouldMoveForward = true;

void setup() {
  // put your setup code here, to run once:
    setupSensors();
    setupEngine();
    setupSSR();


    normalLight = readSensor(Light);
    normalTemp = getTemperatureInFahrenheit();
}

void loop() {
  // put your main code here, to run repeatedly: 
    tempSensor = getTemperatureInFahrenheit();
    lightSensor = readSensor(Light);

    if(tempSensor > normalTemp * 1.02){
        digitalWrite(SSR, HIGH);
    }else if (tempSensor < normalTemp * 1.01){
        digitalWrite(SSR, LOW);
    }


    OnTouch();

    if(lightSensor > normalLight * 1.1 || lightSensor > 1023){//dark
        setState(Brake);
    }else if (lightSensor < normalLight * 0.5){//light
        setEnginePower(1.0);
        if(shouldMoveForward)
            setState(Forward);
        else
            setState(Backward);
    }else{
        setEnginePower(0.2);// temp 0.2 since I can't see difff
        if(shouldMoveForward)
            setState(Forward);
        else
            setState(Backward);
    }
}

void OnTouch(){
    if(readSensor(Touch) < 1000){
        while(readSensor(Touch) < 1000){

            }
        shouldMoveForward = !shouldMoveForward;
    }

}

void setupSSR(){
    pinMode(SSR, OUTPUT);
    digitalWrite(SSR, HIGH);
}

float getTemperatureInFahrenheit(){
    return readSensor(Temperature) * (3.3/1024) * 100;
}
