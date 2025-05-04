#ifndef CROSSWORD_FUNCTIONS_H
#define CROSSWORD_FUNCTIONS_H

#define DEFINE_ARRAY(TYPE) \
struct array_##TYPE##_t\
{      \
    int size;       \
    int capacity;     \
    TYPE* data;\
};             \

#define CREATE_ARRAY(TYPE)\
struct array_##TYPE##_t *create_array_##TYPE(int size)\
{ \
    if(size < 1)\
    {     \
         return NULL;    \
    }             \
    struct array_##TYPE##_t* helper = malloc(sizeof(struct array_##TYPE##_t)); \
    if(helper == NULL)\
    {   \
         return NULL;       \
    }                \
    helper->data = malloc(sizeof(TYPE) * size);\
    if (!(helper->data == NULL)) \
    {\
        helper->size = 0;\
        helper->capacity = size;\
        return helper;\
    } \
    else \
    {\
        return free(helper), NULL;\
    }\
}\


#define FREE_ARRAY(TYPE) \
void free_array_##TYPE(struct array_##TYPE##_t *array)\
{\
    if(array != NULL)\
    {\
        free((array->data));\
        free(array);\
    }\
}

#define SAVE_ARRAY(TYPE)\
int save_array_##TYPE(const struct array_##TYPE##_t *array, const char *filename)\
{ \
    if(array == NULL || filename == NULL || array == NULL || array->size < 1 || array->data == NULL || array->capacity < 1 || array->size > array->capacity)\
    { \
        return 1;      \
    }       \
           \
    FILE *file;\
    file = fopen(filename, "wb");    \
    if(file == NULL)\
    {                    \
        return 2;     \
    }             \
    \
    fwrite(&array->size, sizeof(int), 1, file);\
    fwrite(array->data, sizeof(TYPE), array->size, file);\
                        \
    fclose(file);     \
    return 0;\
}


#define LOAD_ARRAY(TYPE) \
int load_array_##TYPE(struct array_##TYPE##_t **array, const char *filename) \
{                        \
    if(array==NULL||filename==NULL)      \
    {                    \
        return 1;                        \
    }                    \
    \
    FILE *file = fopen(filename,"rb");                                                \
    if(file == NULL)              \
    {                    \
        return 2;                        \
    }                    \
    \
    int number = 0;\
    int error = fread(&number, sizeof(int), 1, file);                                             \
    if(error != 1)                 \
    {                    \
        fclose(file);             \
        return 3;\
    }                    \
    \
    if(number <= 0)                 \
    {                    \
        fclose(file);             \
        return 3;\
    }                    \
    \
    struct array_##TYPE##_t *stack = create_array_##TYPE(number);                          \
    if(stack == NULL)             \
    {                    \
        fclose(file);              \
        return 4;\
    }                    \
    \
    stack->size = number;           \
    error = fread(stack->data, sizeof(*stack->data), number, file);                            \
    if(error != number)              \
    {                    \
        free_array_##TYPE(stack);  \
        fclose(file);               \
        return 3;\
    }    \
    *array = stack;\
    fclose(file);               \
    return 0;\
}\


#define SORT_ARRAY(TYPE) \
int sort_array_##TYPE(struct array_##TYPE##_t* array)\
{ \
    if (array == NULL || array->size < 1 || array->data == NULL || array->capacity < 1 || array->size > array->capacity) \
    { \
        return 1; \
    } \
    for (int i = 0; i < array->size - 1; i++) \
    { \
        for (int j = i + 1; j < array->size; j++) \
        { \
            if (*(array->data + i) > *(array->data + j))\
            { \
                TYPE stas_asket = *(array->data + i); \
                *(array->data + i) = *(array->data + j); \
                *(array->data + j) = stas_asket; \
            } \
        } \
    } \
    return 0; \
}

#endif //CROSSWORD_FUNCTIONS_H
