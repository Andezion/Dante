const print = std.debug.print;
const std = @import("std");

pub fn main() void {
        const d_pi: f32 = 3.141592653589793;
        const f_pi: f64 = 3.141592653589793;

        print("f_pi is: {}\nd_pi is: {}", .{f_pi, d_pi});
}

