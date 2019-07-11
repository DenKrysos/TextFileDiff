#ifndef TDiff_H
#define TDiff_H

/*
 * Authored by
 * Dennis Krummacker (03.06.14-)
 */






#define CFG_FILE_PATH_FILE_NAME "TDiff.cfg"
//This becomes preceded onto the StorageFilesPath string variable
#define CFG_FILE_PATH_PREFIX "config/"
//So the complete File-Path is concatenated as
//		StorageFilesPath + CFG_FILE_PATH_PREFIX + CFG_FILE_PATH_FILE_NAME
//				StorageFilesPath has a preceding '/'
//				One should specify the CFG_FILE_PATH_PREFIX including a preceding '/'





void ctrl_c();







#endif /*  */
