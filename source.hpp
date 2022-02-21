#ifndef SOURCE_HPP
#define SOURCE_HPP

#include <string>

/*inline*/ constexpr int matrixSize = 11;

//union keyboard{
//    constexpr int keyUp = 65,
//                  keyDown = 66,
//                  keyRight = 67,
//                  keyLeft = 68,
//                  keyEnter = 0x0A,
//                  keyEsq = 27;
//};

constexpr int keyUp = 65, keyDown = 66, keyRight = 67, keyLeft = 68, keyEnter = 0x0A, keyEsq = 27;

const char quit = 'q';

inline std::string_view B_GREEN = "\u001b[32;1m";
inline std::string_view CYAN = "\u001b[36m";
inline std::string_view YELLOW = "\u001b[33m";
inline std::string_view BACK_YELLOW = "\u001b[43m";
inline std::string_view B_RED = "\u001b[31;1m";
inline std::string_view BACK_RED = "\u001b[41m";
inline std::string_view RESET = "\u001b[0m";
inline std::string_view GREEN = "\u001b[32m";
inline std::string_view BACK_B_GREEN = "\u001b[42;1m";
inline std::string_view BACK_GREEN = "\u001b[42m";
inline std::string_view WHITE = "\u001b[37m";
inline std::string_view BACK_B_WHITE = "\u001b[47;1m";
inline std::string_view BACK_BLUE = "\u001b[44;1m";
inline std::string_view BLUE = "\u001b[47m";

void randomBlock(char matrix1[][matrixSize], int hard_lvl);
void matrixInit(char matrix1[][matrixSize]);
/* inline */ void print_m(char matrix1[][matrixSize]);

#endif // SOURCE_HPP
