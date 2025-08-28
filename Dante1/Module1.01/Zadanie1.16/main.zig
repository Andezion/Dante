const std = @import("std");
const math = std.math;

pub fn main() !void {
    const stdin = std.io.getStdIn().reader();
    const stdout = std.io.getStdOut().writer();

    try stdout.print("Enter number1: ", .{});
    var buf1: [100]u8 = undefined;
    const line_opt1 = try stdin.readUntilDelimiterOrEof(&buf1, '\n');
    const line1 = line_opt1 orelse {
        try stdout.print("No input\n", .{});
        return;
    };
    const number1 = std.fmt.parseFloat(f32, line1) catch {
        try stdout.print("Incorrect input\n", .{});
        return;
    };

    try stdout.print("Enter number2: ", .{});
    var buf2: [100]u8 = undefined;
    const line_opt2 = try stdin.readUntilDelimiterOrEof(&buf2, '\n');
    const line2 = line_opt2 orelse {
        try stdout.print("No input\n", .{});
        return;
    };
    const number2 = std.fmt.parseFloat(f32, line2) catch {
        try stdout.print("Incorrect input\n", .{});
        return;
    };

    try stdout.print("Enter number3: ", .{});
    var buf3: [100]u8 = undefined;
    const line_opt3 = try stdin.readUntilDelimiterOrEof(&buf3, '\n');
    const line3 = line_opt3 orelse {
        try stdout.print("No input\n", .{});
        return;
    };
    const number3 = std.fmt.parseFloat(f32, line3) catch {
        try stdout.print("Incorrect input\n", .{});
        return;
    };

    const result = math.sqrt(number1 * number1 +
        number2 * number2 +
        number3 * number3);

    try stdout.print("Result: {d:.4}\n", .{result});
}
