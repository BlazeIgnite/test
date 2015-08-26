#include "map.h"

unsigned char level[26][71];
char side[25][10];
short next=0;//current level of map change to access other levels
char checker = 0;
void menu()
{
		checker = 0;
        char menu[24][71]={
                {" #####################################################################"}
        ,       {" #                                                                   #"}
		,       {" #      *       * ***** ****  ****   ***  ****                       #"}
		,       {" #      **     **   *   *   * *   * *   * *   *                      #"}
		,       {" #      * *   * *   *   ****  ****  *   * ****                       #"}
		,       {" #      *  * *  *   *   *  *  *  *  *   * *  *                       #"}
		,       {" #      *   *   * ***** *   * *   *  ***  *   *                      #"}
        ,       {" #                                                                   #"}
		,       {" #                     ###                                           #"}
        ,       {" #                     # # Start                                     #"}
        ,       {" #                     # # Instructions                              #"}
		,       {" #                     # # Quit                                      #"}
		,       {" #                     ###                                           #"}
		,       {" #      *****  *       *   ***    ****  *****                        #"}
		,       {" #        *    **     **  *   *  *      *                            #"}
		,       {" #        *    * *   * *  *****  *  **  ***                          #"}
		,       {" #        *    *  * *  *  *   *  *   *  *                            #"}
		,       {" #      *****  *   *   *  *   *   ****  *****                        #"}
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
        char sidemenu [23][10]={
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
                        side[i][c] = sidemenu[i][c];
                }
        }
}
void level1()
{
		char level1[24][71]={
				{" #####################################################################"}
		,		{" #                        #        @        #                        #"}
		,		{" #                        #                 #                        #"}
		,		{" #                        #                 #                        #"}
		,		{" #                        #                 #                        #"}
		,		{" #                        #$$$$$$$$$$$$$$$$$#                        #"}
		,		{" #                        #                 #                        #"}
		,		{" #                        #                 #                        #"}
		,		{" #                        #                 #                        #"}
		,		{" #                        #                 #                        #"}
		,		{" #           ##############                 ##############           #"}
		,		{" #                                                                   #"}
		,		{" #                                                                   #"}
		,		{" #                                  %                                #"}
		,		{" #                                                                   #"}
		,		{" #                                                                   #"}
		,		{" #                                                                   #"}
		,		{" #                                                                   #"}
		,		{" #                                                                   #"}
		,		{" #                                                                   #"}
		,		{" #                                                                   #"}
		,		{" #                                                                   #"}
		,		{" #                                                                   #"}
		,		{" #####################################################################"}};
 
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
,	{" #                                       $$                          #"}
,	{" #                                 %     $$                          #"}
,	{" #                                       $$                          #"}
,	{" #    ########################$$$$$$$$$$$########################    #"}
,	{" #    ########################           ########################    #"}
,	{" #    ########################           ########################    #"}
,	{" #                           #           #                           #"}
,	{" ########################    #           #    ########################"}
,	{" ########################    #           #    ########################"}
,	{" ########################    #           #    ########################"}
,	{" #                           #     >     #                           #"}
,	{" ##      #####################           #####################      ##"}
,	{" #####      ##################           ##################      #####"}
,	{" ########      ###############     <     ###############      ########"}
,	{" ###########      ############           ############      ###########"}
,	{" ##############      #########           #########      ##############"}
,	{" #################      ######     >     ######      #################"}
,	{" ####################      ###           ###      ####################"}
,	{" #################           #           #           #################"}
,	{" ##############             ##           ##             ##############"}
,	{" ###########             #####           #####             ###########"}
,	{" #                    ########     @     ########                    #"}
,	{" #####################################################################"}};
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
,	{" #                               #####                               #"}
,	{" #                               #   #                               #"}
,	{" #                               # @ #                               #"}
,	{" #    ##########^#################   #################^##########    #"}
,	{" #    ############################   ############################    #"}
,	{" #    #                     ####        ###                     #    #"}
,	{" #    #                     #### ###### ###                     #    #"}
,	{" #    #                     ###  ###### ###                     #    #"}
,	{" #    #  #################  ### ######  ###  #################  #    #"}
,	{" #    #  #################  ### ######  ###  #################  #    #"}
,	{" #    #  ##                 ###        ####                 ##  #    #"}
,	{" #    #  ##                 ###        ###################  ##  #    #"}
,	{" #    #  ##  ###################### ######################  ##  #    #"}
,	{" #    #  ##                 ####### ########                ##  #    #"}
,	{" #    #  #############    #$####### ########     #############  #    #"}
,	{" #    #             ##    #   ###     %###       #              #    #"}
,	{" #    #             ##    #   ###  #   ###       #              #    #"}
,	{" #    #             ##    #   <##  #   ##>       #              #    #"}
,	{" #    ############  ##    #   ###  #   ###       #   ############    #"}
,	{" #    ############  ##    #   ###      ###       #   ############    #"}
,	{" #                  ##    #   #####  #####       #                   #"}
,	{" #          ^       ##    #                      #        ^          #"}
,	{" #####################################################################"}};
 
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
		char level4[24][71] = {
	{" #####################################################################"}
,	{" #  #   #   #   #   #   #   #       >         #   #   # ###   #   #  #"}
,	{" ## # #   # # # #   # ### # #  # ## ### ### # # #   #   #   # # # # ##"}
,	{" ##       #   #     < #   #                 #   #   ##  #   #   #   ##"}
,	{" ##   ### #   ###  ## ### # # # # ### ### # ### # # # >   #   ### ####"}
,	{" #  #   #   #   #   #   #   #         #   #   #   #   #   #   #   #  #"}
,	{" ## # # # # # # #   # ### # #   # # ##    # # ###   # # # #     ### ##"}
,	{" ##       #   #   #   #   #   #         #   #   #   #   #   #   #   ##"}
,	{" ## #   # # ### #  ## # # # # # # ### # # # #   # # ###   # # # # # ##"}
,	{" #  #   #   #       #   #   #         #   #   #           #   #   #  #"}
,	{" ## # ### # # # # ### # # # #  ## #$# # # # # #   #   # # #     # # ##"}
,	{" ##   #   #  ##   #   #   #       #@#   #   #   #       #       #   ##"}
,	{" ## #   #     # # #   ##  # # # # #$#   ### # # # # #   #     # # # ##"}
,	{" #  #   #>  #   #   #   ^   #   #     #   #   #   #   #   #   #   #  #"}
,	{" ## ### #   #     # # #   # # # # ### # # # #   # # # # # ###   # # ##"}
,	{" ##       #   #   #   #   #   #         #   #   #       #   #   #   ##"}
,	{" ## # ###   ###     ### #   # # ### ### # #   # # # #   # #    ## # ##"}
,	{" #  #   #   #   #   #   #   #             #   ##      #   #   #   #  #"}
,	{" ##   #   # # # #   #   #   # #####^  ### # #   # # # ###     # # ####"}
,	{" ##       #   #           #      ##         # #         #   #   #   ##"}
,	{" ## # # # # # # # # # ### # ###   # ### ###%# # #   # # # # #^### # ##"}
,	{" #####################################################################"}};

		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level4[i][c];
			}
		}
}
void level5()
{
        char level5[24][71]={
	{" #####################################################################"}
,	{" #####################################################################"}
,	{" ##  #######   #  #  #  #         %         #  #  #  #  #  # ####   ##"}
,	{" ##   #####    #  #  #  # ################# #  #  #  #  # ##  ##  ####"}
,	{" ###   ###  ## #  #  #  # #               # #  #  #  #  # ###    #####"}
,	{" ####   #  ### #  #  #  # # #$########### # #     #  #  #   ##  ######"}
,	{" ## #     #### #  #  #  # # #           # # #  #  #  #  #    ##     ##"}
,	{" ## #    ##### #  #  #  # # # ######### # # #  #  #  #  # #   # ##  ##"}
,	{" ## ##         #  #  #    # # #       # # # #  #  #  #    ##    #   ##"}
,	{" ## ###     ####  #  #  # # # # #$### # # # #  #  #  #  #####      ###"}
,	{" ## ##    #    #  #  #  # # # # #   # # # # #  #  #  #  # ###     ####"}
,	{" ## #     #### #     #  # # # # # @ # # # # #  #  #     # ####   #####"}
,	{" ##     # #### #  #  #  # # # # #   # # # # #  #  #  #  # ######    ##"}
,	{" ## #   #  ### # <#> # <# # # # ##### # # # #> # <#> #  # # #    #  ##"}
,	{" #### ###      #  #  #  # # # #       # # # #  #  #  #  # # #  # ## ##"}
,	{" ####  ###  ##    #  #  # # # #       # # #    #  #  #  # # #### #####"}
,	{" ####       ## #  #  #  # # # #######$# # # #  #  #  #  #     #     ##"}
,	{" ## ##  #   #  #  #  #  # # #           # # #  #  #  #  # ### ####  ##"}
,	{" ##    ##      #  #     # # ############# # #  #  #  #  #   ######  ##"}
,	{" ## #####   ## #  #  #  # #               $ #  #  #  #  ### #       ##"}
,	{" #########  ## #  #  #  # ################# #  #  #  #  #   # # ##  ##"}
,	{" ##         #  #  #  #  #                   #  #     #  # #   #     ##"}
,	{" #####################################################################"}
,	{" #####################################################################"}};
       
 
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
,	{" #####################################################################"}
,	{" ##     #    # ##   #            #     #       # #   #           #####"}
,	{" ## ##  # ##   #  # #   ######## #     # ##### # # #   #   #####    ##"}
,	{" ##  ####  ### # #####  # ###    #    ## ##    #   ######  #   # ## ##"}
,	{" ##     #    #      ###    # ######  ##   # #    # #   ###       #  ##"}
,	{" ##  #          # #  ## # ##      ####      #^# ## ## #####      ## ##"}
,	{" ##  ##       #   ## #  #  ####     #     #######   # #             ##"}
,	{" ##  #####   ###  #    ###     ##   #     #           #  <#     # ####"}
,	{" ### #   # ^ # #  # ##   # ##   ## $@$    # ## ### ####   #     #  ###"}
,	{" ### #   ##### #  #### ### ##    #  $#         #    ##    #     #   ##"}
,	{" ##    #  ## # #       #    #       #     # # #  ## ###   #    #######"}
,	{" ###   ##  #   #    #  # #### ^     #   ##### # ### ##    #    #    ##"}
,	{" ### # #   #   #   ## #### #  #   ##### # #   #           # #####   ##"}
,	{" ### ###           #  # #    ##       ###   ######    #   #     #   ##"}
,	{" ### ######      # #  #   ######  #  ##     # #       #   #         ##"}
,	{" ##     #        ###  #      #### #  ##  #  #   ### ###   ##### #   ##"}
,	{" ##        #            ####         #  ## ## # # ### ### #  #  #   ##"}
,	{" ## ###### #   ^## # ##  # ### #######  ##    # #   # # # #  ##     ##"}
,	{" ## #    # ####### #  #  # # # #     #####    ###       # ##    # ####"}
,	{" ## ###  #  #   ##### #  # # ### ###        #   #### ## # ##  # #   ##"}
,	{" ##   #             #                <#%###^#        #       ## #   ##"}
,	{" #####################################################################"}
,	{" #####################################################################"}};
 
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

	{" #####################################################################"}
