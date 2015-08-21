// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
// Console object
Console console(80, 25, "SP1 Framework");
 
double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
char level[26][71];
char side[25][10];
short next=0;
char checker = 0;
short data;
void menu();
void help();
void sidemenu();
void level1();
void level2();
void level3();
void level4();
void level5();
void level6();
void level7();
void lose();
void win();
void storepoints();
void printpoints();
short data1[10];
// Game specific variables here
COORD charLocation;
COORD charLocation2;
 
// Initialize variables, allocate memory, load data from file, etc.
// This is called once before entering into your main loop
void init()
{
    // Set precision for floating point output
    elapsedTime = 0.0;
 
    charLocation.X = 24;
    charLocation.Y = 9;
    charLocation2.X = 24;
    charLocation2.Y = 9;
    // sets the width, height and the font name to use in the console
    console.setConsoleFont(0, 28, L"Consolas");
}
 
// Do your clean up of memory here
// This is called once just before the game exits
void shutdown()
{
    // Reset to white text on black background
        colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
 
    console.clearBuffer();
}
/*
        This function checks if any key had been pressed since the last time we checked
        If a key is pressed, the value for that particular key will be true
       
        Add more keys to the enum in game.h if you need to detect more keys
        To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition"
        For Alphanumeric keys, the values are their ascii values (uppercase).
*/
void getInput()
{    
    keyPressed[K_UP] = isKeyPressed(VK_UP);
    keyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
    keyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
    keyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
    keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	keyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
    keyPressed[K_RETURN] = isKeyPressed(VK_RETURN);
}
 
/*
        This is the update function
        double dt - This is the amount of time in seconds since the previous call was made
        Game logic should be done here.
        Such as collision checks, determining the position of your game characters, status updates, etc
        If there are any calls to write to the console here, then you are doing it wrong.
    If your game has multiple states, you should determine the current state, and call the relevant function here.
*/
void update(double dt)
{
    // get the delta time
	if(next!=0 && next!= 21 && next!=99){
    elapsedTime += dt;
	}
    deltaTime = dt;
        switch(next)
        {
		case 21:win();break;
		case 99:help();break;
		case 100:lose();elapsedTime=0;break;
        case 0:menu();sidemenu();
                break;
        case 1:level1();break;
        case 2:level2();break;
        case 3:level3();break;
        case 4:level4();break;
        case 5:level5();break;
        case 6:level6();break;
        case 7:level7();break;
		
        }
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
    // sound can be played here too.
}
 
/*
    This is the render loop
    At this point, you should know exactly what to draw onto the screen.
    Just draw it!
    To get an idea of the values for colours, look at console.h and the URL listed there
*/
void render()
{
    clearScreen();      // clears the current screen and draw from scratch
    renderMap();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
    renderFramerate();  // renders debug information, frame rate, elapsed time, etc
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}
 
