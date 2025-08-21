const std = @import("std");

pub fn main() !void {
    const stdin = std.io.getStdIn().reader();
    const stdout = std.io.getStdOut().writer();

    var buf: [100]u8 = undefined;

    try stdout.print("Enter numbers: ", .{});
    const line = try stdin.readUntilDelimiterOrEof(&buf, '\n');

    if (line == null) {
        try stdout.print("Incorrect input\n", .{});
        return;
    }

    var tokenizer = std.mem.tokenizeScalar(u8, line.?, ' ');

    const num1_str = tokenizer.next() orelse {
        try stdout.print("Incorrect input\n", .{});
        return;
    };
    const num2_str = tokenizer.next() orelse {
        try stdout.print("Incorrect input\n", .{});
        return;
    };

    const num1 = std.fmt.parseInt(i32, num1_str, 10) catch {
        try stdout.print("Incorrect input\n", .{});
        return;
    };

    const num2 = std.fmt.parseInt(i32, num2_str, 10) catch {
        try stdout.print("Incorrect input\n", .{});
        return;
    };

    try stdout.print("{}\n", .{num1 + num2});
}
