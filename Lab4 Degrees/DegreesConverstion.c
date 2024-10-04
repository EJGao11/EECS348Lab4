#include <stdio.h>

//Conversion Formulas with functions 
float celsiusToFahrenheit (float celsius)
{
    return ((9.0/5.0)*celsius) + 32;
}

float fahrenheitToCelsius (float fahrenheit)
{
    return (5.0/9.0)*(fahrenheit - 32);
}

float celsiusToKelvin(float celsius)
{
    return celsius + 273.15;
}

float kelvinToCelsius (float kelvin)
{
    return kelvin - 273.15;
}

// Take the temp in celsius than gives advice 
void categorizeTemp (float celsius)
{
    printf("Sup");
}

int main() 
{

    float temperature = 0;
    int currentScale = 0;
    int convertScale = 0;
    // Takes user input
    printf("Enter the Temperature: ");
    scanf("%f", &temperature);

    printf("Choose the Current Scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &currentScale);

    printf("Convert to (1) Celsius, (2) Fahrenheit,(3) Kelvin: ");
    scanf("%d", &convertScale);

    // Looks for conversion errors  
    if(convertScale == currentScale)
    {
        printf("Invaild Conversion");
        return -1;
    }
    if(currentScale == 1 && temperature < -273.15)
    {
        printf("Invaild Current Temperature");
        return -1;
    } 
    if(currentScale == 2 && temperature < -459.67)
    {
        printf("Invaild Current Temperature");
        return -1;
    }
    if(currentScale == 3 && temperature < 0)
    {
        printf("Invaild Current Temperature");
        return -1;
    }

    
    // First locates the current temperture scale
    float endTemperature = 0;
    if(currentScale == 1)
    {
        //converts the current scale to wanted scale 
        if(convertScale == 2)
            endTemperature = celsiusToFahrenheit(temperature);
        if(convertScale == 3 )
            endTemperature = celsiusToKelvin(temperature);
        
    }
    if(currentScale == 2)
    {
        endTemperature = fahrenheitToCelsius(temperature);
        if(convertScale == 3)
            endTemperature = celsiusToKelvin(endTemperature);
    }
    if(currentScale == 3)
    {
        endTemperature = kelvinToCelsius(temperature);
        if(convertScale == 2)
            endTemperature = celsiusToFahrenheit(endTemperature);
    }
    // Prints convered temperature and advice 
    printf("Converted Temperature: %f \n", endTemperature);
    categorizeTemp(temperature);
    return 0;
}