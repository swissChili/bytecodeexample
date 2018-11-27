//
// Created by cake on 11/26/18.
//

#ifndef BYTECODE_PARSER_CVMC_H
#define BYTECODE_PARSER_CVMC_H

#include <bytecode/bytecode.h>


typedef enum
{
    i_pushrv, //push reserved value
    i_pushv,  //push raw value
    i_pushr,  //push register
    i_pop,
    i_popt,
    i_call,
    i_loadi,
    i_move,
    i_ret,
    i_cmpi,
    i_debug,
    i_ss,
    i_ssr,
    i_addi,
    i_subi,
    i_rega, i_regb, i_regab
} CVM_generic_instructions;

typedef enum
{
    r_iag,
    r_ibg,
    r_icg
} CVM_int_registers;



#endif //BYTECODE_PARSER_CVMC_H
