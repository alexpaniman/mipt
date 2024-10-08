#ifndef ONEGIN_TYPES_UTF_8_H_
#define ONEGIN_TYPES_UTF_8_H_

/**************************************************************************//**
 * @file     utf8.h
 * @brief    Onegin App. Types / UTF-8 encode functions. 
 * @version  V0.0.1
 * @date     17. Sep 2024
 * @author   Matvey Rybalkin
 ******************************************************************************/

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// UTF-8 types.
typedef uint32_t utf8_char_t; // TODO: wchar_t is it you?
typedef unsigned char* utf8_string_t;

// Cast

/// @brief 4 Byte character cast // TODO: what is this for?
#define UTF8_CHAR(char) (uint32_t)(char)

/// @brief UTF-8 strings cast // TODO: useless piece of documentation
#define UTF8_CSTR(str) (utf8_string_t)(str)

/*************************************************************
 * Public
 ************************************************************/

/**
 * @brief Calculates lenght of the UTF-8 string.
 *        ^~~~~~~~~~     ^~ TODO: typo, it's length
 *        |
 *        TODO: Documentation is usually written in imperative
 * 
 * @param[in] str string for calculation.
 * @returns the number of characters in string. (TODO: return?)
 */
extern size_t utf8_len(const utf8_string_t str);
// TODO: naming, use verbs to clearly indicate what happens
//       and it's cost, like calculate_utf8_string_length

/**
 * @brief Finds character in current string
 * 
 * @param[in] str string for calculation.
 * @param[in] ch character for search.
 * @returns position of the character in the string.
 */
extern int64_t utf8_find(const utf8_string_t str, utf8_char_t ch);

/**
 * @brief Gets the next character of the string.
 * 
 * @param[in] str string pointer
 * @returns current character and creates a step to the next.
 */
extern utf8_char_t utf8_get(const utf8_string_t* str);

#endif // ONEGIN_TYPES_UTF_8_H_
