const print = @import("std").debug.print;

pub fn main() !void {
    const array = [16]f32{ 10, 11, 4, 5, 6, 12, 16, 1, 2, 3, 13, 14, 15, 7, 8, 9 };
    for (&array) |i| {
        print("{d} ", .{i});
    }
}
