const std = @import("std");
const print = std.debug.print;

pub fn main() !void {
    var array: [16]f32 = undefined;
    for (array, 0..) |*elem, i| {
        elem.* = @floatFromInt(i);
        print("{d} ", .{i});
    }
}
