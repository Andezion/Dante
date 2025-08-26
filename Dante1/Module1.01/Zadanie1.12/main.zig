const std = @import("std");

pub fn main() !void {
    const stdin = std.io.getStdIn().reader();
    const stdout = std.io.getStdOut().writer();

    try stdout.print("Enter number: ", .{});

    var buf: [100]u8 = undefined;
    const line_opt = try stdin.readUntilDelimiterOrEof(&buf, '\n');

    const line = line_opt orelse {
        try stdout.print("No input\n", .{});
        return;
    };

    const number = std.fmt.parseFloat(f32, line) catch {
        try stdout.print("Incorrect input\n", .{});
        return;
    };

    try stdout.print("{d}\n{d}\n", .{ number, number * 10 });
}
