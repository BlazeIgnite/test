// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>

double	g_dElapsedTime;
double	g_dDeltaTime;
bool	g_abKeyPressed[K_COUNT];
COORD	g_cCharLocation;
COORD	g_cCharLocation2;
COORD	g_cConsoleSize;

char level1[26][71]={
	{" #####################################################################"}
,	{" #                        #                 #                        #"}
,	{" #                        #                 #                        #"}
,	{" #                        #                 #                        #"}
,	{" #                        #                 #                        #"}
,	{" #                        #                 #                        #"}
,	{" #                        #                 #                        #"}
,	{" #                        #                 #                        #"}
,	{" #                        #                 #                        #"}
,	{" #                        #                 #                        #"}
,	{" #           ##############                 ##############           #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #                                                                   #"}
,	{" #####################################################################"}};
 

//--------------------------------------------------------------
// Purpose	: Initialisation function
// Input	: Void
// Output	: void
//--------------------------------------------------------------
void init( void )
{
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(2);

	// set the name of your console window
    SetConsoleTitle(L"SP1 Framework");

    // Sets the console size.
    setConsoleSize(70, 28);

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    g_cConsoleSize.X = csbi.srWindow.Right + 1;
    g_cConsoleSize.Y = csbi.srWindow.Bottom + 1;
	std::cout<<g_cConsoleSize.X;
	std::cout<<g_cConsoleSize.Y;

    // set the character to be in the TOP LEFT OF BOUNDING BOX.
    g_cCharLocation.X = 2;
    g_cCharLocation.Y = 2;
	g_cCharLocation2.X = 68;
	g_cCharLocation2.Y = 2;

    g_dElapsedTime = 0.0;
}

//--------------------------------------------------------------
// Purpose	: Reset before exiting the program
// Input	: Void
// Output	: void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

//--------------------------------------------------------------
// Purpose	: Getting all the key press states
// Input	: Void
// Output	: void
//--------------------------------------------------------------
void getInput( void )
{    
    g_abKeyPressed[K_UP] = isKeyPressed(VK_UP);
    g_abKeyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
    g_abKeyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
    g_abKeyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
    g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
}

//--------------------------------------------------------------
// Purpose	: Update function
// Input	: dt = deltatime
// Output	: void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;
	int X = g_cCharLocation.X;
	int Y = g_cCharLocation.Y-1;
	int a = g_cCharLocation2.X;
	int b = g_cCharLocation2.Y-1;
    // Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
    if (g_abKeyPressed[K_UP] && g_cCharLocation.Y > 0)
    {
		if(level1[Y-1][X]!='#')
		{
			Beep(1440, 30);
			g_cCharLocation.Y--; 
		}
    }
    else if (g_abKeyPressed[K_LEFT] && g_cCharLocation.X > 0)
    {
		if(level1[Y][X-1]!='#')
		{
			Beep(1440, 30);
			g_cCharLocation.X--; 
		}
    }
    else if (g_abKeyPressed[K_DOWN] && g_cCharLocation.Y < g_cConsoleSize.Y - 1)
    {
		if(level1[Y+1][X]!='#')
		{
			Beep(1440, 30);
			g_cCharLocation.Y++; 
		}
    }
    else if (g_abKeyPressed[K_RIGHT] && g_cCharLocation.X < g_cConsoleSize.X - 1)
    {
		if(level1[Y][X+1]!='#')
		{
        Beep(1440, 30);
        g_cCharLocation.X++; 
		}
    }

	//2nd Character, LR reversed.
	if (g_abKeyPressed[K_UP] && g_cCharLocation2.Y > 0)
    {
		if(level1[b-1][a]!='#')
		{
			Beep(1440, 30);
			g_cCharLocation2.Y--;
		}
    }
    else if (g_abKeyPressed[K_LEFT] && g_cCharLocation2.X < g_cConsoleSize.X - 1)
    {
		if(level1[b][a+1]!='#')
		{
			Beep(1440, 30);
			g_cCharLocation2.X++;
		}
    }
    else if (g_abKeyPressed[K_DOWN] && g_cCharLocation2.Y < g_cConsoleSize.Y - 1)
    {
		if(level1[b+1][a]!='#')
		{
			Beep(1440, 30);
			g_cCharLocation2.Y++;
		}
    }
    else if (g_abKeyPressed[K_RIGHT] && g_cCharLocation2.X > 0)
    {
		if(level1[b][a-1]!='#')
		{
			Beep(1440, 30);
			g_cCharLocation2.X--;
		}
    }

    // quits the game if player hits the escape key
    if (g_abKeyPressed[K_ESCAPE])
        g_bQuitGame = true;    
}

//--------------------------------------------------------------
// Purpose	: Render function is to update the console screen
// Input	: void
// Output	: void
//--------------------------------------------------------------
void render( void )//printing walls and renders
{
    // clear previous screen
    colour(0x0F);
	system("CLS");
    //render the game

    //render test screen code (not efficient at all)
    const WORD colors[] =   {
	                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };//dark blue, army green, turquoise, blood red, purple, poop, epilepsy green, cyan, cherry red, pink, yellow, white
	gotoXY(0,1);
	for(int i=0;i<26;++i)
	{
		for(int c=0;c<71;++c)
		{
			std::cout<<level1[i][c];
		}
		std::cout<<"  \n";
	}
    // render time taken to calculate this frame
    gotoXY(62, 0);
    colour(0xF6);
    std::cout << 1.0 / g_dDeltaTime << "fps" << std::endl;
  
    gotoXY(1, 0);
    colour(0xF6);
    std::cout << g_dElapsedTime << "sec" << std::endl;

    // render character
    gotoXY(g_cCharLocation);
    colour(0x0C);
    std::cout << (char)153;

	// render character
    gotoXY(g_cCharLocation2);
    colour(0x0A);
    std::cout << (char)153;
}
