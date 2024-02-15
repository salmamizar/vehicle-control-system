/*
 * Mini_project_1.c
 *
 *  Created on: Aug 17, 2023
 *  Author: Salma Mizar
 */
#define ON 1
#define OFF 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int AC =0;
int ETC =0;
//creating a global structure of all of vehicle's options //
typedef struct{
	char light_color;
	float room_temp;
	float engine_temp;
	int engine_state;
	int speed;
	int ac_state;
	int engine_temp_controller_state;
}vehicles;



//function to display the main options//
void main_menu(char *choice){
         printf("Choose what do you want to do :\n");
       	 printf("=====================\n");
	     printf("a. Turn on the vehicle engine\n");
	     printf("b. Turn off the vehicle engine\n");
	     printf("c. Quit the system\n");
	     fflush(stdout);
	     //to make sure user is entering only one of the 3 options (a,b and c) make a do while loop//
	    do
	    {
	    	scanf("%c",&*choice);
	    }
	    while (*choice !='a' && *choice !='c' &&*choice !='b' );
}

//function to display Sensors set menu//
void set_menu (char *choice_when_ON )
{
         printf("Choose what do you want :\n");
      	 printf("===========sensors set menu==========\n");
	     printf("a. Turn off the engine\n");
	     printf("b. Set the traffic light color\n");
	     printf("c. Set the room temperature (Temperature Sensor)\n");
	     printf("d. Set the engine temperature (Engine Temperature Sensor)");
	     fflush(stdout);
	     //to make sure user is entering only one of the 3 options (a,b and c) make a do while loop//
	    do
	    {
	    	scanf("%c",&*choice_when_ON );
	    }
	    while (*choice_when_ON !='a' && *choice_when_ON !='b' &&*choice_when_ON !='c' &&*choice_when_ON !='d' );
}
//function in case the engine is now ON//
void when_engine_on (char *choice , vehicles *v)
{
	char input;
	//setting the engine on //
	v->engine_state = ON ;
	set_menu(&input);
	while (1)
	{
		switch (input)
		{
		case ('a'):
		// turning off the engine will make us go back to the first menu s//

		        main_menu(v);
		return ;
		case('b'):
				traffic_light(v);
		        current_state(v);
		        set_menu(&input);
		        break;
		case('c'):
				set_room_temp(v);
		        current_state(v);
				set_menu(&input);
				break;
		case('d'):
				set_engine_temp(v);
		        current_state(v);
				set_menu(&input);
		        break;
		}
	}


}

//function to set the traffic lights and speed according to colors  //
void traffic_light (vehicles *v)
{
        printf("enter the traffic light:\n");
        printf("'G' for green\n");
        printf("'O' for orange\n");
        printf("'R' for red\n");
        fflush(stdout);
        //to make sure user is entering only one of the 3 options (G,O and R) make a do while loop//

        do
        {
        scanf("%c",& v->light_color);
        }
        while( v ->light_color != 'G' && v ->light_color != 'O' && v ->light_color!='R');
        //now according to the input color from the user we need to set the vehicle's speed//

        switch(v->light_color)
        	{
        case('G'):
        		v->speed=100;
        break;
        case('O'):
		        v->speed=30;
	    break;
        case('R'):
        		v->speed=0;
        break;
        	}
}
//function to display Sensors set room temperature //
void set_room_temp (vehicles *v)
{
	 //to make sure user is entering only positive number or above 100 make a do while loop//
	   do
		{
			printf("Enter room temperature:\n");
			fflush(stdout);
			scanf("%f", &v->room_temp);
		}while(v->room_temp < 0 || v->room_temp > 100);
	       AC=1;
	       if (v->room_temp <10 || v->room_temp>30)

	       {
	    	   v->ac_state = ON ;
	           v->room_temp =20;
	       }
	       else
	       {
	    	   v->ac_state = OFF ;
	       }
}
void set_engine_temp(vehicles *v)
{

		 printf("Enter engine temperature:\n");
		 fflush(stdout);
		 scanf("%f", &v->engine_temp);

		 ETC=1;
		 if (v->engine_temp <100 || v->engine_temp >150)
		 {
			 v->engine_temp_controller_state = ON;
			 v->engine_temp = 125;
		 }
		 else
			 v->engine_temp_controller_state = OFF ;
}
void current_state(vehicles *v)
{
	if (v->speed==30)
		{
			v->ac_state = ON;
		    v->engine_temp_controller_state = ON;
			v->engine_temp = (float)v->engine_temp * 5.0/4 + 1;
			v->room_temp = (float)v->room_temp * 5.0/4 + 1;
		}
	//engine state//
	if (v->engine_state == 1)
	{
		printf("Engine state: ON\n");
	}
	else
	{
		printf("Engine state: OFF\n");
	}
	//AC state//
	if (v->ac_state ==1)
		{
			printf("AC state: ON\n");
		}
		else
		{
			printf("AC state: OFF\n");
		}
	//vehicle speed//
	printf ("Vehicle Speed: %d km/hr\n", v->speed);
	//Room Temperature//
	printf("Room Temperature: %.1f deg\n",v->room_temp);
	//Engine Temperature Controller State//
	if(v->engine_temp_controller_state ==1)
	{
		printf("Engine Temperature Controller State: ON\n");
	}
	else
	{
		printf("Engine Temperature Controller State: OFF\n");
	// Engine Temperature//
	}
	printf("Engine Temperature: %.1f deg\n" , v->engine_temp);
}
int main (void)
{
	vehicles v ;
	//give the variables initial logical values//
	v.speed = 75;
    v.engine_temp = 95;
	v.room_temp = 35;
	char input;
	main_menu(&input);
	// checking what to do as 'a' will Turn on the vehicle engine , 'b' will Turn off the vehicle engine and 'c' will Quit the system//
	while (1)
	{
		switch (input)
		{
		case ('a'):
		    printf("Engine is ON\n");
			when_engine_on(&input, &v);
			break;
		case 'b':
			printf("Engine is OFF\n");
			main_menu(&input);
			break;
		case 'c':

			printf("Quitting the system\n");
			return 0;

		}
	}

}









