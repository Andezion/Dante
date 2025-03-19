#ifndef WINAPI_COLOR_H
#define WINAPI_COLOR_H

enum colors
{
    RED = 1,
    GREEN,
    BLUE,
    YELLOW,
    UNKNOWN
};

struct color_t
{
    float r;
    float g;
    float b;
    enum colors c;
};

int load_colors_t(const char *filename, struct color_t* p, int N);
float distance(const struct color_t* p1, const struct color_t* p2, int *err_code);
enum colors find_nearest_neighbour(const struct color_t* database, int size, const struct color_t* unknown, int *err_code);

#endif //WINAPI_COLOR_H
