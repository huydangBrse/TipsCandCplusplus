#include <stdio.h>

typedef struct {
    int result;
    char* errorInfo;
} E_RESULT_T;

/**
 * @name                Write File Callback Function
 * @param[in]    name    File Name
 * @param[in]    data    String to write file 
 * @param[in]    result  The result of write function
 * @return       No
 * @attention
 * - No
 */
typedef void ( *writeFileCallbackFunction )( char* fileName, char* data, E_RESULT_T result);

/**
 * @name                Read file Callback Function
 * @param[in]    name    File Name
 * @return       1: Success, 0: Fail
 * @attention
 * - No
 */
typedef int ( *readFileCallbackFunction )( char* fileName);

/**
 * @name                Write File
 * @param[in]    name    File Name
 * @param[in]    data    String to write file 
 * @param[in]    result  The result of write function
 * @return       No
 * @attention
 * - No
 */
void writeFile(char* fileName, char* data, E_RESULT_T result){
    printf("\nThis is Write function\n");
}

/**
 * @name                Read file
 * @param[in]    name    File Name
 * @return       1: Success, 0: Fail
 * @attention
 * - No
 */
int readFile(char* fileName){
    printf("\nThis is read function\n");
    return 0;
}

int main(int argc, char* argv[])
{
    E_RESULT_T result;
    /* declare callback function*/
    writeFileCallbackFunction writeFunc = writeFile;
    readFileCallbackFunction  readFunc  = readFile;

    /*Call callback function*/
    writeFunc("callback_demo.log", "This is string will be written into file", result);
    readFunc("callback_demo.log");
    return 0;
}
