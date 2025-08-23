const print = std.debug.print;
const std = @import("std");

pub fn main() void {
    const d_pi: f32 = 3.14159265359;
    const f_pi: f64 = 3.14159265359;

    print("f_pi is: {:.3}\nd_pi is: {:.3}", .{ f_pi, d_pi });
}
