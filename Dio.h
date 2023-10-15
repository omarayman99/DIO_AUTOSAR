#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include "MCAL/Std_Types/Std_Types.h"


/*Typedefs*/
typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;
typedef struct
{
    uint8 mask;
    uint8 offset;
    Dio_PortType port;
}Dio_ChannelGroupType;

#define NUMBER_OF_PORTS 8U
#define NUMBER_OF_PINS 8U
#define PORTA   0U
#define PORTB   1U
#define PORTC   2U
#define PORTD   3U
#define PORTE   4U
#define PORTF   5U

/*Functions Prototypes*/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);





#endif /* MCAL_DIO_DIO_H_ */
