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
    if(celsius <= 0)
    {
        printf("Temperature category: Freezing \n");
        printf("Weather Advisory: Be careful of ice on the roads");
    }
    if(celsius > 0 && celsius <= 10 )
    {
        printf("Temperature category: Cold \n");
        printf("Weather Advisory: Wear a jacket");
    }
    if(celsius > 10 && celsius <= 25 )
    {
        printf("Temperature category: Comfortable \n");
        printf("Weather Advisory: The weather is really nice");
    }
    if(celsius > 25 && celsius <= 35 )
    {
        printf("Temperature category: Hot \n");
        printf("Weather Advisory: Stay cool");
    }
    if(celsius > 35)
    {
        printf("Temperature category: Extreme Heat \n");
        printf("Weather Advisory: Drink lots of water today");
    }
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
        //Stores the Celsius degrees for later use in categorizing
        endTemperature = fahrenheitToCelsius(temperature);
        temperature = endTemperature;

        //Converts to wanted Scale 
        if(convertScale == 3)
            endTemperature = celsiusToKelvin(endTemperature);
    }
    if(currentScale == 3)
    {
        //Stores the Celsius degrees for later use in categorizing
        endTemperature = kelvinToCelsius(temperature);
        temperature = endTemperature;
        
        //Converts to wanted Scale 
        if(convertScale == 2)
            endTemperature = celsiusToFahrenheit(endTemperature);
    }
    // Prints convered temperature and advice 
    printf("Converted Temperature: %f \n", endTemperature);
    categorizeTemp(temperature);
    return 0;
}