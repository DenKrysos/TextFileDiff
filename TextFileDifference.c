/*
 * Authored by
 * DenKr (2016)
 */


#define NO_DENKREMENT_C_FUNCTIONS


//==================================================================================================//
//////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------------------------------------------------//
//--------  Preamble, Inclusions  ------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------//
//==================================================================================================//
//==================================================================================================//
// At first include this ----------------------------------------------------------
//---------------------------------------------------------------------------------
#include "./global/global_settings.h"
#include "./global/global_variables.h"
// Need this for e.g. some really fundamental Program Basics (if any)  ------------
//---------------------------------------------------------------------------------
#include "DenKrement_base.h"
// Then better start with this  ---------------------------------------------------
//---------------------------------------------------------------------------------
#include "DenKrement.h"
//==================================================================================================//
//==================================================================================================//
//==================================================================================================//
//Just to nicely keep order:  -----------------------------------------------------
//   First include the System / Third-Party Headers  ------------------------------
//   Format: Use <NAME> for them  -------------------------------------------------
//---------------------------------------------------------------------------------
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <linux/types.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <signal.h>
#include <malloc.h>

//==================================================================================================//
//==================================================================================================//
//==================================================================================================//
//Then include own Headers  -------------------------------------------------------
//   Format: Use "NAME" for them  -------------------------------------------------
//---------------------------------------------------------------------------------
#include "auxiliary/support_main.h"
//  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#include "DenKr_essentials/auxiliary.h"
#include "DenKr_essentials/DenKr_errno.h"
//==================================================================================================//
//==================================================================================================//
//////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------------------------------------------------//
//==================================================================================================//



#define FILE1 "File_1-Name.txt"
#define FILE2 "File_2-Name"

