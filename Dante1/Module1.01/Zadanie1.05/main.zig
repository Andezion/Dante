const print = std.debug.print;
const std = @import("std");

pub fn main() void {
        const num_integer: i32 = 5;
        const num_float: f64 = 5.5;
        const num_double: f32 = 4.5;

        print("{} {} {}\n", .{num_integer, num_float, num_double});
}