,	{" #   %  #################### #     #       #####################     #"}
,	{" #      #                 ## # #   # #   # #                         #"}
,	{" #      # ############### ##   #   # #   # # ################# #     #"}
,	{" #      # #             # ## #### ##### ## # #               # #     #"}
,	{" #      # # ########### # ## #     #     # # # ## ########## # #     #"}
,	{" #      # # #         # # ## ## ######## # # # #           # # #     #"}
,	{" #      # # # # ##### # # ## #     #     # # # # ######### # # #     #"}
,	{" #      # # # #     # # # ## # ####### ### # # # #       # # # #     #"}
,	{" #      # # # #     # # # ## #     #     # # # # # ##### # # # #     #"}
,	{" #      # # # # # # # # # ## #### ###### # # # # # #   # # # # #     #"}
,	{" #      # # # # # # # # # ## #     # ##  # # # # # #   # # # # #     #"}
,	{" #        # # # ### # # # ## ## # ##     # # # # # #$$$# # # # #     #"}
,	{" #      # # # #     #   # ## #     # ##### # # # #       # # # #     #"}
,	{" #      # # # #     # # # ## ####  #     # # # # #       # # # #     #"}
,	{" #     <# # # ####### # # ## #     ##### # # # # ####### # # # #>    #"}
,	{" #      # # #         # # ## #     #   # # # # #           # # #     #"}
,	{" #>     # # ########### # ## ## ######   # # # ############# # #    <#"}
,	{" #      #               # ## ## #  @     # # #                 #     #"}
,	{" #     <# ############### ## ## #  #     # # ################# #>    #"}
,	{" #      #                 ## ## ## ###   # #                   #     #"}
,	{" #      #################### #     ####  # #####################     #"}
,	{" #                           #     #######                           #"}
,	{" #####################################################################"}};
        
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level7[i][c];
                }
        }
}//not yet
void level8()
{
	char level8[24][71] = {
	{" #####################################################################"}
,	{" #       % ###                               ###                     #"}
,	{" #     ### ### ###                       ### ### ###                 #"}
,	{" #     ###     ###                       ###     ###                 #"}
,	{" # ### ###     ### ###               ### ###     ### ###             #"}
,	{" # ###             ###               ###             ###             #"}
,	{" # ###             ### ###           ###             ### ###         #"}
,	{" #                     ###                               ###         #"}
,	{" ###                   ### ###     ###                   ### ###     #"}
,	{" ###                       ###     ###                       ###     #"}
,	{" ###                       ### ###$###                       ### ### #"}
,	{" #                             ### $ $                           ### #"}
,	{" # ###                         ###$@$###                         ### #"}
,	{" # ###                           $ $ ###                             #"}
,	{" # ### ###                       ###$### ###                       ###"}
,	{" #     ###                       ###     ###                       ###"}
,	{" #     ### ###                   ###     ### ###                   ###"}
,	{" #         ###                               ###                     #"}
,	{" #         ### ###             ###           ### ###             ### #"}
,	{" #             ###             ###               ###             ### #"}
,	{" #             ### ###     ### ###               ### ###     ### ### #"}
,	{" #                 ###     ###                       ###     ###     #"}
,	{" #                 ### ### ###                       ### ### ###     #"}
,	{" #####################################################################"}};
       
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level8[i][c];
                }
        }
}//not yet
void level9()
{
	char level9[24][71] = {
	{" #####################################################################"}
,	{" #####################################################################"}
,	{" #   #  # #  # #  # #    #         #         # #    #  # #  # #  #   #"}
,	{" #     <###  ###  # #  ### ####### ######### ###  ###  # #   ##  #   #"}
,	{" #      #    # #       # # #               # #    #    # #>          #"}
,	{" #   #  ##     #   ##    # # ############# #   #  # #  #    ###  #   #"}
,	{" #   #  #    #         #   # #           # # # #       # #  #    #   #"}
,	{" #   #    #  ##   ###  ### # # # ####### # # # #  ###  ###    #  #   #"}
,	{" #   #    #  # #  # #  # # # # #       # # #   #  # #  # #  # #      #"}
,	{" #      #    ###  ###  ### # # #  # #  # # # #     ##  ###  ###  #   #"}
,	{" #   #  # #    #  #        # # # ##&## # # # # #    #    #          <#"}
,	{" #   #   #   # #  # #  ### # # #  &@&  #   # ###  #    # #  # #  #   #"}
,	{" #   #    #  #         # # # # # ##&## # # # # #  # #  #    # #  #   #"}
,	{" #   #   ##  ###  ###  #   # # #  # #  # # #      ###  ##     #  #   #"}
,	{" #           # #  # #  # # # # #       # # # # #    #  # #  # #  #   #"}
,	{" #   #  ###    #  ###  # # #   ####### # # # ###  ###  ###  ###      #"}
,	{" #   #  #    # #         # # #           # # # #  #    #    #        #"}
,	{" #      # #  # #  ###  ### # ############# # # #  # #    #    #  #   #"}
,	{" #   #    #  #    # #    # #               # # #  # #  # #  # #  #   #"}
,	{" #   #  # #  # #  ###  #   ############# ### #    #    ###  ###      #"}
,	{" #                #    #%#         #         # #    #  # #  #    #   #"}
,	{" #   #  ##   ###    #^ ###^        #          ^#  ###  ###    #      #"}
,	{" #####################################################################"}
,	{" #####################################################################"}};
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level9[i][c];
			}
		}
}
void level10()
{
	char level10[24][71] = { 
	{" #####################################################################"}
,	{" #####################################################################"}
,	{" #   ########       #######        #           #     # #######     ###"}
,	{" #   #  #     ##  #  #####  ####   #    ##  ##   # #   ##    ##### ###"}
,	{" #  ##    ###  ## ##  ###  ######  #   ##  ### ### ### #  ## #      ##"}
,	{" # ##   #  ###  #  ##     ##    ## #  ##  ###  #     #   ##     ###  #"}
,	{" # ##  ###  ## ##  ###  #    ##  # ##  ## ##  ## ### ## ## ### ##### #"}
,	{" # #  #####  ###  ###  ## ##  ###  ###      #    ###    #  #    ###  #"}
,	{" # # #######     ###  ###  ##  ##  ####  #### ## ### ##   ## #   ### #"}
,	{" #    #####   # ###  ####   ##  ## #####  ##   #     #  ### ## #  ## #"}
,	{" # ##  ###   ##  ###  #####  ##  ########    # ### ### ## # #  #  ## #"}
,	{" # ##   #   ###   ###     # # ##  #############  # #          ###  # #"}
,	{" # ## #####  ## #  ##    ## #                 ##     ##### ####### # #"}
,	{" #        #   # ##  # # ##  #  ## ########### ##  #   ###  ##  ### # #"}
,	{" ### ## ### #   ###   # #  ##### ############ # #####  #  ####  ##   #"}
,	{" ### #    # # # ####  # # ##     ############ #     ##   ######  ### #"}
,	{" #   #   ## # # ###  ##  ##  ################ ## ##  ## ######   # # #"}
,	{" # ##### #  # # ##  ### ##  ##                #  ###  #  ####  #   # #"}
,	{" #     # # ## #    ###     ###  # ### # # # # ## ##  ##       ## #   #"}
,	{" #  # %# ###    # ###   ##  ##   ##@###########  ###    ##   ### ##  #"}
,	{" #  #######  # ## ##  #  ##  #  # #$# # # # # ## ##### ######### ### #"}
,	{" #           #  #    ###    ##     $                 # #             #"}
,	{" #####################################################################"}
,	{" #####################################################################"}};
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level10[i][c];
			}
		}
}
void level11()
{
	char level11[24][71] = {
	{" #####################################################################"}
,	{" #####################################################################"}
,	{" # #######              #########    ###  V  ###  ################   #"}
,	{" # ######  ########  ##  #######  ##  #  #  #   # #                  #"}
,	{" # ###    ########  #### #####  ##     ###    $  ################    #"}
,	{" # ### ##  ######  ######  ### ###  ######  <#@#  #                  #"}
,	{" # ##   ##  ####  ##   ###  #  ##  ######     $   ################   #"}
,	{" #    #  ##      ##  #  ###       ######    #   # #                  #"}
,	{" #   ###  ####  ##  ###  ###   ##  ####  ##  ###  ################   #"}
,	{" #  #####  ### ##    #         ###  ##    ##  #  ##                  #"}
,	{" # #######      ##     # ####   ###    ##  ## #   ################   #"}
,	{" # ######## ###  ##   #  ###     ###  ###   # ### #                  #"}
,	{" # ########  ###  ####V ###    #  #   ##  #   #   ################   #"}
,	{" # ########   ###      ###    ###     #  ###  # ###                  #"}
,	{" # ### #### #  #### ## ##  # ##### #    ##### #   ################   #"}
,	{" # ##   ### ##  ### ## #     ###   ## #####   ### #                  #"}
,	{" # #  #  ## ###  ##      # #  #  #  #  ###  # #   ################   #"}
,	{" # # ###  #  ###  ####  ## ##   ## ##   #  ## # ###                  #"}
,	{" #  #####     ### #### ##   ## ##  #  #   ### #   ################   #"}
,	{" #########    <##  ### #  #          ###  ##  ### #                  #"}
,	{" ##########         ##   ###  ###########     #   ################   #"}
,	{" ##################     #####     %########## #                      #"}
,	{" #####################################################################"}
,	{" #####################################################################"}};
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level11[i][c];
			}
		}
}
void level12()
{
	char level12[24][71] = {
	{" #####################################################################"}
,	{" #          ##### #  ###      # ####### ##   ##  # ######           ##"}
,	{" #   ##     ##### #  ######## # ####    #   #  #   ##     ###### #  ##"}
,	{" # #### #  #    $ #  #        # ###     # #### ### #             #  ##"}
,	{" # ##   ###   # $    #        # ### ### # ####   # ###  #        #  ##"}
,	{" #  #  ####   # # @  # ##### ##      <# #######    #   ###########   #"}
,	{" ####  ##### ## #  ### ##### ####  #### #    ##### # # ##        # ###"}
,	{" #  #  ##    ## #$#  # ##    ####  ####   ## ##    # # ##  #    ## # #"}
,	{" # ### ##  # ## #      ##### ####  #### ####    ## ### ######  ##  # #"}
,	{" #       <## ##   ########## ##       # # ## ## ## ##  #####  ##   # #"}
,	{" #       ### ###  #   ###### ## ## #  # # ## #     #  ###V## ##    # #"}
,	{" #      #### # #  #   ##        ## ## # # ## # ##    #### ## #   #   #"}
,	{" # ###  #### # # ##  ### ###  ####  # # # ## # ###  #####        ### #"}
,	{" # #### ###### #  #  ##  # #        # # # ## # ### ####    ##   #### #"}
,	{" # #### ### ## # ##  ## ## #  ####  # #   ## ##### #      ###   ###  #"}
,	{" # ###      ##    #  ## ## #####    # # # ##  #### #  ### ###  ####  #"}
,	{" # ###      ## ## #   # ## # # #  ### #   ##       ###### ###  ####  #"}
,	{" #  ## #### ##  # ### #  #   #    ###### ###       #   ## ##      #  #"}
,	{" ## ## #### ## ## ### #  ### # #  ##   #     #####     ## ## #### #  #"}
,	{" ## ##         ## #       ## # #  ## # # ## ^ ###  ###    ## #### #  #"}
,	{" ##    ######     # ##### ##   #     #%# ####     #### #     ####    #"}
,	{" #####################################################################"}};
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level12[i][c];
			}
		}
}
void level13()
{
	char level13[24][71] = {
	{" #####################################################################"}
,	{" #####################                           ######            ###"}
,	{" #%################### ######## ### ############ ###### ##############"}
,	{" # ################### ######## ### ############ ###### ##############"}
,	{" #           #########$######## ### ########     ###### ##############"}
,	{" # ######### @         ######## ### ######## ###                    ##"}
,	{" #           #########$######## ### ######## ### # #### #### ##### ###"}
,	{" # ########## ######## ######## ### ######## ### # #### #### ##### ###"}
,	{" #            ########    ##                 ### # #### #### ##### ###"}
,	{" # ########## ########    ##    ############ ### # #### #### ##### ###"}
,	{" #            ######## ##### ##              ### # #### #### ##### ###"}
,	{" # ########## ######## ##### ## ############ ###   #### #### ##### ###"}
,	{" #            ######## ##### ## ############ ### # #### #### ##### ###"}
,	{" # ########## ######## ##### ## ############ ### # #### #### ##### ###"}
,	{" #            ######## ##### ##                  # #### #### ##### ###"}
,	{" # ########## ######## ##### ## #################  ####         ## ###"}
,	{" #            ######## ##### ## ######## ######### #### ####### ## ###"}
,	{" # ########## ######## ##### ## ######## ######### #### ####### ## ###"}
,	{" #                  ##    ## ##                                 ## ###"}
,	{" ##################### ## ## ################### ############## ## ###"}
,	{" ##################### ##                        ##############    ###"}
,	{" #####################################################################"}};
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level13[i][c];
			}
		}
}
void level14()
{
	char level14[24][71] = {
	{" #####################################################################"}
,	{" #        #########        ###    # #    #     #      #        #     #"}
,	{" #    ### #### #### ####    #  ##   #  ####  ######   #    #   #  #  #"}
,	{" #  # ### ###     # ####  #   ##### #  #%### #####    ## ### # # ### #"}
,	{" ######## ##   #  #      ## ####  # #    ##  ####        ### #   ##  #"}
,	{" ######   #    ##  # ## ### #     # # #####   ##  #   ########  ###  #"}
,	{" #  ##      ## ### # ##   #    ## # #  #  ### #  ###    ####         #"}
,	{" #   # #   ### ### # ###    ### # #             #####          #   # #"}
,	{" # #   ## ###      # #####$###  #    #####################$###$### # #"}
,	{" # ## ######   ##  #  ## #     ##$#$$##  ####    ###       ##  #   # #"}
,	{" # ## # ####  ###     ## #  #  #  #  ###  # #     ##  ##  ##  ## # # #"}
,	{" # #     ##  ###   ##     ######  #  #### # #  #     ##  ##      # # #"}
,	{" # ##  #  ## ##   ######        ###  ####     ##    ##  ##   ####### #"}
,	{" # #  ### ## ##  ###     # # ######  ####### ####  ##  ##   ####     #"}
,	{" #   #### ## #  ###      ###    ##  ##     # # ####   ###  ##     ## #"}
,	{" #    ### #  # #### ###### # #  #  @ #   # #   ####  ## #     ##  ## #"}
,	{" # ## ###       ### # #      #  ##  ##   #   #      ##    ## #### #  #"}
,	{" # ## ##  ##  #  ## #      #######  ########### #  ##   #  #    # #  #"}
,	{" # ## ## ##  ###  ###  # # #  # ######          # ##   ###   ##   ## #"}
,	{" #########  #####  ## #### #  # #  #   ############   #####  ## #### #"}
,	{" ##        #######    #            #                   ###        ## #"}
,	{" #####################################################################"}};
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level14[i][c];
			}
		}
}
void level15()
{
	char level15[24][71] = {
		  { " #####################################################################" }
		, { " #                                 @                                 #" }
		, { " #    SSSSSSSSS     IIIIIIIIIIIIII   DDDDDDDDDD     MMMMM      MMMMM #" }
		, { " #   SSSSSSSSSSS    IIIIIIIIIIIIII   DDDDDDDDDDD    MMMMM      MMMMM #" }
		, { " #  SSSSSSSSSSSSS   IIIIIIIIIIIIII   DDDDDDDDDDDD   MMMMMM    MMMMMM #" }
		, { " # SSSSSSSSSSSSSSS  IIIIIIIIIIIIII   DDDDDDDDDDDDD  MMMMMM    MMMMMM #" }
		, { " # SSSS       SSS   IIIIIIIIIIIIII   DDDDDDDDDDDDD  MMMMMMM  MMMMMMM #" }
		, { " # SSSS        S        IIIIII       DDDDD  DDDDDD  MMMMMMMMMMMMMMMM #" }
		, { " # SSSSS                IIIIII       DDDDD   DDDDD  MMMMMMMMMMMMMMMM #" }
		, { " #  SSSSSSSSSS          IIIIII       DDDDD   DDDDD  MMMMMMMMMMMMMMMM #" }
		, { " #   SSSSSSSSSS         IIIIII       DDDDD   DDDDD  MMMMMMMMMMMMMMMM #" }
		, { " #    SSSSSSSSSS        IIIIII       DDDDD   DDDDD  MMMMMMMMMMMMMMMM #" }
		, { " #     SSSSSSSSSS       IIIIII       DDDDD   DDDDD  MMMMMMMMMMMMMMMM #" }
		, { " #          SSSSS       IIIIII       DDDDD   DDDDD  MMMMMMMMMMMMMMMM #" }
		, { " #  S        SSSS       IIIIII       DDDDD  DDDDDD  MMMMMMMMMMMMMMMM #" }
		, { " # SSS       SSSS       IIIIII       DDDDDDDDDDDDD  MMMMMMMMMMMMMMMM #" }
		, { " #SSSSS      SSSS   IIIIIIIIIIIIII   DDDDDDDDDDDDD  MMMMMMMMMMMMMMMM #" }
		, { " # SSSSSSSSSSSSSS   IIIIIIIIIIIIII   DDDDDDDDDDDD   MMMM MMMMMM MMMM #" }
		, { " #  SSSSSSSSSSSS    IIIIIIIIIIIIII   DDDDDDDDDDD    MMMM MMMMMM MMMM #" }
		, { " #   SSSSSSSSSS     IIIIIIIIIIIIII   DDDDDDDDDD     MMMM  MMMM  MMMM #" }
		, { " #    SSSSSSSS      IIIIIIIIIIIIII   DDDDDDDDD      MMMM   MM   MMMM #" }
		, { " #####################################################################" } };
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level15[i][c];
			}
		}
}

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
		,       {" ##            ***     ***     ********     **        **            ##"}
		,       {" ##            ***     ***     ********     **        **            ##"}
		,       {" ##            ***     ***  ***        **   **        **            ##"}
        ,       {" ##            ***     ***  ***        **   **        **            ##"}
        ,       {" ##              ***  **    ***        **   **        **            ##"}
        ,       {" ##              ***  **    ***        **   **        **            ##"}
		,       {" ##                ***      ***        **   **        **            ##"}
        ,       {" ##                ***      ***        **   **        **            ##"}
        ,       {" ##                ***         ********       ********              ##"}
		,       {" ##                ***         ********       ********              ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                     Lost.                       ##"}
        ,       {" ##             press space to continue....                         ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
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
	,	{" #           stage. Your shadow has its left and                     #"}		
	,	{" #           right controls reversed!                                #"}		
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
void levelskip()
{
	if(next==101)
	{
		next=6;
	}
	else if(next==102)
	{
		next=11;
	}
	else if(next==103)
	{
		next=16;
	}
}