//int main(int argc, char *argv[]) {
int main(int argc, char **argv) {
//	system("reset");
//	system("clear");
	int err=0;
	int i;

		//	//Just funny, not really of any use: ;oP
		//	#include <DenKr_essentials/Terminal/ascii.h>
		//	#include <DenKr_essentials/Terminal/ansi.h>
		//	print_ANSI_Pokemon_Starter_1st_Gen_8Bit();
		//	print_ASCII_Pokemon_Bulbasaur_monochrom();
		//	print_ASCII_ANSI_Pokemon_Bulbasaur();
		//	print_ANSI_Pokemon_Bulbasaur();
		//	exit(1);

	// Set Signal Handler for the User-desired Exit Ctrl-C
	signal(SIGINT, sig_handler_ctrl_c);





    //==================================================================================================//
    //--------------------------------------------------------------------------------------------------//
    //----  As a funny startup.  -----------------------------------------------------------------------//
    //----  Really totally not of any use...  ----------------------------------------------------------//
    //--------------------------------------------------------------------------------------------------//
    //==================================================================================================//
//	{
//		CREATE_argv(printf_bulb,"print","pokemon","bulbasaur");
//		CREATE_argv(printf_starter,"print","pokemon","starter","1stGen");
//		printf("\nOK, at first, here you have Bulbausaur...\n");
//		err=Cmd_Line_Mux_funny(3,printf_bulb);
//		printf("\nAnd the other starters as well...\n");
//		err=Cmd_Line_Mux_funny(4,printf_starter);
//		printf("Fine... Now we can start:\n");
//		system("clear");
//
//	}





    //==================================================================================================//
    //--------------------------------------------------------------------------------------------------//
    //----  Initialization of the DenKr_essentials-Library  --------------------------------------------//
    //----  Enables some Paths, Checks System-Endianess, Terminal ANSI-Escape  -------------------------//
    //--------------------------------------------------------------------------------------------------//
    //==================================================================================================//
	DenKr_essentials_Init(argc, argv);
	#ifdef DENKR_ESSENTIALS_AUXILIARY_H
		printfc(yellow,"Program Name:\n");printf("%s\n",ProgramName);
		printfc(yellow,"Program Path (executable):\n");printf("%s\n",ProgPath);
		printfc(yellow,"Storage Files Path (cfg, log, etc.):\n");printf("%s\n",StorageFilesPath);
	#endif
	printf("\n");





    //==================================================================================================//
    //--------------------------------------------------------------------------------------------------//
    //----  Start of the Command-Line Multiplexing  ----------------------------------------------------//
    //--------------------------------------------------------------------------------------------------//
    //==================================================================================================//
	//For now just to intercept some stuff "not really for valuable use", but just additional funny stuff
	//Maybe later on can be extended and the other Code will be integrated; certainly not.
	#ifdef SECRET_DENKREMENT_FUNNY_H
		int argc_proc=argc-1; char **argv_proc=argv+1;
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		if(argc_proc>0){
			if(strcmp(*argv_proc, "funny") == 0){
				#include "secret/DenKrement_funny.h"
				err=Cmd_Line_Mux_funny(--argc_proc,++argv_proc);
				exit(err);
			}else{}
		}else{}
	#endif





    //==================================================================================================//
    //--------------------------------------------------------------------------------------------------//
    //----  Config-Files  ------------------------------------------------------------------------------//
    //--------------------------------------------------------------------------------------------------//
    //==================================================================================================//
    //----  Initializes the global char [][] cfg_files_v_gl,
    //----       Checks for the Presence of Config-Files,
    //----       Eventually creates Default-Config-Files, if one doesn't already exist
    //--------------------------------------------------------------------------------------------------//
	// Creates cfg_files_v, usable like argv, with 'DENKREMENT_CFG_FILES_QUANTITY' as max Value
//	#define cfg_files_v ((char **)cfg_files_v_)
//	create_cfg_files_argv
    //--------------------------------------------------------------------------------------------------//
	// Presence Checking and eventually Default-Creation
//	cfg_files_init_and_default(cfg_files_v);










//=======================================================================================================================================
//=======================================================================================================================================
//=======================================================================================================================================
//----------  Temporary Testing Section  --------------------------------------------------------------------------------------==========
//=======================================================================================================================================
//=======================================================================================================================================
#ifdef DEBUG //----------------------------------------------------------------------------------------------------------------==========
#ifndef RELEASE_VERSION //Just to get sure... ;o) that nothing got forgotten within the final Build  --------------------------==========
//=======================================================================================================================================





//=======================================================================================================================================
#endif //----------------------------------------------------------------------------------------------------------------------==========
#endif //----------------------------------------------------------------------------------------------------------------------==========
//=======================================================================================================================================
//=======================================================================================================================================
//----------  End  -  Temporary Testing Section  ------------------------------------------------------------------------------==========
//=======================================================================================================================================
//=======================================================================================================================================
//=======================================================================================================================================

	char* f1path;
	char* f2path;
	int f1plen=ProgPath_length+sizeof(FILE1);
	int f2plen=ProgPath_length+sizeof(FILE2);
	f1path=malloc(f1plen);
	f2path=malloc(f2plen);
	snprintf(f1path,f1plen,"%s%s",ProgPath,FILE1);
	snprintf(f2path,f2plen,"%s%s",ProgPath,FILE2);

	printf("Reading Files:\n%s\n%s\n",f1path,f2path);

	char c1;
	char c2;
	int bufsiz=40;
	char buf[bufsiz+1];

	unsigned long long line =1;
	unsigned long long row = 1;
	FILE* f1=NULL;
	FILE* f2=NULL;

	f1 = fopen(f1path, "r");
	if (!f1) {
		switch(errno){
			case EACCES:
				printfc(red,"ERROR:");printf(" Couldn't read File!:\n\t%s\n\t\tReason:Permission denied!\n",f1path);
				return FILE_ERR_PERMISSION_DENIED;
			break;
			case ENOENT:
				//TODO: Ask to create default one.
				//Than wait for the user to adjust it. I.e. wait for event like keyboard input
				//or this two things inside GUI.
				//Than jump up and start over reading.
				printfc(red,"TODO:");
				depr(TODO);
				exit(ERR_OVER_9000);
			break;
			default:
				printfc(red,"ERROR:");printf(" Ups, seems like we've encountered a case, which isn't caught yet :o( (config_file_read_variadic_)\n");
				printfc(red,"\tAdditional DEBUG:");printf(" errno: %d. File-Path: %s\n",errno,f1path);
				depr(TODO);
				return MAIN_ERR_FUNC_INCOMPLETE;
			break;
		}
	}
	f2 = fopen(f2path, "r");
	if (!f2) {
		switch(errno){
			case EACCES:
				printfc(red,"ERROR:");printf(" Couldn't read File!:\n\t%s\n\t\tReason:Permission denied!\n",f2path);
				return FILE_ERR_PERMISSION_DENIED;
			break;
			case ENOENT:
				//TODO: Ask to create default one.
				//Than wait for the user to adjust it. I.e. wait for event like keyboard input
				//or this two things inside GUI.
				//Than jump up and start over reading.
				printfc(red,"TODO:");
				depr(TODO);
				exit(ERR_OVER_9000);
			break;
			default:
				printfc(red,"ERROR:");printf(" Ups, seems like we've encountered a case, which isn't caught yet :o( (config_file_read_variadic_)\n");
				printfc(red,"\tAdditional DEBUG:");printf(" errno: %d. File-Path: %s\n",errno,f2path);
				depr(TODO);
				return MAIN_ERR_FUNC_INCOMPLETE;
			break;
		}
	}

	while(1){
		c1 = (char)getc(f1);
		c2 = (char)getc(f2);
		switch(c1){
		case EOF:
			printf("\nRead completely through File-1. No difference found. Files are equal! Exit.\n");
			goto Exit;
			break;
		case '\n':
			line++;
			row=0;
			break;
		default:
			row++;
			break;
		}
		switch(c2){
		case EOF:
			printf("\nRead completely through File-2. No difference found. Files are equal! Exit.\n");
			goto Exit;
			break;
//		case '\n':
//			line++;
//			break;
		default:
			break;
		}

		if(!(c1==c2)){
			printf("\n!!!\nFirst difference found in Line: %llu | Sign: %llu\n!!!\n",line, row);
			int i;
			for(i=0;i<bufsiz;i++){
				c1 = (char)getc(f1);
				switch(c1){
				case EOF:
					printf("\t --> Read completely through File-1 (while filling the Afterwards-Buffer.\n");
					goto BreakLoop;
					break;
				default:
					buf[i]=c1;
					break;
				}

			}
			BreakLoop:
			buf[i]='\0';
			printf("This follows afterwards in File-1:\n\t%s\n",buf);
			printf("If you want more, equal the Files and start again.\nNow exiting...\n\n");
			goto Exit;

		}
	}




	Exit:
	fclose(f1);
	fclose(f2);


	#undef cfg_files_v

	return err;
}




#undef NO_DENKREMENT_C_FUNCTIONS
