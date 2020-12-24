#ifndef TEXT_H
#define TEXT_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/** convert number of bytes to human readable string
 *  returns number of characters written
 *  notes: dest MUST be at least size characters large
 */
int sprint_humanread_bytes(char *dest, unsigned int size, uint64_t bytes);

/* returns the length of the UTF-8 character pointed to by `data`
 * returns 0 on invalid UTF-8 character
 */
uint8_t utf8_len(const char *data);

/* reads a UTF-8 character from `data` into `ch`
 * returns the length of the UTF-8 character pointed to by `data`
 * returns 0 on invalid UTF-8 character
 */
uint8_t utf8_len_read(const char *data, uint32_t *ch);

/* backwards length */
uint8_t utf8_unlen(char *data);

/* returns the length in bytes of a string of valid UTF-8 characters
 * The returned length is limited by `maxlen`,
 * or by the first invalid UTF-8 character,
 * or by '\0', whichever comes first.
 */
size_t utf8_strnlen(const uint8_t *data, size_t maxlen);

uint8_t unicode_to_utf8_len(uint32_t ch);
void unicode_to_utf8(uint32_t ch, char *dst);

/* compare first n bytes of s1 and s2, ignoring the case of alpha chars
 *  match: returns 0
 *  no match: returns 1
 *  notes: n must be <= length of s1 and <= length of s2
 */
bool memcmp_case(const char *s1, const char *s2, uint32_t n);

/* replace html entities (<,>,&) with html
 */
char *tohtml(const char *str, uint16_t len);

void to_hex(char *out, uint8_t *in, int size);

/* returns non-zero if substring is found */
bool strstr_case(const char *a, const char *b);

/**
 * @brief Shrink UTF-8 string down to provided length
 * without splitting last UTF-8 multi-bytes character.
 *
 * @param string UTF-8 string to shrink.
 * @param string_length Length of UTF-8 string.
 * @param shrink_length Desirable length of shrunk string.
 * @return shrunk length.
 */
uint16_t safe_shrink(const char *string, uint16_t string_length, uint16_t shrink_length);

#endif
