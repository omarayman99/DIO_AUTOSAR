#include "Dio.h"
#include "hw_gpio.h"

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint8 Local_Val = ChannelId/NUMBER_OF_PORTS;
    Dio_LevelType Read_Val = 0;
    switch(ChannelId)
    {
    case PORTA:
        Local_Val %= NUMBER_OF_PINS;
        if( (GPIO_PORTA_DATA_R &  (1U<<Local_Val)) >> Local_Val)
        {
            Read_Val = STD_HIGH;
        }
        else
        {
            Read_Val = STD_LOW;
        }
        break;
    case PORTB:
        Local_Val %= NUMBER_OF_PINS;
        if( (GPIO_PORTB_DATA_R &  (1U<<Local_Val)) >> Local_Val)
        {
            Read_Val = STD_HIGH;
        }
        else
        {
            Read_Val = STD_LOW;
        }
        break;
    case PORTC:
        Local_Val %= NUMBER_OF_PINS;
        if( (GPIO_PORTC_DATA_R &  (1U<<Local_Val)) >> Local_Val)
        {
            Read_Val = STD_HIGH;
        }
        else
        {
            Read_Val = STD_LOW;
        }
        break;
    case PORTD:
        Local_Val %= NUMBER_OF_PINS;
        if( (GPIO_PORTD_DATA_R &  (1U<<Local_Val)) >> Local_Val)
        {
            Read_Val = STD_HIGH;
        }
        else
        {
            Read_Val = STD_LOW;
        }
        break;
    case PORTE:
        Local_Val %= NUMBER_OF_PINS;
        if( (GPIO_PORTE_DATA_R &  (1U<<Local_Val)) >> Local_Val)
        {
            Read_Val = STD_HIGH;
        }
        else
        {
            Read_Val = STD_LOW;
        }
        break;
    case PORTF:
        Local_Val %= NUMBER_OF_PINS;
        if( (GPIO_PORTF_DATA_R &  (1U<<Local_Val)) >> Local_Val)
        {
            Read_Val = STD_HIGH;
        }
        else
        {
            Read_Val = STD_LOW;
        }
        break;
    default:
        break;
    }

    return Read_Val;
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 Local_Val = ChannelId/NUMBER_OF_PORTS;
    switch(Local_Val)
    {
    case PORTA:
        Local_Val %= NUMBER_OF_PINS;
        if(Level == STD_HIGH)
        {
            GPIO_PORTA_DATA_R |= 1U<<Local_Val;
        }
        else if(Level == STD_LOW)
        {
            GPIO_PORTA_DATA_R &= ~(1U<<Local_Val);
        }
        else
        {
            /*ERROR*/
        }
        break;
    case PORTB:
        Local_Val %= NUMBER_OF_PINS;
        if(Level == STD_HIGH)
        {
            GPIO_PORTB_DATA_R |= 1U<<Local_Val;
        }
        else if(Level == STD_LOW)
        {
            GPIO_PORTB_DATA_R &= ~(1U<<Local_Val);
        }
        else
        {
            /*ERROR*/
        }
        break;
    case PORTC:
        Local_Val %= NUMBER_OF_PINS;
        if(Level == STD_HIGH)
        {
            GPIO_PORTC_DATA_R |= 1U<<Local_Val;
        }
        else if(Level == STD_LOW)
        {
            GPIO_PORTC_DATA_R &= ~(1U<<Local_Val);
        }
        else
        {
            /*ERROR*/
        }
        break;
    case PORTD:
        Local_Val %= NUMBER_OF_PINS;
        if(Level == STD_HIGH)
        {
            GPIO_PORTD_DATA_R |= 1U<<Local_Val;
        }
        else if(Level == STD_LOW)
        {
            GPIO_PORTD_DATA_R &= ~(1U<<Local_Val);
        }
        else
        {
            /*ERROR*/
        }
        break;
    case PORTE:
        Local_Val %= NUMBER_OF_PINS;
        if(Level == STD_HIGH)
        {
            GPIO_PORTE_DATA_R |= 1U<<Local_Val;
        }
        else if(Level == STD_LOW)
        {
            GPIO_PORTE_DATA_R &= ~(1U<<Local_Val);
        }
        else
        {
            /*ERROR*/
        }
        break;
    case PORTF:
        Local_Val %= NUMBER_OF_PINS;
        if(Level == STD_HIGH)
        {
            GPIO_PORTF_DATA_R |= 1U<<Local_Val;
        }
        else if(Level == STD_LOW)
        {
            GPIO_PORTF_DATA_R &= ~(1U<<Local_Val);
        }
        else
        {
            /*ERROR*/
        }
        break;
    default:
        break;
    }
}
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    Dio_PortLevelType Val;
    switch(PortId)
    {
    case PORTA:
        Val = GPIO_PORTA_DATA_R;
        break;
    case PORTB:
        Val = GPIO_PORTB_DATA_R;
        break;
    case PORTC:
        Val = GPIO_PORTC_DATA_R;
        break;
    case PORTD:
        Val = GPIO_PORTD_DATA_R;
        break;
    case PORTE:
        Val = GPIO_PORTE_DATA_R;
        break;
    case PORTF:
        Val = GPIO_PORTF_DATA_R;
        break;
    default:
        break;
    }
    return Val;
}
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
    if(Level > NUMBER_OF_PINS)
    {
        while(1){} /*ERROR*/
    }
    else
    {
        switch (PortId)
        {
        case PORTA:
            GPIO_PORTA_DATA_R = Level;
            break;

        case PORTB:
            GPIO_PORTB_DATA_R = Level;
            break;

        case PORTC:
            GPIO_PORTC_DATA_R = Level;
            break;

        case PORTD:
            GPIO_PORTD_DATA_R = Level;
            break;

        case PORTE:
            GPIO_PORTE_DATA_R = Level;
            break;

        case PORTF:
            GPIO_PORTF_DATA_R = Level;
            break;

        default:
            break;
        }
    }
}
