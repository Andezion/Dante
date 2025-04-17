#ifndef PAST6MODULE_CHAR_OPERATIONS_H
#define PAST6MODULE_CHAR_OPERATIONS_H

char* letter_modifier(const char* input_text, char (*fun)(char));
char lower_to_upper(char ch);
char upper_to_lower(char ch);
char space_to_dash(char ch);
char reverse_letter(char ch);

#endif //PAST6MODULE_CHAR_OPERATIONS_H
