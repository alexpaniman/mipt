#ifndef DISASSEMBLER_H_
#define DISASSEMBLER_H_

/**************************************************************************//**
 * @file     disassembler.h
 * @brief    Functions for disassembling .bin file to assembler text.
 * @version  V0.2.0
 * @date     2. Dec 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <instructions.h>
#include <stdlib.h>

/**
 * @brief Error codes for disassembly operations.
 * 
 * Use these codes to determine the result of disassembly-related functions.
 */
typedef enum {
    /**
     * @brief Operation completed successfully.
     */
    DASM_OK,

    /**
     * @brief Destination pointer is `NULL`.
     * 
     * Indicates that the destination structure required for the operation
     * was not provided or is invalid.
     */
    DASM_ERROR_NO_DEST,

    /**
     * @brief Source data is invalid or `NULL`.
     * 
     * Indicates that the binary source data required for the operation
     * was not provided or is invalid.
     */
    DASM_ERROR_NO_SRC,

    /**
     * @brief Memory allocation failed.
     * 
     * Indicates that the required memory could not be allocated during the operation.
     * This error typically occurs when the system runs out of memory or the requested 
     * allocation size is invalid.
     */
    DASM_ERROR_ALLOC,

    /**
     * @brief Invalid opcode encountered.
     * 
     * Indicates that the provided opcode does not correspond to any valid processor instruction.
     * This error typically occurs when decoding or validating binary data that contains unknown 
     * or unsupported opcodes.
     * 
     * @note Ensure the opcode is validated using `is_opcode_valid()` before performing operations
     * that depend on it.
     */
    DASM_ERROR_OPCODE_INVALID,


} dasm_error_t;


/**
 * @brief Creates a new `bin_code_t` structure from raw binary data.
 * 
 * For encapsulating raw binary data into a `bin_code_t` structure,
 * use this function to initialize the structure with the given data and size.
 * 
 * @param src Pointer to the source buffer containing raw binary data. Must not be `NULL`.
 * @param size Size of the source buffer in bytes. Must be greater than 0.
 * @return A `bin_code_t` structure initialized with the provided data. 
 * If the input is invalid (`src == NULL` or `size == 0`), returns a structure with `.size = 0`.
 */
extern bin_code_t bin_code_duplicate(const void* src, size_t size);

/**
 * @brief Generates assembly code from binary code.
 * 
 * For transforming binary instructions into assembly representation, 
 * this function processes the source binary code and writes the result to the destination.
 * 
 * @param dest Pointer to an `asm_code_t` structure where the generated assembly code will be stored. Must not be `NULL`.
 * @param src The source binary code as a `bin_code_t` structure.
 * @param src_size The size of the source binary data in bytes. Must match the size of `src`.
 * @return A `dasm_error_t` indicating the result:
 * - `DASM_OK`: The operation was successful.
 * - `DASM_ERROR_NO_DEST`: The destination pointer is `NULL`.
 * - `DASM_ERROR_NO_SRC`: The source data is invalid.
 */
extern dasm_error_t dasm_generate(asm_code_t* dest, const bin_code_t src, const size_t src_size);

#endif // DISASSEMBLER_H_