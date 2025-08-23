const print = std.debug.print;
const std = @import("std");

pub fn main() void {
    const number1: f32 = 6.1;
    const number2: i32 = 2;

    const z: i32 = @as(i32, number2) + @as(i32, @intFromFloat(number1));

    print("Result: {}\n", .{z});
}