void moveCharacter()
{
    int X = charLocation.X;
    int Y = charLocation.Y-1;
    int a = charLocation2.X;
    int b = charLocation2.Y-1;
    // Updating the location of the character based on the key press
    if (keyPressed[K_UP] && charLocation.Y > 0)
    {
        if(level[Y-1][X]!='#')
        {
            //Beep(1440, 30);
            charLocation.Y--;
        }
    }
    else if (keyPressed[K_LEFT] && charLocation.X > 0)
    {
        if(level[Y][X-1]!='#')
        {
            //Beep(1440, 30);
            charLocation.X--;
        }
    }
    else if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1)
    {
        if(level[Y+1][X]!='#')
        {
			//Beep(1440, 30);
			charLocation.Y++;
        }
    }
    else if (keyPressed[K_RIGHT] && charLocation.X < console.getConsoleSize().X - 1)
    {
        if(level[Y][X+1]!='#')
        {
            //Beep(1440, 30);
            charLocation.X++;
        }
    }
        //2nd character
    if (keyPressed[K_UP] && charLocation2.Y > 0)
	{
		if(level[b-1][a]!='#')
		{
            //Beep(1440, 30);
            charLocation2.Y--;
        }
	}
	else if (keyPressed[K_LEFT] && charLocation2.X < console.getConsoleSize().X - 1)
	{
        if(level[b][a+1]!='#')
        {
            //Beep(1440, 30);
            charLocation2.X++;
        }
	}
	else if (keyPressed[K_DOWN] && charLocation2.Y < console.getConsoleSize().Y - 1)
	{
        if(level[b+1][a]!='#')
        {
			//Beep(1440, 30);
            charLocation2.Y++;
        }
	}
	else if (keyPressed[K_RIGHT] && charLocation2.X > 0)
	{
        if(level[b][a-1]!='#')
		{
            //Beep(1440, 30);
            charLocation2.X--;
        }
	}
    if (level[b][a]=='@' && level[Y][X]=='@')
    {
        next++;
        switch(next)
        {
			case 2: charLocation.X = 2; charLocation.Y = 23; charLocation2.X = 68; charLocation2.Y = 23;break;
			case 3: charLocation.X = 31; charLocation.Y = 4; charLocation2.X = 40; charLocation2.Y = 3;break;
			case 4: charLocation.X = 4; charLocation.Y = 5; charLocation2.X = 66; charLocation2.Y = 21;break;
			case 5: charLocation.X = 7; charLocation.Y = 3; charLocation2.X = 67; charLocation2.Y = 22;break;
			case 6: charLocation.X = 17; charLocation.Y = 12; charLocation2.X = 53	; charLocation2.Y = 13;break;
			case 7: charLocation.X = 31; charLocation.Y = 4; charLocation2.X = 40; charLocation2.Y = 3;break;
			case 21:charLocation.X = 2;charLocation.Y = 2;charLocation2.X = 68;charLocation2.Y = 2;break;
		}               
    }
    else if ((keyPressed[K_RETURN]) && (next == 0) && (charLocation2.X == 24) && (charLocation2.Y == 9))
    {
        Beep(1440, 30);
        next++;
        charLocation.X = 2;charLocation.Y = 2;charLocation2.X = 68;charLocation2.Y = 2;
    }
	else if ((keyPressed[K_RETURN]) && (next == 0) && (charLocation2.X == 24) && (charLocation2.Y == 10))
    {
		Beep(1440,30);
        next=99;		
        charLocation.X = 2;charLocation.Y = 23;charLocation2.X = 68;charLocation2.Y = 23;		
    }
	else if ((keyPressed[K_SPACE]) && ((next == 100) || (next==21)))
	{
		Beep(1440,30);
		next = 0;
		charLocation.X = 24;charLocation.Y = 9;charLocation2.X = 24;charLocation2.Y = 9;
	}
	else if ((keyPressed[K_SPACE]) && (next == 99))		
	{
		Beep(1440,30);
		next = 0;		
	    charLocation.X = 24;charLocation.Y = 9;charLocation2.X = 24;charLocation2.Y = 9;		
	}
}
 
void processUserInput()
{
    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
        {
        g_quitGame = true;
        }
}
 
void clearScreen()
{
    // Clears the buffer with this colour attribute
    console.clearBuffer(0x0F);
}
 
