const print = std.debug.print;
const std = @import("std");

pub fn main() void {
    const number_1: f32 = 5.5;
    const number_2: f32 = 7.6;

    print("Num1: {} and Num2: {}\n", .{ number_1, number_2 });

    print("{}\n", .{number_1 * number_2});
    print("{}\n", .{number_1 / number_2});
    print("{}\n", .{number_1 + number_2});
    print("{}\n", .{number_1 - number_2});
}