void renderMap()
{
    // Set up sample colours, and output shadings
    const WORD colors[] = {
        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
		};
        for (unsigned int i=0;i<24;++i)
        {
        for (unsigned int c=0;c<71;++c)
        {
                if(level[i][c] == '#')
                {
                        unsigned char a = 219;
						if(next>0 && next<99 && next!=21)
						{
                        console.writeToBuffer(c,i+1,a,0x23);
						}
						else
						{
						 console.writeToBuffer(c,i+1,a,0x00);
						}
                }
                else
                {
                               
                        console.writeToBuffer(c,i+1,level[i][c]);
                }
        }
        }
        if(next >0 && next != 100 && next != 21 && next!=99)
        {
                for (unsigned int i=0;i<23;++i)
                {
                        for(unsigned int c=0;c<10;++c)
                        {
                                if(side[i][c] == '#')
								{
									unsigned char a = 219;
                                    console.writeToBuffer(c+70,i+1,a,0x00);//side menu
                                }
                                else
                                {
                                        console.writeToBuffer(c+70,i+1,side[i][c]);
                                }
                        }
                }
        }

	if(next == 21)
	{
	printpoints();
	}
}
void renderCharacter()
{
    // Draw the location of the character
    console.writeToBuffer(charLocation, (char)153, 0x0C);
        console.writeToBuffer(charLocation2, (char)153, 0x0A);
}
void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << 1.0 / deltaTime << "FPS";
    c.X = console.getConsoleSize().X - 8;
    c.Y = 0;
    console.writeToBuffer(c, ss.str());

	//displays the current level
	if (next!=0 && (next != 100) && next!= 21 && next!=99)
	{
		ss.str("");
		ss<<next;
		c.X=71;
		c.Y=12;
		console.writeToBuffer(c,ss.str());
		// displays the elapsed time

		ss.str("");
		if (1000-elapsedTime>0)
		{
		ss << 1000 - elapsedTime << "s";
		}
		else
		{
			ss << "0s";
			elapsedTime=1000;
			next = 100;
			charLocation.X = 2;charLocation.Y = 2;charLocation2.X = 68;charLocation2.Y = 2;
		}
		c.X = 71;
		c.Y = 10;
		console.writeToBuffer(c, ss.str(), 0x0B);
	}
}
void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    console.flushBufferToConsole();
}
void storepoints()
{

	int c=0;
	int a =static_cast<int>(elapsedTime);
	std::fstream fs;
	fs.open ("scoreboard.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fs <<1000- a<<std::endl;
	fs.close();
	std::ifstream inData;
	inData.open ("scoreboard.txt");
	short var2 = 1001;
	for(int a = 0 ;a<10;a++)
	{
		data = 0;
		short var1 = 0;
		while (!inData.eof())
		{
			inData >> data;
			if ((data > var1) && (data < var2))
			{
				var1 = data;
			}
		}
		inData.clear();
		inData.seekg(0, inData.beg);
		var2 = var1;
		data1[a] = var1;
	}
	inData.close();
}

void printpoints()
{
	std::ostringstream ss;
	for(int a =0 ;a<10;a++)
	{
		if(data1[a] == 0)
		{
			console.writeToBuffer(4,4+a,"----");
		}
		// convert number (data[a]) into string
		else
		{
			ss.str("");
			ss << data1[a];
			// use void Console::writeToBuffer(SHORT x, SHORT y, std::string& s, WORD attribute)
			console.writeToBuffer(4,4+a,ss.str());
		}
	}
}
void menu()
{
		checker = 0;
        char menu[24][71]={
                {" #####################################################################"}
        ,       {" #    |\\      /| ===== |====\\ |====\\  /====\\  |====\\                 #"}
        ,       {" #    | \\    / |   |   |____/ |____/ /      \\ |____/                 #"}
        ,       {" #    |  \\  /  |   |   |  \\   |  \\   \\      / |  \\                   #"}
        ,       {" #    |   \\/   | ===== |   \\  |   \\   \\____/  |   \\                  #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                     ###                                           #"}
        ,       {" #                     # # Start                                     #"}
        ,       {" #                     # # Instructions                              #"}
        ,       {" #                     ###                                           #"}
        ,       {" #                                                                   #"}
        ,       {" #    ===== |\\      /|    /\\    /===\\  |====                         #"}
        ,       {" #      |   | \\    / |   /__\\  /       |                             #"}
        ,       {" #      |   |  \\  /  |  /    \\ \\   ==/ |====                         #"}
        ,       {" #    ===== |   \\/   | /      \\ \\___/  |____                         #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #####################################################################"}};
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = menu[i][c];
                }
        }
}
void sidemenu()
{
        char sixonenine [23][10]={
         {"#########"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
		,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#Time:  #"}
        ,{"#       #"}
        ,{"#Level: #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#########"}};
 
        for(int i=0;i<23;++i)
        {
                for(int c=0;c<10;++c)
                {
                        side[i][c] = sixonenine[i][c];
                }
        }
}
void level1()
{
        char level1[24][71]={
                {" #####################################################################"}
        ,       {" #                        #        @        #                        #"}
        ,       {" #                        #                 #                        #"}
        ,       {" #                        #                 #                        #"}
        ,       {" #                        #                 #                        #"}
        ,       {" #                        #                 #                        #"}
        ,       {" #                        #                 #                        #"}
        ,       {" #                        #                 #                        #"}
        ,       {" #                        #                 #                        #"}
        ,       {" #                        #                 #                        #"}
        ,       {" #           ##############                 ##############           #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #####################################################################"}};
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level1[i][c];
                }
        }
}
void level2()
{
        char level2[24][71]={
                {" #####################################################################"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                           #           #                           #"}
        ,       {" #                           #           #                           #"}
        ,       {" #                           #           #                           #"}
        ,       {" #          ##################           ##################          #"}
        ,       {" #                           #           #                           #"}
        ,       {" #                           #           #                           #"}
        ,       {" #                           #           #                           #"}
        ,       {" #                           #           #                           #"}
        ,       {" ####################        #           #        ####################"}
        ,       {" #                           #           #                           #"}
        ,       {" #                           #           #                           #"}
        ,       {" #                           #           #                           #"}
        ,       {" #                           #     @     #                           #"}
        ,       {" #####################################################################"}};
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level2[i][c];
                }
        }
}
void level3()
{
 
        char level3[24][71]={
                {" #####################################################################"}
        ,       {" #                               #####                               #"}
        ,       {" #                               #   #                               #"}
        ,       {" #                               # @ #                               #"}
        ,       {" #   #############################   #############################   #"}
        ,       {" #   #############################   #############################   #"}
        ,       {" #   ##                     ####        ###                     ##   #"}
        ,       {" #   ##                     #### ###### ###                     ##   #"}
        ,       {" #   ##                     ###  ###### ###                     ##   #"}
        ,       {" #   ##  #################  ### ######  ###  #################  ##   #"}
        ,       {" #   ##  #################  ### ######  ###  #################  ##   #"}
        ,       {" #   ##  ##                 ###        ####                 ##  ##   #"}
        ,       {" #   ##  ##                 ###        ###################  ##  ##   #"}
        ,       {" #   ##  ##  ###################### ######################  ##  ##   #"}
        ,       {" #   ##  ##                 ####### ########                ##  ##   #"}
        ,       {" #   ##  #############    # ####### ########     #############  ##   #"}
        ,       {" #   ##             ##    #   ###      ###       #              ##   #"}
        ,       {" #   ##             ##    #   ###  #   ###       #              ##   #"}
        ,       {" #   ##             ##    #   ###  #   ###       #              ##   #"}
        ,       {" #   #############  ##    #   ###  #   ###       #   #############   #"}
        ,       {" #   #############  ##    #   ###      ###       #   #############   #"}
        ,       {" #                  ##    #   #####  #####       #                   #"}
        ,       {" #                  ##    #                      #                   #"}
        ,       {" #####################################################################"}};
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level3[i][c];
                }
        }
}
void level4()
{
        char level4[24][71]={
                {" #####################################################################"}
        ,       {" #####################################################################"}
        ,       {" ##  #######   #  #  #  #                   #  #  #  #  #  # ####   ##"}
        ,       {" ##   #####    #  #  #  # ################# #  #  #  #  # ##  ##  ####"}
        ,       {" ###   ###  ## #  #  #  # #               # #  #  #  #  # ###    #####"}
        ,       {" ####   #  ### #  #  #  # # # ########### # #     #  #  #   ## #######"}
        ,       {" ## #     #### #  #  #  # # #           # # #  #  #  #  #    ##     ##"}
        ,       {" ## #    ##### #  #  #  # # # ######### # # #  #  #  #  # #   # ##  ##"}
        ,       {" ## ##         #  #  #    # # #       # # # #  #  #  #    ##    #   ##"}
        ,       {" ## ###     ####  #  #  # # # # # ### # # # #  #  #  #  #####      ###"}
        ,       {" ## ##    #    #  #  #  # # # # #   # # # # #  #  #  #  # ###     ####"}
        ,       {" ## #     #### #     #  # # # # # @ # # # # #  #  #     # ####   #####"}
        ,       {" ##     # #### #  #  #  # # # # #   # # # # #  #  #  #  # ######    ##"}
        ,       {" ## #   #  ### #  #  #  # # # # ##### # # # #  #  #  #  # # #    #  ##"}
        ,       {" #### ###      #  #  #  # # # #       # # # #  #  #  #  # # #  # ## ##"}
        ,       {" ####  ###  ##    #  #  # # # #       # # #    #  #  #  # # #### #####"}
        ,       {" ####       ## #  #  #  # # # ####### # # # #  #  #  #  #     #     ##"}
        ,       {" ## ##  #   #  #  #  #  # # #           # # #  #  #  #  # ### ####  ##"}
        ,       {" ##    ##      #  #     # # ############# # #  #  #  #  #   ######  ##"}
        ,       {" ## #####   ## #  #  #  # #                 #  #  #  #  ### #       ##"}
        ,       {" #########  ## #  #  #  # ################# #  #  #  #  #   # # ##  ##"}
        ,       {" ##         #  #  #  #  #                   #  #     #  # #   #     ##"}
        ,       {" #####################################################################"}
        ,       {" #####################################################################"}};
       
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level4[i][c];
                }
        }
}//not yet
void level5()
{
        char level5[24][71]={
                {" #####################################################################"}
        ,       {" #####################################################################"}
        ,       {" ##     #    # ##   #            #     #       # #   #          ######"}
        ,       {" ## ##  # ##   #  # #   ######## #     # ##### # # #   #   #####    ##"}
        ,       {" ##  ####  ### # #####  # ###    #    ## ##    #   ######  #   # ## ##"}
        ,       {" ##     #    #      ###    # ######  ##   # #    # #   ###       #  ##"}
        ,       {" ##  #          # #  ## # ##      ####      # # ## ## #####      ## ##"}
        ,       {" ##  ##       #   ## #  #  ####     #     #######   # #             ##"}
        ,       {" ##  #####   ###  #    ###     ##   #     #           #   #     # ####"}
        ,       {" ### #   #   # #  # ##   # ##   ##  @     # ## ### ####   #     #  ###"}
        ,       {" ### #   ##### #  #### ### ##    #   #         #    ##    #     #   ##"}
        ,       {" ##    #  ## # #       #    #       #     # # #  ## ###   #    #######"}
        ,       {" ###   ##  #   #    #  # ####       #   ##### # ### ##    #    #    ##"}
        ,       {" ### # #   #   #   ## #### #  #   ##### # #   #           # #####   ##"}
        ,       {" ### ###           #  # #    ##       ###   ######    #   #     #   ##"}
        ,       {" ### ######      # #  #   ######  #  ##     # #       #   #         ##"}
        ,       {" ##     #        ###  #      #### #  ##  #  #   ### ###   ##### #   ##"}
        ,       {" ##        #            ####         #  ## ## # # ### ### #  #  #   ##"}
        ,       {" ## ###### #    ## # ##  # ### #######  ##    # #   # # # #  ##     ##"}
        ,       {" ## #    # ####### #  #  # # # #     #####    ###       # ##    # ####"}
        ,       {" ## ###  #  #   ##### #  # # ### ###        #   #### ## # ##  # #   ##"}
        ,       {" ##   #             #                 # ### #        #       ## #   ##"}
        ,       {" #####################################################################"}
        ,       {" #####################################################################"}};
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level5[i][c];
                }
        }
}//not yet
void level6()
{
        char level6[24][71]={

				{" #####################################################################"}
        ,       {" #      #################### #     #       #####################     #"}
        ,       {" #      #                 ## # #   # #   # #                   #     #"}
        ,       {" #      # ############### ##   #   # #   # # ################# #     #"}
        ,       {" #      # #             # ## #### ##### ## # #               # #     #"}
        ,       {" #      # # ########### # ## #     #     # # # ############# # #     #"}
        ,       {" #      # # #         # # ## ## ######## # # # #           #   #     #"}
        ,       {" #      # # # # ##### # # ## #     #     # # # # ######### #   #     #"}
        ,       {" #      # # # #     # # # ## # ####### ### # #   #       # #   #     #"}
        ,       {" #      # # # #     # # # ## #     #     # # #   # ##### # #   #     #"}
        ,       {" #      # # # # # # # # # ## #### ###### # # #   # #   # # #   #     #"}
        ,       {" #      # # # # # # # # # ## #     # ##  # # #   # #   # # #   #     #"}
        ,       {" #        # # # ### # # # ## ## # ##     # # #   # #   # # #   #     #"}
        ,       {" #      # # # #     #   # ## #     # ##### # #   #       # #   #     #"}
        ,       {" #      # # # #     # # # ## ####  #     # # #   #       # #   #     #"}
        ,       {" #      # # # ####### # # ## #     ##### # # #   ####### # #   #     #"}
        ,       {" #      # # #         # # ## #     #   # # # #             #   #     #"}
        ,       {" #      # # ########### # ## ## ######   # # ###############   #     #"}
        ,       {" #      #               # ## ## #  @     # #                   #     #"}
        ,       {" #      # ############### ## ## #  ###   # # ################# #     #"}
        ,       {" #      #                 ## ## ## ###   # #                   #     #"}
        ,       {" #      #################### #     ####  # ########### #########     #"}
        ,       {" #                           #     #######             #             #"}
        ,       {" #####################################################################"}};
        
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level6[i][c];
                }
        }
}//not yet
void level7()
{
        char level7[24][71]={
       
        };
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level7[i][c];
                }
        }
}//not yet
void lose()
{
        char lose[24][71]={
			    {" #####################################################################"}
        ,       {" # ################################################################# #"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
		,       {" ##                                                                 ##"}
		,       {" ##                                                                 ##"}
		,       {" ##            \\   //=====\\  |    |                                 ##"}
		,       {" ##             \\ //       \\ |    |                                 ##"}
		,       {" ##              | \\       / |    |                                 ##"}
        ,       {" ##              |  \\_____/  \\____/                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                               |     /=====\\   /====== |====     ##"}
        ,       {" ##                               |    /       \\ /_______ |____     ##"}
		,       {" ##                               |    \\       /        / |         ##"}
        ,       {" ##                               |____ \\_____/   _____/  |____     ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##             press space to continue....                         ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" #####################################################################"}
        ,       {" #####################################################################"}


       
        };
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = lose[i][c];
                }
        }
}
void win()
{
		if(checker == 0)
		{
			storepoints();
			checker++;
		}
        char win[24][71]={
			    {" #####################################################################"}
        ,       {" # ################################################################# #"}
        ,       {" ##Top 10 scores:                                                   ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
		,       {" ##                                                                 ##"}
		,       {" ##                                                                 ##"}
		,       {" ##            \\   //=====\\  |    |                                 ##"}
		,       {" ##             \\ //       \\ |    |                                 ##"}
		,       {" ##              | \\       / |    |                                 ##"}
        ,       {" ##              |  \\_____/  \\____/                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                        \\          / =  |\\   |                   ##"}
        ,       {" ##                         \\        /  |  | \\  |                   ##"}
		,       {" ##                          \\  /\\  /   |  |  \\ |                   ##"}
        ,       {" ##                           \\/  \\/    |  |   \\|                   ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##             press space to continue....                         ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" #####################################################################"}
        ,       {" #####################################################################"}


       
        };
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = win[i][c];
                }
        }

}
void help() 		
{		
	char help[24][71]={		
		{" #####################################################################"}		
	,	{" #                                                                   #"}		
	,	{" #                               Story                               #"}		
	,	{" #                                                                   #"}		
	,	{" #           Your shadow seems to be trolling you, and               #"}		
	,	{" #           doesn't seem to follow you as it normally               #"}		
	,	{" #           should. You hear there is a way to revert               #"}		
	,	{" #           back to normal, but it involves going                   #"}		
	,	{" #           through a ordeal of fifteen magical doors               #"}		
	,	{" #           that only appear for a thousand seconds.                #"}		
	,	{" #           Should you fail, you will never return to               #"}		
	,	{" #           normal every again. Good Luck!                          #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                            How to play                            #"}		
	,	{" #                                                                   #"}		
	,	{" #           Use the arrow keys to move and reach the                #"}		
	,	{" #           goal, marked by @ to advance to the next                #"}		
	,	{" #           stage. Your shadow has it's left and                    #"}		
	,	{" #           right control's reversed!                               #"}		
	,	{" ##                                                                 ##"}		
	,	{" # #             PRESS SPACE TO RETURN TO THE MENU                 # #"}		
	,	{" #####################################################################"}};		
		
        for(int i=0;i<24;++i)		
        {		
                for(int c=0;c<71;++c)		
                {		
                        level[i][c] = help[i][c];		
                }		
        }		
		
}
